#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\a");
        fflush(stdout); // força a saída imediata
        sleep(1);
    }
    return 0;
}