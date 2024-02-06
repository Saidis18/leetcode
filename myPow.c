#include <limits.h>

double tail_rec(double x, int n, double result){
    if(0 == n){
        return result;
    }
    switch((-INT_MAX) & n){
        case -INT_MAX: // Negative odd
            return tail_rec(x * x , n/2, result / x);
            break;
        case 1: // Positive odd
            return tail_rec(x * x, n>>1, result * x);
            break;
        case -INT_MAX - 1: // Negative even
            return tail_rec(x * x, n/2, result);
            break;
        case 0: // Positive even
            return tail_rec(x * x, n>>1, result);
            break;
        default:
            return 0;
            break;
    }
}

double myPow(double x, int n) {
    return tail_rec(x, n, 1);
}

int main(){
    return 0;
}