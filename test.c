#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
int m = -INT_MAX;
int n = 0b10000000000000000000000000000001;
*/

void parity_check(int n){
    switch((-INT_MAX) & n){
        case -INT_MAX:
            printf("Negative odd\n");
            break;
        case 1:
            printf("Positive odd\n");
            break;
        case -INT_MAX - 1:
            printf("Negative even\n");
            break;
        case 0:
            printf("Positive even\n");
            break;
        default:
            printf("???\n");
            break;
    }
}

int main(){
    parity_check(-10);
    parity_check(-9);
    parity_check(-1);
    parity_check(0);
    parity_check(1);
    parity_check(9);
    parity_check(10);
    printf("%d", 1>>1);
    return 0;
}