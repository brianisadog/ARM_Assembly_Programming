/* driver.c - C driver program to test assembly functions */
#include <stdio.h>

int sum_array_c(int *, int);
int sum_array_s(int *, int);
int find_max_c(int *, int);
int find_max_s(int *, int);
int fib_iter_c(int);
int fib_iter_s(int);
int fib_rec_c(int);

void test_sum_array();
void test_find_max();
void test_fib();

int main(int argc, char **argv) {

    test_sum_array();
    test_find_max();
    test_fib();
    
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

void test_find_max() {
    int positive[4] = {2, 4, 6, 8};
    int negative[4] = {-2, -4, -6, -8};
    int zero[5] = {0, -2, 0, 0, 0};
    int large_set[1001];
    int i, max;

    for (i = 0; i < 1001; i++) {
        large_set[i] = i * 2;
    }

    printf("\n");
    printf("find_max:\n");

    max = find_max_c(positive, 4);
    printf("find_max_c({2, 4, 6, 8}, 4) = %d\n", max);
    max = find_max_s(positive, 4);
    printf("find_max_s({2, 4, 6, 8}, 4) = %d\n", max);
    
    max = find_max_c(negative, 4);
    printf("find_max_c({-2, -4, -6, -8}, 4) = %d\n", max);
    max = find_max_s(negative, 4);
    printf("find_max_s({-2, -4, -6, -8}, 4) = %d\n", max);

    max = find_max_c(zero, 5);
    printf("find_max_c({0, -2, 0, 0, 0}, 5) = %d\n", max);
    max = find_max_s(zero, 5);
    printf("find_max_s({0, -2, 0, 0, 0}, 5) = %d\n", max);

    max = find_max_c(large_set, 1001);
    printf("find_max_c(*large_set, 1001) = %d\n", max);
    max = find_max_s(large_set, 1001);
    printf("find_max_s(*large_set, 1001) = %d\n", max);
}

void test_fib() {
    int n, result;

    printf("\n");
    printf("fib_iter/fib_rec:\n");

    for (n = 0; n <= 20; n++) {
        result = fib_iter_c(n);
        printf("fib_iter_c(%d) = %d\n", n, result);
        result = fib_iter_s(n);
        printf("fib_iter_s(%d) = %d\n", n, result);
        result = fib_rec_c(n);
        printf("fib_rec_c(%d) = %d\n", n, result);
    }
}
