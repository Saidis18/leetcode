// Useless, but fun (just use ... % 3)
// This problem is not a leetcode problem

#include <stdbool.h>
#include <stdio.h>

unsigned int count(unsigned int x){ // Not my code
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

bool isMultipleOfThree(int n) {
    if(n<0){
        return isMultipleOfThree(-n);
    }
    if(n<4){
        return n == 0 || n == 3;
    }
    unsigned int odd = 0b10101010101010101010101010101010;
    unsigned int even = ~odd;
    return isMultipleOfThree(count(n & odd) - count(n & even));
}

int main(){
    for(int i = -20; i < 20; i++){
        printf("%d : %d\n", i, isMultipleOfThree(i));
    }
    return 0;
}