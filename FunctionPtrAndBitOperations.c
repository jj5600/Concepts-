//
//  main.c


#include <stdio.h>
int add(int a , int b)
{
    return a + b;
}

int Ptradd(int *a, int * b )
{
    return *a + *b;
}
int main(void)
{
    int * numPtr, *numPtr1;
    int random1 = 5;
    int random2 = 5;
    // goal is to clear the 1st bit and set the second bit
    uint8_t ball = 0x3;
    // 4 - 2 - 1
    //ball &= ~(1 << 1);
    //ball |= (1 << 2);
    ball = (ball & ~(1<<1)) | (1<<2);
    printf("%x\n",ball);
    numPtr = &random1;
    numPtr1 = &random2;
    
    
    int (*funcptr)(int,int);
    funcptr = add;
    int result = funcptr(1,2);
    printf("the result is : %d\n", result);
    int (*funcptr1)(int *, int *);
    funcptr1 = Ptradd;
    result = 0;
    result = funcptr1(numPtr,numPtr1);
    printf("the result of pTradd is %d\n",result);
    
    
    
    uint16_t jm_register = 0xFFFF;
    printf("Before: 0x%x\n",jm_register);
    
    jm_register &= ~(0xF);
    
    printf("After: 0x%x\n",jm_register);
    
    jm_register |= (1);
    printf("After: 0x%x\n",jm_register);
    
    uint32_t jm_32bit_reg = 0xAABBCCDD;
    printf("32 bit reg: 0x%x\n", jm_32bit_reg);
    
    return 0;
    
}
