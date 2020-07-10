#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, int *argv[])
{
    int i, j;
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);

    for (i = 1; i <= height + 2; i++)
    {
        if (i == 1 || i == height + 2)
        {
            for (j = 1; j <= width; j++)
            {
                printf("*");
            }
        }
        else
        {
            for (j = 1; j <= width; j++)
                if (j == 1 || j == width)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
        }
        printf("\n");
    }
    return 0;
}
