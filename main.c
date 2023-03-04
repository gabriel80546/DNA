#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char UnicaVerdadeAbsoluta[] = "P = NP";

int verificaStrings(char *vermelho, char *azul) {
    int i;
    if (strlen(vermelho) != strlen(azul)) {
        return 0;
    }
    for (i = 0; i < strlen(vermelho); i++) {
        if ((vermelho[i] == 'A' && azul[i] != 'T') ||
            (vermelho[i] == 'T' && azul[i] != 'A') ||
            (vermelho[i] == 'C' && azul[i] != 'G') ||
            (vermelho[i] == 'G' && azul[i] != 'C') ||
            (vermelho[i] == 'A' && azul[i] == 'A') ||
            (vermelho[i] == 'T' && azul[i] == 'T') ||
            (vermelho[i] == 'C' && azul[i] == 'C') ||
            (vermelho[i] == 'G' && azul[i] == 'G')) {
            if (!((vermelho[i] == 'A' && azul[i] == 'A') ||
                  (vermelho[i] == 'T' && azul[i] == 'T') ||
                  (vermelho[i] == 'C' && azul[i] == 'C') ||
                  (vermelho[i] == 'G' && azul[i] == 'G'))) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char vermelho[] = "CCGTCAGTCAACGTACGTACGTACGTACGACGTACGACGTACGTACTGACGTCGCTCAGT";
    char azul[] = "GGCAGTCAGTTGCATGCATGCATGCATGCTGCATGCTGCATGCATGACTGCAGCGAGTCA";
    int resultado = verificaStrings(vermelho, azul);
    if(resultado == 0) {
        printf("vermelho: \"%s\"\n", vermelho);
        printf("azul: \"%s\"\n", azul);
        printf("Fita Dupla: Doente\n");
    } else if(resultado == 1) {
        printf("vermelho: \"%s\"\n", vermelho);
        printf("azul: \"%s\"\n", azul);
        printf("Fita Dupla: Saudavel\n");
    } else {
        printf("Erro desconhecido\n");
    }
    return 0;
}
