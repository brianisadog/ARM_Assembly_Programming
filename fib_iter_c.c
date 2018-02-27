#include <stdio.h>

int fib_iter_c(int n) {
    if (n <= 0) {
        return 0;
    }
    
    int i, temp;
    int a = 0, b = 1;

    for (i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}
