#include <stdio.h>

int fib_rec_c(int n) {
    int result;
    
    if (n <= 0) {
        result = 0;
    }
    else if (n == 1) {
        result = 1;
    }
    else {
        result = fib_rec_c(n - 2) + fib_rec_c(n - 1);
    }

    return result;
}
