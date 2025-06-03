#include <stdio.h>
#include <stdlib.h>
#define linha 3
#define coluna 3

int main()
{
    system("clear");
    int matte[3][3];
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (i == 0)
            {
                matte[i][j] = j;
            }
            else if (i == 1)
            {
                matte[i][j] = j + 10;
            }
            else if (i == 2)
            {
                matte[i][j] = j + 20;
            }
        }
    }
    
    for (int j = coluna - 1; j >= 0; j--)
    {
        printf("[ ");
        for (int i = 0; i < linha; i++)
        {
            printf("%02d ", matte[i][j]);
        }
        printf("]");
        puts("");
    }
    
    return 0;
}