#include <stdio.h>
#include "pico/stdlib.h"
#include "esp8266.h"


int main()
{
    stdio_init_all();

    puts("Hello, world!");

    esp8266 my_esp;
    
    return 0;
}
