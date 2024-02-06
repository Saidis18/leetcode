#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int count(unsigned int x){ // Not my code
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

int main(){
    int n = 0b11110000111100001111010011110000;
    printf("%d", count(n));
    return 0;
}