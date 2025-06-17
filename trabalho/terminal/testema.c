#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

int main()
{
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    int n1, n2, v = 0, f = 0, lim = 10;
    float res, esc;
    char buffer[100];
    char *endptr;

    srand(time(NULL));
    system("clear");
    printf("\t\t\t   BEM VINDO AO MODO DIVISÃO\n");
    sleep(1);
    system("clear");
    printf("Digite 9999 para voltar\n");
    sleep(1);
    system("clear");

    while (1)
    {
        if (v > 10)
        {
            lim = 50;
            if (v > 25)
                lim = 120;
        }

        n1 = rand() % lim + 1;
        n2 = rand() % lim + 1;
        while (n2 == 0)
            n2 = rand() % lim + 1;
        res = (float)n1 / n2;

        do
        {
            system("clear");
            printf("Dificuldade: %d\nQuanto é %d / %d?\n>> ", v, n1, n2);

            // Ler a entrada como string
            if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            {
                printf("Erro na leitura!\n");
                continue;
            }

            // Substituir vírgula por ponto
            for (int i = 0; buffer[i]; i++)
            {
                if (buffer[i] == ',')
                {
                    buffer[i] = '.';
                }
            }

            // Converter para float com verificação
            esc = strtof(buffer, &endptr);

            // Verificar se a conversão foi bem-sucedida
            if (endptr == buffer)
            {
                printf("Entrada inválida! Use números decimais com ponto ou vírgula.\n");
                usleep(1000000);
                continue;
            }

            if (esc == 9999)
            {
                return 0;
            }
            else if (fabs(esc - res) > 0.01)
            {
                printf("Errado!\n");
                f += 1;
                usleep(1000000);
            }
        } while (fabs(esc - res) > 0.01);

        v += 1;
        printf("\033[32mCorreto!\033[m\n");
        fflush(stdout);
        coin();
        usleep(300000);
    }
    fclose(arquivo);
}
