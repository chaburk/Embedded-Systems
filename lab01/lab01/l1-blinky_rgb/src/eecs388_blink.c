#include <stdint.h>

#include "eecs388_lib.h"

/*
   Task 2.1: Review eecs388_lib.h and eecs388_lib.c 

   Task 2.2: Implement RGB blinky. 

   - set red, green, and blue LEDs for output mode, using the gpio_mode() function
   - in the main loop, turn on/off a different LED at each iteration. 
      for example, 
      at 1st iteration
         turn on RED led
	      delay 500 ms 
	      turn off RED led
	      delay 300 ms.
	   at 2nd iteration
	      do the same but for GREEN led
	   at 3rd iteration
	      do the same but for BLUE led
	   at 4th iteration
	      back to RED led. 
	   ...
   - You must use array and modulo (%) operator to change the color. 

   Task 2.3. Implement RGBA (bonus: +1 point)
   - rotate red, green, blue, and white (all LEDs are enabled) colors.
*/

int main()
{
   int colors[] = {RED_LED, BLUE_LED, GREEN_LED};
   int gpio = RED_LED;
   int i = 0;
   gpio_mode(RED_LED, OUTPUT);
   gpio_mode(GREEN_LED, OUTPUT);
   gpio_mode(BLUE_LED, OUTPUT);
    
   while(1)
   {
      
      gpio = colors[i % 3];
      gpio_write(gpio, ON);
      delay(500);
      gpio_write(gpio, OFF);
      delay(300);
      if (i > 2) {
         i = 0;
      }
      
      if (i == 2) {
         gpio_write(colors[0], ON);
         gpio_write(colors[1], ON);
         gpio_write(colors[2], ON);
         delay(500);
         gpio_write(colors[0], OFF);
         gpio_write(colors[1], OFF);
         gpio_write(colors[2], OFF);
         delay(300);
      }
      i++;
   }
   
}
