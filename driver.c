/* driver.c - C driver program to test assembly functions */
#include <stdio.h>

int sum_array_c(int *, int);
int sum_array_s(int *, int);

void test_sum_array();

int main(int argc, char **argv) {

    test_sum_array();
    
    return 0;
}

void test_sum_array() {
    int positive[4] = {1, 2, 3, 4};
    int negative[4] = {-1, -2, -3, -4};
    int zero[5] = {-2, -1, 0, 1, 2};
    int large_set[1001];
    int i, sum;
    
    for (i = 0; i < 1001; i++) {
        large_set[i] = i * 2;
    }

    printf("sum_array:\n");
    
    sum = sum_array_c(positive, 4);
    printf("sum_array_c({1, 2, 3, 4}, 4) = %d\n", sum);
    sum = sum_array_s(positive, 4);
    printf("sum_array_s({1, 2, 3, 4}, 4) = %d\n", sum);

    sum = sum_array_c(negative, 4);
    printf("sum_array_c({-1, -2, -3, -4}, 4) = %d\n", sum);
    sum = sum_array_s(negative, 4);
    printf("sum_array_s({-1, -2, -3, -4}, 4) = %d\n", sum);
    
    sum = sum_array_c(zero, 5);
    printf("sum_array_c({-2, -1, 0, 1, 2}, 5) = %d\n", sum);
    sum = sum_array_s(zero, 5);
    printf("sum_array_s({-2, -1, 0, 1, 2}, 5) = %d\n", sum);

    sum = sum_array_c(large_set, 1001);
    printf("sum_array_c(*large_set, 1001) = %d\n", sum);
    sum = sum_array_s(large_set, 1001);
    printf("sum_array_s(*large_set, 1001) = %d\n", sum);
}
