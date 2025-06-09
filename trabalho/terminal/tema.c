#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// Função para iniciar a trilha sonora em segundo plano
pid_t iniciar_trilha_sonora(const char *arquivo_mp3) {
    pid_t pid = fork(); // Cria um processo filho

    if (pid == 0) { // Processo filho (executa o player)
        setsid(); // Isola o processo para evitar que seja encerrado com o programa principal
        execlp("mpg123", "mpg123", "-q", arquivo_mp3, NULL); // Executa o mpg123
        perror("Erro ao executar mpg123");
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) { // Erro no fork()
        // perror("Erro ao criar processo filho");
        return -1;
    }

    return pid; // Retorna o PID do processo do player
}

// Função para parar a trilha sonora
void parar_trilha_sonora(pid_t pid) {
    if (pid > 0) {
        kill(pid, SIGTERM); // Envia um sinal para encerrar o player
        waitpid(pid, NULL, 0); // Espera o processo terminar
    }
}

int main() {
    // Inicia a trilha sonora (substitua "trilha.mp3" pelo seu arquivo)
    pid_t player_pid = iniciar_trilha_sonora("trilha.mp3");
    
    if (player_pid == -1) {
        // printf("Erro ao iniciar a trilha sonora.\n");
        return 1;
    }

    // printf("Trilha sonora iniciada (PID: %d).\n", player_pid);

    //Simulação do programa principal
    for (int i = 1; i <= 20; i++) {
        //printf("Executando passo %d/10...\n", i);
        sleep(1);
    }

    // Encerra a trilha sonora (opcional)
    parar_trilha_sonora(player_pid);
    // printf("Trilha sonora encerrada.\n");

    return 0;
}