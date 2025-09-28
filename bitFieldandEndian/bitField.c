
#include <stdio.h>

struct Status
{
    unsigned int read:4; // 4 bits each
    unsigned int error:4;
    unsigned int mode:4;
    unsigned int code:4; 
};
int main(void)
{
    struct Status s = {0,0,0,0};
    
    s.read = 0xF;
    s.error = 0xF;
    s.mode = 0xF;
    s.code = 0xF;
    
    
    uint32_t check_me = 0xAABBCCDD;
  
    return 0;
}
