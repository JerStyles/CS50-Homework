#include <stdio.h>

int main(void)
{

    __uint8_t smallInt;
    __uint16_t mediumInt;

    smallInt = 255;
    mediumInt = 32767;
    printf("smallInt: %d\n", smallInt);
    printf("mediumInt: %d\n", mediumInt);

    return 0;
}