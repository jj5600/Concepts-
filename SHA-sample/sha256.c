// sample of a single block .works for small words
//  sha256_imp.c
// SHA-256 implementation
#include <stdio.h>
#include <string.h>
#include <stdint.h>
// the output of sha-256 is alwasy 256 bits long or 32 bytes
// for this initial base we are assumig it fits within a single 512 bit block to keep it simple
#define TOTAL_BLOCK 64
#define SIZE_PORTION 8
#define BLOCK (TOTAL_BLOCK - SIZE_PORTION)
#define RIGHTROTATE(x,n)(((x)>>(n)) | ((x)<<(32-(n))))
int main(void)
{
    unsigned char str[TOTAL_BLOCK] = {0};
    printf("Please enter a string:");
    fgets(str, sizeof(str), stdin);
    // remove the trailing newline and replace with null
    //uint64_t Stringsize = (strlen(str)-1)*8;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') len--;
    uint64_t Stringsize = len * 8;
    
    /*
    if(str[strlen(str)-1] == '\n')
    {
        // this is the single 1 bit that is set after the inital message
        str[strlen(str)-1] = 0x80;
        str[strlen(str)] = 0x0;
    }
    */
    str[len] = 0x80;
    memset(str + len + 1, 0, 55 - len);
    str[55] = (uint8_t)(Stringsize >> 56);
    str[56] = (uint8_t)(Stringsize >> 48);
    str[57] = (uint8_t)(Stringsize >> 40);
    str[58] = (uint8_t)(Stringsize >> 32);
    str[59] = (uint8_t)(Stringsize >> 24);
    str[60] = (uint8_t)(Stringsize >> 16);
    str[61] = (uint8_t)(Stringsize >> 8);
    str[62] = (uint8_t)(Stringsize);
    printf("%s\n",str);
    
    int numbits = sizeof(char)*8;
    char * ptr = str;
    // print the output in binary
   
    while(*ptr != '\0')
    {
        for ( int i = numbits-1; i>=0; i--)
        {
            printf("%d",(*ptr >> i)&1);
        }
        printf(" ");
        ptr++;
    }
    uint32_t messageSchedule[TOTAL_BLOCK] = {0};
    // move the user input into a uint32_t array value and concat the values
    for(int row_iter = 0; row_iter < 16 ;row_iter++ ) // was 14
    {
        messageSchedule[row_iter] =
            ((uint32_t)(uint8_t)str[row_iter * 4]     << 24) |
            ((uint32_t)(uint8_t)str[row_iter * 4 + 1] << 16) |
            ((uint32_t)(uint8_t)str[row_iter * 4 + 2] <<  8) |
            ((uint32_t)(uint8_t)str[row_iter * 4 + 3]);
       // printf("\nRow iter is %d", row_iter);
    }
    
    // hard coding an example that is just 1 block size
    messageSchedule[14] = (uint32_t)((Stringsize >> 32) & 0xFFFFFFFF);
    messageSchedule[15] = (uint32_t)(Stringsize & 0xFFFFFFFF );
    // There is a message block that is 512 bits or 64 bytes
    // calculate the nexdt word which is :
    // w16 = w0 + sigma0 + w9 + sigma1;
    // sigma0 =(w1 RIGHTROTATE(7)
    
    // populate the entire message schedule block
    for(int row_iter = 16; row_iter < TOTAL_BLOCK; row_iter++)
    {
        messageSchedule[row_iter] = messageSchedule[row_iter-16] +
        ((RIGHTROTATE(messageSchedule[row_iter-15], 7)) ^
        (RIGHTROTATE(messageSchedule[row_iter-15], 18)) ^
         (messageSchedule[row_iter-15] >> 3)) +
        messageSchedule[row_iter-7] +
        ((RIGHTROTATE(messageSchedule[row_iter-2], 17)) ^
        (RIGHTROTATE(messageSchedule[row_iter-2], 19)) ^
         (messageSchedule[row_iter-2] >> 10));
    }
    // inital values represent the
//Initialize hash value h0 to h7: first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19).
    const uint32_t initalHashValues[8] = {
        0x6a09e667, 0xbb67ae85,
        0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c,
        0x1f83d9ab, 0x5be0cd19 };
//Initialize array of K constants: first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311
    const uint32_t K_values[TOTAL_BLOCK] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf,
        0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 
        0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
        0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc,
        0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85,
        0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb,
        0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70,
        0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 
        0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f,
        0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
    
    uint32_t a = initalHashValues[0],
             b = initalHashValues[1],
             c = initalHashValues[2],
             d = initalHashValues[3],
             e = initalHashValues[4],
             f = initalHashValues[5],
             g = initalHashValues[6],
             h = initalHashValues[7];
    
    for( int row_ctr = 0; row_ctr < TOTAL_BLOCK; row_ctr++)
    {
        uint32_t Cap_Sigma_1 = (RIGHTROTATE(e, 6)) ^ (RIGHTROTATE(e, 11)) ^ (RIGHTROTATE(e, 25));
        uint32_t Cap_Sigma_0 = (RIGHTROTATE(a, 2)) ^ (RIGHTROTATE(a, 13)) ^ (RIGHTROTATE(a, 22));
        uint32_t Choice = (e & f) ^ ((~e) & g);
        uint32_t Majority = (a & b) ^ (a & c) ^ (b & c);
        uint32_t Temp1 = h + Cap_Sigma_1 + Choice + K_values[row_ctr] + messageSchedule[row_ctr];
        uint32_t Temp2 = Cap_Sigma_0 + Majority;
        
        h = g;
        g = f;
        f = e;
        e = d + Temp1;
        d = c;
        c = b;
        b = a;
        a = Temp1 + Temp2;
    }
    
    uint32_t final_h0 = initalHashValues[0] + a,
             final_h1 = initalHashValues[1] + b,
    final_h2 = initalHashValues[2] + c,
    final_h3 = initalHashValues[3] + d,
    final_h4 = initalHashValues[4] + e,
    final_h5 = initalHashValues[5] + f,
    final_h6 = initalHashValues[6] + g,
    final_h7 = initalHashValues[7] + h;
    
    printf("\nFinal SHA256 hash of %s is :%x%x%x%x%x%x%x%x\n",str,final_h0,final_h1,final_h2,final_h3,final_h4,final_h5,final_h6,final_h7);
    
    return 0;
}
