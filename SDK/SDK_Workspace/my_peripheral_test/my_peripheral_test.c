#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xio.h"
int main () {
unsigned int DataRead;
unsigned int OldData;
init_platform();
// Clear the screen
	xil_printf("%c[2J",27);
	OldData = (unsigned int) 0xffffffff;
	while(1){
	// Read the state of the DIP switches
	DataRead = XIo_In32(XPAR_MY_PERIPHERAL_0_BASEADDR);
	// Send the data to the UART if the settings change
	if(DataRead != OldData){
	xil_printf("DIP Switch settings: 0x%2X\r\n", DataRead);
	// Set the LED outputs to the DIP switch values
	XIo_Out32(XPAR_MY_PERIPHERAL_0_BASEADDR, DataRead);
	// Record the DIP switch settings
	OldData = DataRead;
		}
	}
}