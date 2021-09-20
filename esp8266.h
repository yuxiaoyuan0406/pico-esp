#pragma once
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/irq.h"

class esp8266
{
private:
    /* data */
public:
    /*! \brief Create a esp8266 object on a specified uart port. 
    * 
    * \param uart hardware uart
    * \param tx_pin GPIO pin using as txd for uart
    * \param rx_pin GPIO pin using as rxd for uart
    * \param baudrate you know what this is
    */
    esp8266(uart_inst_t *uart = uart1, 
            uint tx_pin = 8, 
            uint rx_pin = 9, 
            uint baudrate = 115200);
    ~esp8266();
};
