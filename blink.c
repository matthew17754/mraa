/*
* Author: Matthew Moradi <matthewx.moradi@intel.com>
* Copyright (c) 2019, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* Example usage: Blinks the LED PIN on/off every second. Press Ctrl+C to exit
*/

#include <stdio.h>
#include <mraa.h>

/* sets the LED builtin pin (13 in most cases) */
#define LED_PIN 13

main(void)
{
	/* opaque pointer definition to the internal struct _gpio */
    mraa_gpio_context led;
    
	/* detects running platform and attempts to use included pinmap */
	mraa_init();
    
	/* initializes gpio_context, sets the led pin */
    led = mraa_gpio_init(LED_PIN);

	/* checks if the LED pin was initialized successfully */
	if (led == NULL) 
	{
		fprintf(stderr, "Failed to initialize LED PIN\n");
		mraa_deinit();
		return EXIT_FAILURE;
	}
	else 
	{
		fprintf(stderr, "LED PIN Initialized\n");
	}

     /* sets gpio direction for led*/
    mraa_gpio_dir(led, MRAA_GPIO_OUT);
    
    while(1)
    {
		/* writes desired value to led pin */
        mraa_gpio_write(led, 1);
		fprintf(stderr, "LED ON\n");
        sleep(1);
        mraa_gpio_write(led, 0);
		fprintf(stderr, "LED OFF\n");
        sleep(1);
    }

	/* deinitialize mraa for the platform (not needed most of the time) */
	mraa_deinit();

	return EXIT_SUCCESS;
}
