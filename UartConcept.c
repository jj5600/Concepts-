#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
typedef volatile uint32_t reg32_t;
// the purpose of type def is to create an alias for a long descriptor. for example
// instead of typing volatile uint32_t each tiem you can just use reg32_t and its like a nickname

// I also typedef'd this struct to be called UART_t. so that way I dont have to keep calling struct.. just UART_t
typedef struct{
    reg32_t CR1;
    reg32_t CR2;
    reg32_t CR3;
    reg32_t BRR;
    uint32_t RESERVED[1];
    reg32_t ISR; // interrupt and status
    uint32_t RESERVED2[1];
    reg32_t ICR; // interrupt clear
    uint32_t RESERVED3[5];
    reg32_t TDR;
    reg32_t RDR;
    
} UART_t;


#define USART1_BASE ((uint32_t)0x40011000)
#define USART2_BASE ((uint32_t)0x40004400)


#define UART_CR1_UE_BIT (1UL << 13)
#define UART_CR1_TE_BIT (1UL << 3)
#define UART_CR1_RE_BIT (1UL << 2)
#define UART_ISR_TXE_BIT (1UL << 7)
#define UART_ISR_TC_BIt (1UL << 6)

// function like macros
#define REG_S(temp,n) ((temp)|=(1U<<(n)))
#define REG_C(temp,n) ((temp)&=~(1U<<(n)))



uint8_t process_reg(uint8_t reg)
{
    uint8_t r = 0;
    for(int x =0; x<8; x++)
    {
        r = (r << 1) | (reg & 1);
        printf("%d\n", r);
        reg >>=1;
    }
    
    return r;
}
static uint32_t calculate_brr(uint32_t apb_clk, uint32_t baud)
{
    return apb_clk / (16UL * baud);
}
// to access elements within a struct using the struct pointer we can utilize the arrow

// this function accepts a pointer to uart struct , the desired baud rate and apb_clk
void uart_init(UART_t * uart , uint32_t baud, uint32_t apb_clk)
{
    // this is celaring the CR1_Ue bit
    uart->CR1 &= ~UART_CR1_UE_BIT;
    // calculate then set the brr
    uart->BRR = calculate_brr(apb_clk,baud);
    //set the icr to maximum. Clear the interrupt registers
    
    uart->ICR = 0xFFFFFFFF;
    
    // set the te and re bit
    uart->CR1 |=UART_CR1_TE_BIT |UART_CR1_RE_BIT;

    
    // set the ue bit finally
    uart->CR1 |= UART_CR1_UE_BIT;
    
    
    //printf("UART init: BRR=0x%08lX (target baud)\n",uart->BRR, baud);
    //printf("Actual baud: %d\n",apb_clk/(16UL * uart->BRR));
}

void toggle_bits(volatile uint8_t *reg, uint8_t start, uint8_t end)
{
    
    uint8_t MASK = 0xFF;
    
    MASK = MASK >> (7 - (end - start));
    MASK <<= start;
    *reg ^= MASK;

    
    
}
uint8_t swap_nibbles(uint8_t reg)
{
    return (reg & 0xF0) >> 4 | (reg & 0xF)<<4;
}

bool is_power_of_2(uint8_t n)
{
    return (n!=0) && (n & (n-1));
}
uint8_t count_set_bits(volatile uint8_t reg)
{
    uint8_t count = 0;
    uint8_t temp = reg;
    while(temp!=0)
    {
        if((temp & 0x1 )== 0x1 )
        {
            count++;
        }
        temp>>=1;
    }
    return count;
}

int uart_write_byte(UART_t *uart, uint8_t byte)
{
    while(!(uart->ISR & UART_ISR_TXE_BIT))
    {
        
    }
    uart->TDR = byte;
    return 0;
}

int uart_write(UART_t *uart, const char * data)
{
    while(*data){
        if(uart_write_byte(uart, *data) !=0){
            return -1;
        }
        data++;
    }
    return 0;
}
static UART_t fake_uart = {0};
int main(void)
{
    printf("Testing the uart!\n");
    fake_uart.ISR = UART_ISR_TXE_BIT;
    uart_init(&fake_uart, 115200,84000000);
    
    printf("Sending Hello UART!\n");
    uart_write(&fake_uart,"Hello UART!");
    
    printf("BRR reg: 0x%08lx\n",fake_uart.BRR);
    printf("EXPECTED for 115200: 0x457\n");
    
    typedef volatile uint8_t u8_t;
    u8_t TEMP = 0x0;
    
    TEMP |= (1U<<7);
    
    TEMP &= ~(1U<<7);
    
    REG_S(TEMP,0);
    REG_C(TEMP,0);
    printf("Hello World!\n");
    
    printf("..%d/.", is_power_of_2(4));
    
    process_reg(3);
    return 0;
}


