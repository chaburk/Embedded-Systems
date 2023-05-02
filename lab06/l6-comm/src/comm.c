#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "eecs388_lib.h"

int main()
{
    // initialize UART channels
    ser_setup(0); // uart0 (debug)
    ser_setup(1); // uart1 (raspberry pi)
    char input_msg[100];

    printf("Setup completed.\n");
    printf("Begin the main loop.\n");

    int prev_dist = 0;
    int prev_angle = 0; 
    while (1) {
        // YOUR CODE HERE
        if(ser_isready(1) & 0x2)
        {
            ser_readline(1,100,input_msg);
            ser_printline(0,input_msg);
        }
    }
}
