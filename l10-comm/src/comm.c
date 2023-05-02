#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "eecs388_lib.h"

int main()
{
    // initialize UART channels
    ser_setup(0); // uart0 (debug)
    ser_setup(1); // uart1 (raspberry pi)

    printf("Setup completed.\n");
    printf("Begin the main loop.\n");

    int prev_dist = 0;
    int prev_angle = 0;
    char strArr[50];
    char data;

    while (1) {
        if(ser_isready(1)){
            data = ser_readline(1, 50 ,strArr);
            ser_printline(0, strArr);
        }
    }
}
