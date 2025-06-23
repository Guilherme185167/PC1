#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <math.h>
#include <ctype.h>

#define tit 30

char hora_atual[50];
char nome[30];

void livros();
void lista();

//*Função barra de carregamento
void barra()
{
    system("clear");
    printf("\033[37mINICIANDO [%25s]\033[m", "");
    fflush(stdout);

    printf("\033[1;12H");
    fflush(stdout);

    for (int i = 0; i < 25; i++)
    {
        printf("\033[36m%s\033[m", "\u2588");
        fflush(stdout);
        usleep(50000);
    }
    system("clear");
    printf("INICIANDO [\033[32m█████████████████████████\033[m]");
    printf("\033[m\n");
}

//* Função executar musica
void music()
{
    int resultado = system("./TESTE");

    if (resultado == -1)
    {
        printf("Erro ao executar o programa externo!\n");
    }
}

//* Função  som sair
void sai()
{
    int resultado = system("./sai");

    if (resultado == -1)
    {
        printf("Erro ao executar o programa externo!\n");
    }
}

//* Função coin
void coin()
{
    int resultado = system("./ts");

    if (resultado == -1)
    {
        printf("Erro ao executar o programa externo!\n");
    }
}

//* Função entrada
void entra()
{
    int resultado = system("./entra");

    if (resultado == -1)
    {
        printf("Erro ao executar o programa externo!\n");
    }
}

//* Função para pegar a hora atual da execução do codigo e salvar no pontos.txt
void pegar_hora()
{
    time_t agora;
    time(&agora);
    strftime(hora_atual, 50, "[%d/%m/%Y %H:%M:%S]", localtime(&agora));
}

//* função para exibir o a chamada de saida e guardar os resultados no pontos.txt
void saida(char hora_atual[], char op[], int v, int f)
{
    FILE *arquivo = fopen("pontos.txt", "a");
    fprintf(arquivo, "| Hora atual: %s |\n| Modo: %29s |\n| Dificuldade: %20d |\n| Acertos: %24d |\n| Erros: %26d |\n\n", hora_atual, op, v, v, f);
    fclose(arquivo);
    printf("\t\t\t\t\033[35mVoltando");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(50000);
    }
    system("clear");
    printf("\033[m");
    sai();
    printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
    sleep(1);
    system("clear");
}

//* função para mostrar o placar
void placar()
{
    FILE *arquivo = fopen("pontos.txt", "r");

    if (arquivo == NULL)
    {
        printf("\033[31mErro ao abrir o arquivo!\033[m\n");
        return;
    }

    system("clear");
    printf("\n\t\t\033[34m=== REGISTRO DE PONTUAÇÕES ===\033[m\n\n");

    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo))
    {
        printf("%s", linha);
    }

    fclose(arquivo);

    printf("\n\nPressione ENTER para voltar...");
    getchar();
    getchar();
    sai();
    system("clear");
}

//* função soma
void soma()
{
    pegar_hora();
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;
    char input[10];
    system("clear");
    printf("\t\t\t   BEM VINDO AO MODO SOMA\n");
    sleep(1);
    system("clear");
    printf("Digte 9999 para voltar\n");
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

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 + n2;
        do
        {
            system("clear");
            printf("Dificuldade: %d\nQuanto é %d + %d?\n>> ", v, n1, n2);
             //! le a entrada como string
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("erro na leitura!");
            continue;
        }
        //! converte para inteiro
        if (sscanf(input, "%d", &esc) != 1)
        {
            printf("Codigo invalido, utilize apenas numeros!");
            sleep(1);
            continue;
        }
            if (esc == 9999)
            {

                saida(hora_atual, "Adição", v, f);
                return;
            }
            else if (esc != res)
            {
                printf("Errado!\n");
                f += 1;
            }
            usleep(500000);
        } while (esc != res);
        if (esc == res)
        {
            v += 1;
            printf("\033[32mCorreto!\033[m\n");
            fflush(stdout);
            coin();
        }
        usleep(500000);
    }
}

//* função subtração
void sub()
{
    pegar_hora();
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;
    char input[10];
    system("clear");
    printf("\t\t\t   BEM VINDO AO MODO SUBTRAÇÃO\n");
    sleep(1);
    system("clear");
    printf("Digte 9999 para voltar\n");
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

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 - n2;
        do
        {
            system("clear");
            printf("Dificuldade: %d\nQuanto é %d - %d?\n>> ", v, n1, n2);
             //! le a entrada como string
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("erro na leitura!");
            continue;
        }
        //! converte para inteiro
        if (sscanf(input, "%d", &esc) != 1)
        {
            printf("Codigo invalido, utilize apenas numeros!");
            sleep(1);
            continue;
        }
        
            if (esc == 9999)
            {
                saida(hora_atual, "Subtração", v, f);
                return;
            }
            else if (esc != res)
            {
                printf("Errado!\n");
                f += 1;
            }
            usleep(500000);
        } while (esc != res);
        if (esc == res)
        {
            v += 1;
            printf("\033[32mCorreto!\033[m\n");
            fflush(stdout);
            coin();
        }
        usleep(500000);
    }
}

//* função multiplicação
void mult()
{
    pegar_hora();
    srand(time(NULL));
    int n1, n2, res, esc, v = 0, f = 0, lim = 10;
    char input[10];
    system("clear");
    printf("\t\t\t   BEM VINDO AO MODO MULTIPLICAÇÃO\n");
    sleep(1);
    system("clear");
    printf("Digte 9999 para voltar\n");
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

        n1 = rand() % lim + 0;
        n2 = rand() % lim + 0;
        res = n1 * n2;
        do
        {
            system("clear");
            printf("Dificuldade: %d\nQuanto é %d * %d?\n>> ", v, n1, n2);
             //! le a entrada como string
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("erro na leitura!");
            continue;
        }
        //! converte para inteiro
        if (sscanf(input, "%d", &esc) != 1)
        {
            printf("Codigo invalido, utilize apenas numeros!");
            sleep(1);
            continue;
        }
            
            if (esc == 9999)
            {
                saida(hora_atual, "Multiplicação", v, f);

                return;
            }
            else if (esc != res)
            {
                printf("Errado!\n");
                f += 1;
            }
            usleep(500000);
        } while (esc != res);
        if (esc == res)
        {
            v += 1;
            printf("\033[32mCorreto!\033[m\n");
            fflush(stdout);
            coin();
        }
        usleep(500000);
    }
}

//* função divisão
void divis()
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

            // Converter para float
            esc = strtof(buffer, &endptr);

            // Verificar a conversão
            if (endptr == buffer)
            {
                printf("Entrada inválida! Use números decimais com ponto ou vírgula.\n");
                usleep(1000000);
                continue;
            }

            if (esc == 9999)
            {
                saida(hora_atual, "Divisão", v, f);
                return;
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

//* função de equações
// void equee()
// {
//     pegar_hora();
//     system("clear");
//     printf("\t\t\t   BEM VINDO AO MODO EQUAÇÃO\n");
//     sleep(1);
//     system("clear");
//     printf("Digte 9999 para voltar\n");
//     sleep(1);
//     system("clear");
//     srand(time(NULL));
//     int dificuldade = 0, min = 0, max = 10, v = 0, f = 0;
//     float resposta_usuario;
//     while (1)
//     {
//         if (dificuldade > 5)
//         {
//             max = 50;
//             min = 10;
//             if (dificuldade > 13)
//             {
//                 max = 100;
//                 min = 35;
//                 if (dificuldade > 25)
//                 {
//                     max = 100;
//                     min = 0;
//                 }
//             }
//         }

//         system("clear");

//         //! Gerar equação aleatória
//         int qtd_numeros = rand() % 3 + 2;
//         int numeros[qtd_numeros];
//         char operadores[qtd_numeros - 1];

//         //? Preenche números
//         for (int i = 0; i < qtd_numeros; i++)
//         {
//             numeros[i] = rand() % max + min;
//         }

//         // *Operadores
//         char ops[] = {'+', '-', '*', '/'};
//         for (int i = 0; i < qtd_numeros - 1; i++)
//         {
//             operadores[i] = ops[rand() % 4];
//         }

//         //*Mostrar equação
//         printf("Dificuldade: %d\nResolva: ", dificuldade);
//         for (int i = 0; i < qtd_numeros; i++)
//         {
//             printf("%d", numeros[i]);
//             if (i < qtd_numeros - 1)
//             {
//                 printf(" %c ", operadores[i]);
//             }
//         }
//         printf("\n");

//         //* Calcular o resultado correto
//         int resultado = numeros[0];

//         // resolver * , /
//         for (int i = 1; i < qtd_numeros; i++)
//         {
//             if (operadores[i - 1] == '*')
//             {
//                 resultado *= numeros[i];
//             }
//             else if (operadores[i - 1] == '/')
//             {
//                 if (numeros[i] == 0)
//                 {
//                     numeros[i] = 1;
//                 }
//                 resultado /= numeros[i];
//             }
//         }

//         //* resolver + , -
//         for (int i = 1; i < qtd_numeros; i++)
//         {
//             if (operadores[i - 1] == '+')
//             {
//                 resultado += numeros[i];
//             }
//             else if (operadores[i - 1] == '-')
//             {
//                 resultado -= numeros[i];
//             }
//         }

//         //* Resposta do usuário
//         do
//         {
//             system("clear");
//             printf("Dificuldade: %d\nResolva: ", dificuldade);
//             for (int i = 0; i < qtd_numeros; i++)
//             {
//                 printf("%d", numeros[i]);
//                 if (i < qtd_numeros - 1)
//                 {
//                     printf(" %c ", operadores[i]);
//                 }
//             }
//             printf("\n");
//             printf("Sua resposta: ");
//             scanf("%f", &resposta_usuario);

//             if (resposta_usuario == 9999)
//             {
//                 saida(hora_atual, "Equação", v, f);
//                 return;
//             }
//             else if (resposta_usuario != resultado)
//             {
//                 printf("Errado!\n");
//                 f += 1;
//             }
//             usleep(500000);
//         } while (resposta_usuario != resultado);

//         if (resposta_usuario == resultado)
//         {
//             v += 1;
//             dificuldade += 1;
//             printf("\033[32mCorreto!\033[m\n");
//             fflush(stdout);
//             coin();
//         }
//         usleep(500000);
//         system("clear");
//     }
// }

//* menu matematico
void menu_matematica()
{
    int modo;
    char input[10];
    while (1)
    {
        system("clear");
        printf("\t\t\t   BEM VINDO AO MODO MATEMÁTICA\n");
        sleep(1);
        system("clear");
        printf("\t\t\t    \033[33m[999 Sair, 998 Ajuda]\033[m\n\t\t        Digite um codigo de atividade: ");

         //! le a entrada como string
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("erro na leitura!");
            continue;
        }
        //! converte para inteiro
        if (sscanf(input, "%d", &modo) != 1)
        {
            printf("Codigo invalido, utilize apenas numeros!");
            sleep(1);
            continue;
        }
        switch (modo)
        {
        case 41:
            soma();
            break;
        case 42:
            sub();
            break;
        case 43:
            mult();
            break;
        case 44:
            divis();
            break;
        // case 45:
        //     equee();
        //     break;
        case 998:
            lista();
            break;
        case 999:
            printf("\t\t\t\t\033[35mSaindo");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                usleep(500000);
            }
            system("clear");
            printf("\033[m");
            sai();
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            sleep(1);
            system("clear");
            return;
        default:
            printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
    }
}

//* menu dos livros
void menu_livro()
{
    int lv;
    char input[10];
    int gab1[10] = {1, 2, 4, 1, 1, 4, 1, 3, 4, 1};
    int gab2[10] = {3, 4, 3, 4, 3, 1, 3, 1, 2, 4};
    while (1)
    {
        printf("\t\t\t   BEM VINDO AO MODO LIVRO\n");
        system("clear");
        sleep(1);
        system("clear");
        printf("\t\t\t   \033[33m[999 p/ voltar, 998 ajuda]\033[m\n\t\t\t   Digite o codigo do livro: ");

        //! le a entrada como string
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("erro na leitura!");
            continue;
        }
        //! converte para inteiro
        if (sscanf(input, "%d", &lv) != 1)
        {
            printf("Codigo invalido, utilize apenas numeros!");
            sleep(1);
            continue;
        }

        switch (lv)
        {
        case 31:
            livros(gab1, 0);
            break;
        case 32:
            livros(gab2, 1);
            break;
        case 998:
            lista();
            break;
        case 999:

            printf("\t\t\t\t\033[35mVoltando");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                usleep(70000);
            }
            system("clear");
            printf("\033[m");
            sai();
            printf("\033[32m\t\t\t\t   VOLTE SEMPRE!\033[m\n");
            sleep(1);
            system("clear");
            return;
            // break;
        default:
            printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
    }
    return;
}

//* livros de questões
void livros(int gabarito[10], int a)
{
    pegar_hora();
    FILE *arquivo = fopen("pontos.txt", "a");
    int mv = 0, que = 0, resp[10], cer = 0, err = 0, form[10];
    char nav;
    char *cores[] = {
        "\033[31m", // Vermelho
        "\033[32m", // Verde
        "\033[33m", // Amarelo
        "\033[34m"  // Azul
    };
    char *livros[] = {
        "Hardware",
        "Software"};

    printf("\n\t\t   Utilize o livro \033[35m%s\033[m para visualizar as questoes!\n", livros[a]);
    sleep(3);

    while (1)
    {
        system("clear");
        printf("\t\033[1;33mQuestão %d [a/d para mover q para sair, espaço para confirmar]\033[m\n\n", que + 1);
        for (int i = 0; i < 4; i++)
        {
            if (i == mv)
                printf("\t\a|| %s\u2588\u2588\033[m ||\t", cores[i]); // destaque reverso
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
        else if (nav == ' ')
        {
            resp[que] = mv + 1;
            que += 1;
        }
        else if (nav == 'q')
        {
            saida(hora_atual, "Livro", cer, err);
            return;
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
    fprintf(arquivo, "Nome: %s\nData: %s\n", nome, hora_atual);

    //* imprimir respostas
    for (int j = 0; j < 10; j++)
    {
        if (form[j] == 1)
        {
            fprintf(arquivo, "%d ", resp[j]);
            printf("\033[32m%d \033[m", resp[j]);
        }
        else
        {
            fprintf(arquivo, "%d ", resp[j]);
            printf("\033[31m%d \033[m", resp[j]);
        }
    }
    fprintf(arquivo, "\n");
    puts("");

    //* imprimir gabarito
    for (int j = 0; j < 10; j++)
    {
        fprintf(arquivo, "%d ", gabarito[j]);
        printf("\033[32m%d \033[m", gabarito[j]);
    }
    puts("\n");
    printf("\033[32mAcertos: %d \033[31mErros %d\n\033[m", cer, err);
    fprintf(arquivo, "Acertos: %d Erros %d\n", cer, err);
    getchar();
    printf("\nAperte qualquer tecla para continuar......");
    getchar();
    fclose(arquivo);
}

//* lista de ajuda
void lista()
{
    system("clear");
    printf("\033[35mComandos principais\033[m\n\033[33m999 - SAIR\n998 - LISTA DE COMANDOS\n997 - PONTUAÇÃO\033[m\n\n\033[35mNavegação\033[m\n\033[33mq - SAIR DA ATIVIDADE(Livros)\n9999 - SAIR DA ATIVIDADE(Matematica)\na - MOVER PARA ESQUERDA\nd - MOVER PARA DIREITA\nSpace - SELECIONAR OPÇÂO\nEnter - CONFIRMAR OPÇÂO\033[m\n\n\033[35mMenus\033[m\n\033[33m1 - MENU DE LIVROS\n2 - MENU DE MATEMATICA\033[m\n\n\033[35mLivros\n\033[33m31 - LIVRO HARDWARE\n32 - LIVRO SOFTWARE\033[m\n\n\033[35mModos matemáticos\033[m\n\033[33m41 - SOMA\n42 - SUBTRAÇÃO\n43 - MUTIPLICAÇÃO\n44 - DIVISÃO\033[m");
    getchar();
    printf("\nTecle enter para continuar...");
    getchar();
    system("clear");
}

//* menu_principal
void menu_principal()
{
    char mensagem[] = "\t\t\tBEM VINDO AO PENSE MAIS OU MENOS";
    char input[10];
    int n = strlen(mensagem), atv;

    // mensagem de boas vindas
    for (int i = 0; i < n; i++)
    {
        printf("%c", mensagem[i]);
        fflush(stdout);
        usleep(10000);
    }
    system("clear");
    for (int i = 0; i < 7; i++)
    {
        system("clear");
        printf("\033[7;3%dm%s\033[m", i, mensagem);
        fflush(stdout);
        usleep(100000);
    }
    //! musica de boas vindas
    music();
    system("clear");
    while (1)
    {
        printf("\t\t\t\033[33m[999 Sair, 998 Ajuda, 997 placar]\033[m\n\t\t        Digite um codigo de atividade: \033[7;31m");

         //! le a entrada como string
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("erro na leitura!");
            continue;
        }
        //! converte para inteiro
        if (sscanf(input, "%d", &atv) != 1)
        {
            printf("Codigo invalido, utilize apenas numeros!");
            sleep(1);
            continue;
        }
        
        printf("\033[m");
        if (atv == 999)
        {
            printf("\033[m");
            printf("\t\t\t\t\033[35mSaindo");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                usleep(500000);
            }
            system("clear");
            printf("\033[m");
            sai();
            printf("\033[32m\n\t\t\t\tVOLTE SEMPRE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
        switch (atv)
        {
        case 1:
            menu_livro();
            break;
        case 2:
            menu_matematica();
            break;
        case 997:
            placar();
            break;
        case 998:
            lista();
            break;
        default:
            printf("\t\t\t\033[31mCODIGO INVÁLIDO, TENTE NOVAMENTE!\033[m\n");
            sleep(1);
            system("clear");
            break;
        }
    }
}

//* Função principal
int main()
{
    FILE *arquivo = fopen("pontos.txt", "a");
    system("clear");
    barra();
    usleep(50000);
    entra();
    system("clear");
    printf("NOME: ");
    fgets(nome, 30, stdin);
    fprintf(arquivo, "| ===============NOME============== |\n< %s", nome);
    fclose(arquivo);
    system("clear");
    menu_principal();
}