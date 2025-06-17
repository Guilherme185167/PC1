/*Crie um programa que escreve a letra de uma música, linha por linha. O usuário deve pressionar uma tecla (<enter>) para que a próxima linha seja exibida. Você pode usar uma “matriz”: char letra[NUMERO_LINHAS][COLUNAS].*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imp(char letra[14][150])
{
    for (int i = 0; i < 14; i++)
    {
        printf("%s", letra[i]);
        getchar();
    }
}
int main()
{
    system("clear");
    char letra[14][150] = {
        {"Day-o, day-o"},
        {"Daylight come and we want go home"},
        {"Day, is a day, is a day, is a day, is a day, is a day-o"},
        {"Daylight come and we want go home\n"},
        {"Work all night on a drink of rum"},
        {"(Daylight come and we want go home)"},
        {"Stack banana 'til the morning come"},
        {"(Daylight come and we want go home)\n"},
        {"Come Mister tally man, tally me banana"},
        {"(Daylight come and we want go home)"},
        {"Come Mister tally man, tally me banana"},
        {"(Daylight come and we want go home)\n"}};
    imp(letra);
}