#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i)
    {
        res <<= 1;
        res |= n & 1; 
        n >>= 1;
    }

    return res;
    
}


void printBinary(uint32_t num){
    for (int i = 0; i < 32; ++i)
    {
        printf("%d", num & 1);
        num >>= 1;
    
        // add a space every 8 bits for readability
        if ((i + 1) % 8 == 0) {
            printf(" ");  
        }
    }
}

int main(void){
    uint32_t num = 80;
    printf("before: ");
    printBinary(num);
    printf("\n");

    num = reverseBits(num);

    printf("after: ");
    printBinary(num);
    printf("\n");

    return 0;
}