#include "stm32f10x.h"

int main(void)
{
  while (1)
  {
  }
}

void SystemInit(void)
{
  /* Reset RCC register */
  RCC->CR      &= 0x0000FF83;
  RCC->CFGR     = 0x00000000;
  RCC->CIR      = 0x00000000;
  RCC->APB2RSTR = 0x00000000;
  RCC->APB1RSTR = 0x00000000;
  RCC->AHBENR   = 0x00000000;
  RCC->APB2ENR  = 0x00000000;
  RCC->APB1ENR  = 0x00000000;
  /* Configure system clock */
  RCC->CR |= 0x00000001;                         // enable HSI clock
  while((RCC->CR & 0x00000002) == 0x00000000);   // wait for HSI clock ready
  RCC->CR   |= 0x00010000;                       // enable HSE clock
  while((RCC->CR & 0x00020000) == 0x00000000);   // wait for HSE clock ready
  RCC->CFGR |= 0x00 << 4;                        // set AHB clock prescaler
  RCC->CFGR |= 0x04 << 8;                        // set APB1 clock prescaler
  RCC->CFGR |= 0x00 << 11;                       // set APB2 clock prescaler
  RCC->CFGR |= 0x02 << 14;                       // set ADC clock prescaler
  FLASH->ACR |= 0x00000010;                      // enable flash prefetch
  FLASH->ACR &= 0xFFFFFFF8;                      // clean latency of flash access
  FLASH->ACR |= 0x00000002;                      // configure two wait states
  SCB->VTOR = FLASH_BASE;                        // set vector table base offset field
  RCC->CFGR |= 0x00010000;                       // HSE oscillator clock selected as PLL input clock
  RCC->CFGR |= 0x00000000;                       // HSE divider for PLL entry: HSE clock no divided
  RCC->CFGR |= (0x09 - 0x02) << 18;              // configure PLL multiplication factor
  RCC->CR   |= 0x01000000;                       // enable PLL clock
  while((RCC->CR & 0x02000000) == 0x00000000);   // wait for PLL clock ready
  RCC->CFGR |= 0x00000002;                       // PLL selected as system clock
  while((RCC->CFGR & 0x0000000C) != 0x00000008); // wait for PLL used as system clock
}
