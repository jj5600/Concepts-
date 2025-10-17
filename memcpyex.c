

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// navigate to the smallest measurable size which is one bytes .
//size of returns the size of the amount of data to be copied.
void myMemCpy(void *dst, const void *src, size_t n)
{
    uint8_t *destination= (uint8_t *)dst;
    const uint8_t *source = (const uint8_t *)src;
    
    for(int temp = 0; temp < n; temp++)
    {
        destination[temp] = source[temp];
    }
    // no return type;
}
int main(void)
{
    volatile uint32_t temp = 0xDEADBEEF;
    uint32_t random = 0xBBBBCCCC;
    temp = 0xFFFFAAAA;
    random = 0xDDDDEEEE;
    printf("Volatile Reg: 0x%08X\n",temp);
    printf("Volatile Reg: 0x%08X\n",random);

    printf("Hello World!\n");
    char str[] = "Hello";
    printf("The size of string str is %lu\n",sizeof(str));
    printf("The length of the string str is %lu\n",strlen(str));
    uint8_t arr[3] = {1, 2, 3};
    printf("this is the size of the array arr %lu\n",sizeof(arr));
    // int is 4 bytes and there are 3 of them.
    char * cptr = (char *)malloc(sizeof(str));
    uint8_t * ptr = (uint8_t *)malloc(sizeof(arr));
    uint8_t * ptr2 = (uint8_t *)malloc(sizeof(arr));

    if(cptr == NULL)
    {
        printf("C ptr malloc fail\n");
        exit(EXIT_FAILURE);
        
    }
    
    if(ptr2 == NULL)
    {
        printf("Ptr 2 malloc failure\n");
        exit(EXIT_FAILURE);
    }
    if(ptr == NULL)
    {
        printf("Ptr malloc failure\n");
        exit(EXIT_FAILURE);
    }
   if(memcpy(ptr, arr, sizeof(arr)) == NULL)
   {
       printf("memcpy failed!");
       exit(EXIT_FAILURE);
   }
    myMemCpy(ptr2, arr, sizeof(arr));
    myMemCpy(cptr, str, sizeof(str));
    // you need to free dynamically allocated memory.
    free(ptr);
    free(ptr2);
    free(cptr);
    return 0;
}
