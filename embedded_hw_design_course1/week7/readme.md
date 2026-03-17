equired Reading
 These are the required reading texts for this module. You can expect this content to appear in assignments or exams.

https://resources.pcb.cadence.com/jbj-pcb-design-from-start-to-finishLinks to an external site.

Read chapters 4, 5 and 7 from the Hitchhikers guide to PCB design.Download Hitchhikers guide to PCB design.
Download STM32 Discovery board schematicLinks to an external site. and gerber files and view in KiCad
You will need to convert the STM32 schematics from Altium format to KiCad format.
View the following videoLinks to an external site. on how to convert Altium files to KiCad format

Overview
1. The quiz is covering your understanding of your knowledge of IoT Embedded Systems and IoT in Automotives

Student Learning Outcomes
Do you have questions about this assignment?
Post your questions in the Ask the Instructor Forum, located towards the top of the Modules area of this course.

Instructions
(10 points)
Quiz #6

(10 points)
Based on the Week 6  Interrupt-Driven Thermostat, use the Flash to save the user temperature setting.
On every boot, read the temperature value from flash, if this is the first time reading from flash, then
set the initial value in the flash. Since writing to the flash very frequently is not desirable, I would like you
to only write to flash if the user defined value has changed from the value stored in the flash, and check this every 5 seconds.
Note that in order to write to flash, you need to erase the whole page before you can write to it.

I would suggest to get the basic code to read and write to flash a fixed value to work first by using the code example I am sharing, later
add the logic, which would be same as used in week 6 assignment, except in this assignment you are saving the user-defined value in flash.

If you are not able to get the whole code to work, that is fine. I am looking for your design and logic understanding for this 
assignment.
 
For this assignment, you will be using: Peripherals: Flash(Storage), Temperature sensor (I2C), User button (EXTI interrupt), UART (printf), LED (status output)
I am sharing the steps and code example that should help you with the assignment.

Stores one temperature value (e.g., tempF_x10 = 723 for 72.3°F)

Uses a magic tag so you can detect “valid vs empty Flash”

Uses the last Flash page as a dedicated storage slot

 

1) Pick a Flash location (last 2KB page)
STM32L475VGT6 has 1MB Flash, and STM32L4 uses 2KB pages.

So we’ll use the last page base address:
#define FLASH_BASE_ADDR     0x08000000UL
#define FLASH_SIZE_BYTES    (1024UL * 1024UL)   // 1MB
#define FLASH_PAGE_BYTES    (2UL * 1024UL)      // 2KB
#define FLASH_CFG_ADDR      (FLASH_BASE_ADDR + FLASH_SIZE_BYTES - FLASH_PAGE_BYTES)  // 0x080FF800
0x080FF800 is the last 2KB page start for a 1MB part.

2) Code example to use in main.c

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_flash.h"
#include "stm32l4xx_hal_flash_ex.h"
#include <stdbool.h>
#include <stdint.h>

#define FLASH_BASE_ADDR     0x08000000UL
#define FLASH_SIZE_BYTES    (1024UL * 1024UL)   // 1MB
#define FLASH_PAGE_BYTES    (2UL * 1024UL)      // 2KB
#define FLASH_CFG_ADDR      (FLASH_BASE_ADDR + FLASH_SIZE_BYTES - FLASH_PAGE_BYTES) // 0x080FF800

#define TEMP_MAGIC          0x54454D50UL         // 'T''E''M''P'

static uint32_t Flash_GetPage(uint32_t addr)
{
  return (addr - FLASH_BASE_ADDR) / FLASH_PAGE_BYTES;
}

/**
 * Save a single temperature value to Flash.
 * tempF_x10 example: 723 => 72.3°F
 */
bool Flash_SaveTempF_x10(int16_t tempF_x10)
{
  // Pack 64-bit value: upper 32 = magic, lower 32 = signed temp
  uint64_t data = ((uint64_t)TEMP_MAGIC << 32) | (uint32_t)(int32_t)tempF_x10;

  FLASH_EraseInitTypeDef erase = {0};
  uint32_t page_error = 0;

  erase.TypeErase = FLASH_TYPEERASE_PAGES;
  erase.Page      = Flash_GetPage(FLASH_CFG_ADDR);
  erase.NbPages   = 1;

  HAL_FLASH_Unlock();

  // 1) erase page
  if (HAL_FLASHEx_Erase(&erase, &page_error) != HAL_OK)
  {
    HAL_FLASH_Lock();
    return false;
  }

  // 2) program one doubleword (8 bytes)
  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, FLASH_CFG_ADDR, data) != HAL_OK)
  {
    HAL_FLASH_Lock();
    return false;
  }

  HAL_FLASH_Lock();
  return true;
}

/**
 * Load temperature value from Flash.
 * Returns true if valid saved data exists.
 */
bool Flash_LoadTempF_x10(int16_t *out_tempF_x10)
{
  // Read 64-bit stored value
  uint64_t raw = *(const uint64_t *)FLASH_CFG_ADDR;
  uint32_t magic = (uint32_t)(raw >> 32);
  int32_t  temp  = (int32_t)(uint32_t)(raw & 0xFFFFFFFFUL);

  if (magic != TEMP_MAGIC)
    return false;

  // Our stored range fits in int16; clamp defensively if you want.
  *out_tempF_x10 = (int16_t)temp;
  return true;
}

3) How to use it in your project
On boot:
int16_t savedTemp;
if (Flash_LoadTempF_x10(&savedTemp))
{
  printf("Loaded saved temp: %d.%d F\r\n", savedTemp/10, abs(savedTemp%10));
}
else
{
  printf("No saved temp in Flash.\r\n");
}
When you want to save to flash:

// example temp value to save to flash
int16_t tempF_x10 = 723;

if (Flash_SaveTempF_x10(tempF_x10))
  printf("Saved temp: %d.%d F\r\n", tempF_x10/10, abs(tempF_x10%10));
else
  printf("Flash save failed!\r\n");
