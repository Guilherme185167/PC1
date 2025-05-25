#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void soma()
{
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    while (1)
    {
        if (v > 10)
        {
            lim = 50;
            if (v > 25)
                lim = 120;
        }

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 + n2;

        system("clear");
        printf("Quanto é %d + %d?\n>> ", n1, n2);
        scanf("%d", &esc);
        if (esc == 244)
        {
            break;
        }

        if (esc == res)
        {
            v += 1;
            printf("Correto! %d\n", v);
        }
        else if (esc != res)
        {
            printf("Errado! %d\n", res);
            f += 1;
        }
        sleep(1);
    }
}
void sub()
{
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    while (1)
    {
        if (v > 10)
        {
            lim = 50;
            if (v > 25)
                lim = 120;
        }

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 - n2;

        system("clear");
        printf("Quanto é %d - %d?\n>> ", n1, n2);
        scanf("%d", &esc);
        if (esc == 244)
        {
            break;
        }

        if (esc == res)
        {
            v += 1;
            printf("Correto! %d\n", v);
        }
        else if (esc != res)
        {
            printf("Errado! %d\n", res);
            f += 1;
        }
        sleep(1);
    }
}
void mult()
{
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    while (1)
    {
        if (v > 10)
        {
            lim = 50;
            if (v > 25)
                lim = 120;
        }

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 - n2;

        system("clear");
        printf("Quanto é %d * %d?\n>> ", n1, n2);
        scanf("%d", &esc);
        if (esc == 244)
        {
            break;
        }

        if (esc == res)
        {
            v += 1;
            printf("Correto! %d\n", v);
        }
        else if (esc != res)
        {
            printf("Errado! %d\n", res);
            f += 1;
        }
        sleep(1);
    }
}
void divis()
{
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;

    while (1)
    {
        if (v > 10)
        {
            lim = 50;
            if (v > 25)
                lim = 120;
        }

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 - n2;

        system("clear");
        printf("Quanto é %d / %d?\n>> ", n1, n2);
        scanf("%d", &esc);
        if (esc == 244)
        {
            break;
        }

        if (esc == res)
        {
            v += 1;
            printf("Correto! %d\n", v);
        }
        else if (esc != res)
        {
            printf("Errado! %d\n", res);
            f += 1;
        }
        sleep(1);
    }
}
void equee()
{
    srand(time(NULL));
    int resposta_usuario,dificuldade = 0,min = 0,max = 10;

    while (1)
    {
        if(dificuldade > 5){
            max = 50;
            min = 10;
            if(dificuldade > 13){
            max = 100;
            min = 35;
            if(dificuldade > 25){
            max = 100;
            min = 0;
        }
        }
        }
        system("clear");

        //Gerar equação aleatória
        int qtd_numeros = rand() % 3 + 2; // 2 a 4 números
        int numeros[qtd_numeros];
        char operadores[qtd_numeros - 1];

        //Preenche números
        for (int i = 0; i < qtd_numeros; i++)
        {
            numeros[i] = rand() % max + min;
        }

        //Operadores
        char ops[] = {'+', '-', '*', '/'};
        for (int i = 0; i < qtd_numeros - 1; i++)
        {
            operadores[i] = ops[rand() % 4];
        }

        //Mostrar equação
        printf("Dificuldade: %d\nResolva: ",dificuldade);
        for (int i = 0; i < qtd_numeros; i++)
        {
            printf("%d", numeros[i]);
            if (i < qtd_numeros - 1)
            {
                printf(" %c ", operadores[i]);
            }
        }
        printf("\n");

        //Calcular o resultado correto
        int resultado = numeros[0];

        //resolver * , /
        for (int i = 1; i < qtd_numeros; i++)
        {
            if (operadores[i - 1] == '*')
            {
                resultado *= numeros[i];
            }
            else if (operadores[i - 1] == '/')
            {
                if (numeros[i] == 0)
                {                   
                    numeros[i] = 1; 
                }
                resultado /= numeros[i];
            }
        }

        //resolver + , -
        for (int i = 1; i < qtd_numeros; i++)
        {
            if (operadores[i - 1] == '+')
            {
                resultado += numeros[i];
            }
            else if (operadores[i - 1] == '-')
            {
                resultado -= numeros[i];
            }
        }

        //Resposta do usuário
        printf("Sua resposta: ");
        scanf("%d", &resposta_usuario);

        if (resposta_usuario == 244)
        {
            break;
        }
        else if (resposta_usuario == resultado)
        {
            printf("Correto!\n");
            dificuldade+=1;
        }
        else
        {
            printf("Errado! O resultado era: %d\n", resultado);
        }

        // Pausa antes de continuar
        printf("\nPressione ENTER para continuar...");
        getchar(); 
        getchar();
    }
}

int main()
{
    int op;
    printf("\n>> ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        soma();
        break;
    case 2:
        sub();
        break;
    case 3:
        mult();
        break;
    case 4:
        divis();
        break;
    case 5:
        equee();
        break;
    default:
        break;
    }
}