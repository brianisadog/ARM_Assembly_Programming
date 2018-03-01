#include <stdio.h>

int find_str_c(char *s, char *sub) {
    char start_of_sub = *sub;
    char *pointer_sub;
    int result = -1;
    int i = 0;
    int j;

    while (result == -1 && *s != '\0') {
        if (*s == start_of_sub) {
            pointer_sub = sub;
            j = i;
            
            while (*s == *pointer_sub && *pointer_sub != '\0') {
                s += 1;
                pointer_sub += 1;
                i += 1;
            }

            if (*pointer_sub == '\0') {
                result = j;
            }
        }
        s += 1;
        i += 1;
    }

    return result;
}
