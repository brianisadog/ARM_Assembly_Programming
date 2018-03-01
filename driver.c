/* driver.c - C driver program to test assembly functions */
#include <stdio.h>

int sum_array_c(int *, int);
int sum_array_s(int *, int);
int find_max_c(int *, int);
int find_max_s(int *, int);
int fib_iter_c(int);
int fib_iter_s(int);
int fib_rec_c(int);
int fib_rec_s(int);
int find_str_c(char *, char*);
int find_str_s(char *, char *);
void test_sum_array_and_find_max();
void test_fib_iter_and_fib_rec();
void test_find_str();

int main(int argc, char **argv) {

    test_sum_array_and_find_max();
    test_fib_iter_and_fib_rec();
    test_find_str();
    
    return 0;
}

void test_sum_array_and_find_max() {
    int positive[4] = {1, 2, 3, 4};
    int negative[4] = {-1, -2, -3, -4};
    int zero[5] = {0, 0, 0, 0, 0};
    int large_set[1000];
    int i, sum, max;
    
    for (i = 1; i <= 1000; i++) {
        large_set[i - 1] = i;
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
    printf("sum_array_c({0, 0, 0, 0, 0}, 5) = %d\n", sum);
    sum = sum_array_s(zero, 5);
    printf("sum_array_s({0, 0, 0, 0, 0}, 5) = %d\n", sum);

    sum = sum_array_c(large_set, 1000);
    printf("sum_array_c({1, 2, ..., 999, 1000}, 1000) = %d\n", sum);
    sum = sum_array_s(large_set, 1000);
    printf("sum_array_s({1, 2, ..., 999, 1000}, 1000) = %d\n", sum);

    printf("\n");
    printf("find_max:\n");

    max = find_max_c(positive, 4);
    printf("find_max_c({1, 2, 3, 4}, 4) = %d\n", max);
    max = find_max_s(positive, 4);
    printf("find_max_s({1, 2, 3, 4}, 4) = %d\n", max);

    max = find_max_c(negative, 4);
    printf("find_max_c({-1, -2, -3, -4}, 4) = %d\n", max);
    max = find_max_s(negative, 4);
    printf("find_max_s({-1, -2, -3, -4}, 4) = %d\n", max);

    max = find_max_c(zero, 5);
    printf("find_max_c({0, 0, 0, 0, 0}, 5) = %d\n", max);
    max = find_max_s(zero, 5);
    printf("find_max_s({0, 0, 0, 0, 0}, 5) = %d\n", max);

    max = find_max_c(large_set, 1000);
    printf("find_max_c({1, 2, ..., 999, 1000}, 1000) = %d\n", max);
    max = find_max_s(large_set, 1000);
    printf("find_max_s({1, 2, ..., 999, 1000}, 1000) = %d\n", max);
}

void test_fib_iter_and_fib_rec() {
    int n, result;

    printf("\n");
    printf("fib_iter:\n");

    for (n = 0; n <= 20; n++) {
        result = fib_iter_c(n);
        printf("fib_iter_c(%d) = %d\n", n, result);
        result = fib_iter_s(n);
        printf("fib_iter_s(%d) = %d\n", n, result);
    }

    printf("\n");
    printf("fib_rec:\n");

    for (n = 0; n <= 20; n++) {
        result = fib_rec_c(n);
        printf("fib_rec_c(%d) = %d\n", n, result);
        result = fib_rec_s(n);
        printf("fib_rec_s(%d) = %d\n", n, result);
    }
}

void test_find_str() {
    char *s = "Computer Science is actually art!";
    char *sub;
    int result;

    printf("\n");
    printf("find_str:\n");

    sub = "art";
    result = find_str_c(s, sub);
    printf("find_str_c(\"Computer Science is actually art!\", \"art\") = %d\n", result);
    result = find_str_s(s, sub);
    printf("find_str_s(\"Computer Science is actually art!\", \"art\") = %d\n", result);

    sub = "s actua";
    result = find_str_c(s, sub);
    printf("find_str_c(\"Computer Science is actually art!\", \"s actua\") = %d\n", result);
    result = find_str_s(s, sub);
    printf("find_str_s(\"Computer Science is actually art!\", \"s actua\") = %d\n", result);

    sub = "Computer Science";
    result = find_str_c(s, sub);
    printf("find_str_c(\"Computer Science is actually art!\", \"Computer Science\") = %d\n", result);
    result = find_str_s(s, sub);
    printf("find_str_s(\"Computer Science is actually art!\", \"Computer Science\") = %d\n", result);
    

    sub = "not an art";
    result = find_str_c(s, sub);
    printf("find_str_c(\"Computer Science is actually art!\", \"not an art\") = %d\n", result);
    result = find_str_s(s, sub);
    printf("find_str_s(\"Computer Science is actually art!\", \"not an art\") = %d\n", result);

    sub = "art?";
    result = find_str_c(s, sub);
    printf("find_str_c(\"Computer Science is actually art!\", \"art?\") = %d\n", result);
    result = find_str_s(s, sub);
    printf("find_str_s(\"Computer Science is actually art!\", \"art?\") = %d\n", result);
}
