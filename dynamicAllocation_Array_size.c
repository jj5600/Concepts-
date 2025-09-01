//
//  main.c
//  C_ONLY
//
//

#include <stdio.h>
#include <stdlib.h>
uint16_t * Create1D(size_t rows);
int main(void)
{
    // dynamially allocate a block of 3 x uint16_t
    uint16_t * ptr = (uint16_t *)malloc(sizeof(uint16_t) * 3);
    ptr[0] = 0xFFFF;
    ptr[1] = 0xAAAA;
    ptr[2] = 0xBBBB;
    // these can be accessed like a pointer
    uint16_t *nptr = (uint16_t *)realloc(ptr,sizeof(uint16_t)*6);
    nptr[3]= 0x6666;
    nptr[4]= 0x5555;
    nptr[5]= 0x4444;
   // nptr[6]= 0x3333;
    
    //printf("This is ptr[6] which should be seg fault %d",nptr[6]);
    free(nptr);
    
    uint16_t *zptr = Create1D(2);
    if(zptr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    zptr[0]=0x1111;
    zptr[1]=0x2222;
    free(zptr);
    
    
    
    printf("This is a new section where I review double pointers\n");
    int ball = 4;
    int * bptr = &ball;
    int **bbptr = &bptr;
    printf("address of ball is %x and the value is: %x\n",&ball,ball);
    printf("address of bptr is %x and the value is: %x\n", &bptr, bptr);
    printf("address of bbptr is %x and the value is %x\n",&bbptr, bbptr);
    printf("now I will deref each to reach the original value:\n");
    printf("ball : %d\n",ball);
    printf("*bptr: %d\n",*bptr);
    printf("**bptr: %d\n", **bbptr);
    printf("What happens if I do *bbptr : %x\n",*bbptr);
    
    
    return 0;
}

uint16_t * Create1D(size_t rows)
{
    return (uint16_t *)malloc(sizeof(uint16_t)*rows);
}
