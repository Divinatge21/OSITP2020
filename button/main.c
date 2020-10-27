#include "board.h"
#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"

#ifdef CLOCK_CORECLOCK
#define DELAY_SHORT         (CLOCK_CORECLOCK / 10)
#else
#define DELAY_SHORT         (500000UL)
#endif
#define DELAY_LONG          (DELAY_SHORT * 4)

void dumb_delay(uint32_t delay)
{
    for (uint32_t i = 0; i < delay; i++) {
        __asm__("nop");
    }
}
void btn_handler(void *arg)
{
  
  (void)arg;
 
  gpio_toggle(GPIO_PIN(PORT_C, 9));
  }

int main(void)
{
 
  gpio_init_int(GPIO_PIN(PORT_A, 0), GPIO_IN, GPIO_RISING, btn_handler, NULL);

	gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT);
       

  while(1){

}

    return 0;
}

