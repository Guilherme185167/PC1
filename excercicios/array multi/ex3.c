#include <stdio.h>
#include <stdlib.h>
int main()
{
    system("clear");
    int A[2][3], B[3][2], C[2][2];

    //*matix A
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                A[i][j] = j;
            }
            else
            {
                A[i][j] = j + 10;
            }
        }
    }

    //*matix B
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 0)
            {
                B[i][j] = j;
            }
            else if (i == 1)
            {
                B[i][j] = j + 10;
            }
            else
            {
                B[i][j] = j + 20;
            }
        }
    }

    //*Matix C
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //! Saida A
    puts("A:");
    for (int i = 0; i < 2; i++)
    {
        printf("[ ");
        for (int j = 0; j < 3; j++)
        {
            printf("%02d ", A[i][j]);
        }
        printf("] ");
        puts("");
    }
    puts("");
    
    //! Saida B
    puts("B:");
    for (int i = 0; i < 3; i++)
    {
        printf("[ ");
        for (int j = 0; j < 2; j++)
        {
            printf("%02d ", B[i][j]);
        }
        printf("] ");
        puts("");
    }
    puts("");
    
    //! Saida C
    puts("C:");
    for (int i = 0; i < 2; i++)
    {
        printf("[ ");
        for (int j = 0; j < 2; j++)
        {
            printf("%03d ", C[i][j]);
        }
        printf("] ");
        puts("");
    }
    return 0;
}