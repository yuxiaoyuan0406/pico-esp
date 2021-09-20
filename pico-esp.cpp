#include <stdio.h>
#include "pico/stdlib.h"
#include "esp8266.h"

void on_uart_rx()
{
    if (uart_is_readable(uart0))
    {
        uint8_t ch = uart_getc(uart0);
        if(uart_is_writable(uart0))
        {
            // ch++;
            asm volatile("nop");
            uart_putc(uart0, ch);
        }
    }
}

int main()
{
    // stdio_init_all();

    // puts("Hello, world!");
    uart_init(uart0, 115200);

    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    uart_set_format(uart0, 8, 1, UART_PARITY_NONE);

    irq_set_exclusive_handler(UART0_IRQ, on_uart_rx);
    irq_set_enabled(UART0_IRQ, true);

    uart_set_irq_enables(uart0, true, false);

    uart_puts(uart0, "\n\rbegin.\n\r");

    while (1)
        tight_loop_contents();
}
