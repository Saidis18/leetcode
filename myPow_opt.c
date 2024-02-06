#include <limits.h>

double myPow(double x, int n){
    double result = 1;
    while(0 != n){
        switch((-INT_MAX) & n){
            case -INT_MAX: // Negative odd
                n = n/2;
                result = result / x;
                break;
            case 1: // Positive odd
                n = n>>1;
                result = result * x;
                break;
            case -INT_MAX - 1: // Negative even
                n = n/2;
                break;
            case 0: // Positive even
                n = n>>1;
                break;
            default:
                return 0;
                break;
        }
        x = x * x; 
    }
    return result;
}

int main(){
    return 0;
}