#include "main.h"

static void init_clock(void)
{
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

static void gpio_init(void)
{
    gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL,GPIO11);
}

int main (void)
{   
    int i;
    init_clock();
    gpio_init();
    init_uart();

    while (true) {

        uart_putln("led on");
        gpio_set(GPIOA, GPIO11);
            for (i = 0; i < 1500000; i++)   /* Wait a bit. */
            __asm__("nop");
        uart_putln("LED off");
        gpio_clear(GPIOA, GPIO11);
            for (i = 0; i < 1500000; i++)   /* Wait a bit. */
            __asm__("nop");
    }
    return 0;
}
