#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//task is to utilize spi to read temp data from temp sensor
typedef volatile uint32_t v_uint;
typedef struct{
    v_uint CR1; // control reg 1
    v_uint CR2; // control reg 2'
    v_uint SR; // status reg
    v_uint DR; // data reg
}SPI_t;

#define SPI_SR_TXE (1U << 1) // transmit buffer empty
#define SPI_SR_RXNE (1U << 0) // receive buffer not empty
#define SPI_SR_RXE (1U << 1) // receive buffer empty
#define SPI_SR_OVR (1U << 6) // buffer over run
#define SPI_SR_MODF (1U << 5) // mode fault
#define SPI_SR_CRCERR (1U << 4) //CRC error
#define SPI_SR_UDR (1U << 3) //UNDERRUN
#define SPI_SR_BSY (1U << 7) // BUSY
#define SPI ((SPI_t *)0x40013000)
#define CS_PIN 32
#define READ_TEMP 0x1

#define TIMEOUT 10000

#define SPI_ERROR -1
#define SPI_NORMAL 0
int SPI_STATUS = SPI_NORMAL;
void gpio_write(uint8_t pin, uint8_t value)
{
    // dummy function
}
//Implement a function to send one byte and receive one byte:
/*
This function should:
1.Wait until TXE is set.
2.Write data to SPI1->DR.
Wait until RXNE is set.
Return the received byte.
 */
int spi_check_errors(void){
    if (SPI->SR & (SPI_SR_OVR | SPI_SR_MODF | SPI_SR_CRCERR)) {
        if((SPI->SR) & (SPI_SR_OVR))
        {
            volatile uint32_t tmp;
            tmp = SPI->DR;
            tmp = SPI->SR;
            
            printf("SPI Overrun Error!\n");
            SPI_STATUS = SPI_ERROR;
            return 0xFF;
        }
        if((SPI->SR) & (SPI_SR_MODF))
        {
            volatile uint32_t temp1 = SPI->SR;
            SPI->CR1 |= (1U << 6); // re-enable SPI (SPE bit)
            printf("SPI Mode Fault!\n");
            SPI_STATUS = SPI_ERROR;
            return 0xFF;
        }
        if((SPI->SR) & (SPI_SR_CRCERR))
        {
            SPI->SR &= ~SPI_SR_CRCERR;
            printf("SPI CRC Error!\n");
            SPI_STATUS = SPI_ERROR;
            return 0xFF;
        }
    }
    return 0;
}
uint8_t spi_transfer(uint8_t data)
{
    uint32_t timeout = 0;
    // polling till TXE is not 0
    while(((SPI->SR) & SPI_SR_TXE) == 0)
    {
        
        if(++timeout > TIMEOUT)
        {
            printf("TXE TIMEOUT!");
            SPI_STATUS=SPI_ERROR;
            return 0xFF;
        }// eventually time out mechanism can be added
    }
    spi_check_errors();
    timeout = 0;
    // write value to reg and cast to 32 bit unsigned
    SPI->DR = (uint32_t)data;
    while(((SPI->SR) & SPI_SR_RXNE) == 0)
    {
        
        if(++timeout > TIMEOUT)
        {
            printf("RXE TIMEOUT!");
            SPI_STATUS=SPI_ERROR;
            return 0xFF;
        }// eventually time out mechanism can be added// eventually a time out mechanism can be added
    }
    spi_check_errors();
    timeout = 0;
    return (uint8_t)SPI->DR;
}

float read_temperature(void)
{
    gpio_write(CS_PIN, 0);
    spi_transfer(READ_TEMP);
    uint8_t temp1 = spi_transfer(0x00);
    uint8_t temp2 = spi_transfer(0x00);
    
    uint16_t final = (uint16_t)((temp1) << 8 | (temp2));
    float temp = ((float)final) / 100.0;
    gpio_write(CS_PIN, 1);
    return temp;
}
void spi_init(void)
{
    // dummy function
}
int main(void)
{
    spi_init();
    for(;;)
        printf("Temp is :%f C\n",read_temperature()); 
}
