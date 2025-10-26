// ran out of time not fully done: 

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

int atoi(const char *str)
{
    char * temp = (char *)str;
    // 'a' - 'A' or 'z - 'Z'
    // '0' - '9' number
    int fin = 0;
    //printf("%c", *temp);
    while(*temp != '\0')
    {
        printf("%c",*temp);
        int value = *temp;
        // if its ! a number
        
    
        if((value >= '0') && (value <= '9'))
        {
            
            //printf("num detect");
            fin = (int)(value - '0') * 10;
            printf("%d\n",fin);
            // 1
            // 1*10 + 2
            // 12 * 10 + 3
            // 
        }
        temp++;
    }
    return fin;
}

int main(int argc, char *argv[])
{
    atoi("J12");
}
