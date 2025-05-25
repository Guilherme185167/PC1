#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define tit 30
struct termios original;

void menu_principal();
void menu_livro();
void matematica();
void desativarModoCanonico();
void restaurarModoCanonico();

char *nome_livro[] = {
    "Hardware"};

void soma()
{
    srand(time(NULL));
    int n1, n2, res, esc;
    int v = 0, f = 0, lim = 10;

    while (1)
    {
        if (v > 10)
            lim = 50;
        if (v > 25)
            lim = 120;

        n1 = rand() % lim;
        n2 = rand() % lim;
        res = n1 + n2;

        system("clear");
        printf("Quanto é %d + %d? [4002 para voltar]\n>> ", n1, n2);

        if (scanf("%d", &esc) != 1)
        {
            printf("Entrada inválida! Digite um número.\n");

            while ((getchar()) != '\n')
            {
            } // Limpa buffer
            sleep(1);
            continue;
        }

        while ((getchar()) != '\n')
        {
        }

        if (esc == 4002)
        {
            return;
        }

        if (esc == res)
        {
            printf("Correto! (%d acertos)\n", ++v);
        }
        else
        {
            printf("Errado! Era %d (%d erros)\n", res, ++f);
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

        if (esc == 4002)
        {
            desativarModoCanonico();
            return;
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
    int resposta_usuario, dificuldade = 0, min = 0, max = 10;

    while (1)
    {
        if (dificuldade > 5)
        {
            max = 50;
            min = 10;
            if (dificuldade > 13)
            {
                max = 100;
                min = 35;
                if (dificuldade > 25)
                {
                    max = 100;
                    min = 0;
                }
            }
        }
        system("clear");

        // Gerar equação aleatória
        int qtd_numeros = rand() % 3 + 2;
        int numeros[qtd_numeros];
        char operadores[qtd_numeros - 1];

        // Preenche números
        for (int i = 0; i < qtd_numeros; i++)
        {
            numeros[i] = rand() % max + min;
        }

        // Operadores
        char ops[] = {'+', '-', '*', '/'};
        for (int i = 0; i < qtd_numeros - 1; i++)
        {
            operadores[i] = ops[rand() % 4];
        }

        // Mostrar equação
        printf("[4002 p/ sair] Dificuldade: %d\n\nResolva: ", dificuldade);
        for (int i = 0; i < qtd_numeros; i++)
        {
            printf("%d", numeros[i]);
            if (i < qtd_numeros - 1)
            {
                printf(" %c ", operadores[i]);
            }
        }
        printf("\n");

        // Calcular o resultado correto
        int resultado = numeros[0];

        // resolver * , /
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

        // resolver + , -
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

        // Resposta do usuário
        printf("\nSua resposta: ");
        scanf("%d", &resposta_usuario);

        if (resposta_usuario == 4002)
        {
            return;
        }
        else if (resposta_usuario == resultado)
        {
            printf("Correto!\n");
            dificuldade += 1;
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

void desativarModoCanonico()
{
    struct termios novo;
    tcgetattr(STDIN_FILENO, &original);
    novo = original;
    novo.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &novo);
}

void restaurarModoCanonico()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
}

void livros(int n, int gabarito[10])
{
    int mv = 0, que = 0, resp[10], cer = 0, err = 0, form[10];
    char nav;
    char *cores[] = {
        "\033[31m", // Vermelho
        "\033[32m", // Verde
        "\033[33m", // Amarelo
        "\033[34m"  // Azul
    };

    puts("Utilize o livro para visualizar as questoes!\n");
    while (1)
    {
        system("clear");
        printf("\t\t\033[1;33m%s: Questão %d [a/d para mover q para sair]\033[m\n\n", nome_livro[n], que + 1);
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\t\a|| [%s\u2588\u2588\033[m ||\t", cores[i]); // destaque reverso
            else
                printf(" \t\a\033[%s\u2588\u2588\033[m\t ", cores[i]); // normal
        }
        puts("");

        nav = getchar();
        if (nav == 'a')
        {
            mv--;
            if (mv < 0)
                mv = 3;
        }
        else if (nav == 'd')
        {
            mv++;
            if (mv > 3)
                mv = 0;
        }
        else if (nav == '\n')
        {
            resp[que] = mv + 1;
            que += 1;
        }
        else if (nav == 'q')
        {
            menu_livro();
        }
        if (que == 10)
        {
            break;
        }
    }
    // verificação das respostas
    for (int j = 0; j < 10; j++)
    {
        if (resp[j] == gabarito[j])
        {
            cer += 1;
            form[j] = 1;
        }
        else
        {
            err += 1;
            form[j] = 0;
        }
    }
    // imprimir respostas
    for (int j = 0; j < 10; j++)
    {
        if (form[j] == 1)
            printf("\033[32m%d \033[m", resp[j]);
        else
            printf("\033[31m%d \033[m", resp[j]);
    }
    puts("");
    // imprimir gabarito
    for (int j = 0; j < 10; j++)
    {
        printf("\033[32m%d \033[m", gabarito[j]);
    }
    puts("\n");
    printf("\033[32mAcertos: %d \033[31mErros %d\n\033[m", cer, err);
}

void matematica()
{
    int mv = 0;
    char nav;
    char *op[] = {"\aSoma", "\aSubtração", "\aMultiplicação", "\aDivisão", "\aEquação", "\a::Sair"};

    while (1)
    {
        system("clear");
        puts("\033[1;33mEscolha um desafio: [use w/s para navegar enter para confirmar]\033[m\n");

        for (int i = 0; i < 6; i++)
        {
            if (i == mv)
                printf("\033[1;36;47m%s\033[m\n", op[i]);
            else
                printf("%s\n", op[i]);
        }

        nav = getchar();
        if (nav == 'w')
            mv = (mv == 0) ? 5 : mv - 1;
        else if (nav == 's')
            mv = (mv == 5) ? 0 : mv + 1;
        else if (nav == '\n')
        {

            restaurarModoCanonico();

            switch (mv)
            {
            case 0:
                soma();
                break;
            case 1:
                sub();
                break;
            case 2:
                mult();
                break;
            case 3:
                divis();
                break;
            case 4:
                equee();
                break;
            case 5:
                desativarModoCanonico();
                menu_principal();
                break;
            default:
                break;
            }
        }
    }
}

void menu_livro()
{
    int mv = 0;
    char nav;
    // opções do menu
    char *op[] = {
        "\aAtividades Programadas Nº 01",
        "\aAtividades Programadas Nº 02",
        "\aAtividades Programadas Nº 03",
        "\a::Sair"};

    while (1)
    {
        system("clear");
        puts("\033\t[1;33mEscolha um livro: [use w/s para navegar enter para confirmar]\033[m\n");
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\033[1;36;47m%s\033[m\n", op[i]);
            else
                printf("%s\n", op[i]);
        }
        nav = getchar();
        if (nav == 'w')
        {
            mv--;
            if (mv < 0)
                mv = 3;
        }
        else if (nav == 's')
        {
            mv++;
            if (mv > 3)
                mv = 0;
        }
        else if (nav == '\n')
        {
            break;
        }
    }
    switch (mv)
    {
    case 0:
    {

        int gab1[10] = {1, 1, 4, 3, 2, 4, 1, 1, 4, 3};
        livros(0, gab1);
        break;
    }
    case 1:
    {
        int gab2[10] = {2, 1, 4, 3, 2, 4, 1, 1, 4, 3};
        livros(0, gab2);
        break;
    }
    case 2:
    {
        int gab3[10] = {3, 1, 4, 3, 2, 4, 1, 1, 4, 3};
        livros(0, gab3);
        break;
    }
    case 3:
        menu_principal();
        break;

    default:
        break;
    }
}

void menu_principal() {
    int mv;
    
    while (1) {
        system("clear");
        puts("\033[1;33mESCOLHA UMA OPÇÃO:\033[m\n");
        puts("1 - Equações Matemáticas");
        puts("2 - Livros");
        puts("3 - Gabritos");
        puts("0 - Sair");
        printf("\nDigite o número da opção: ");
        
        // Verifica se a entrada é um número
        if (scanf("%d", &mv) != 1) {
            // Limpa o buffer se a entrada for inválida
            while (getchar() != '\n');
            puts("\033[31mOpção inválida! Tente novamente.\033[m");
            sleep(1);
            continue;
        }
        
        // Limpa o buffer após a leitura
        while (getchar() != '\n');

        switch (mv) {
            case 1:
                matematica();
                break;
            case 2:
                menu_livro();
                break;
            case 3:
                printf("\nGabritos selecionado!\n");
                sleep(2);
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                return;
            default:
                puts("\033[31mOpção inválida! Tente novamente.\033[m");
                sleep(1);
                break;
        }
    }
}

int main()
{
    menu_principal();

    return 0;
}