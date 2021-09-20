#include "esp8266.h"

esp8266::esp8266(uart_inst_t *uart, uint tx_pin, uint rx_pin, uint baudrate)
{
    uart_init(uart, baudrate);

    gpio_set_function(tx_pin, GPIO_FUNC_UART);
    gpio_set_function(rx_pin, GPIO_FUNC_UART);

}

esp8266::~esp8266()
{
}
