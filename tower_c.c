#include <stdio.h>

void tower_c(int num, char frompeg, char topeg, char auxpeg) {
    if (num == 1) {
        printf("Move disk %d from peg %c to peg %c\n", num, frompeg, topeg);
            return;
    }
    
    tower_c(num - 1, frompeg, auxpeg, topeg);
    printf("Move disk %d from peg %c to peg %c\n", num, frompeg, topeg);
    tower_c(num - 1, auxpeg, topeg, frompeg);
}
