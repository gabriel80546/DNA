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

int main(int argc, char *argv[]) {
    char *vermelho, *azul, *junta;
    int i, j = 0;

    if (argc < 3) {
        printf("Erro: é necessário informar duas strings na linha de comando\n");
        return 1;
    }

    vermelho = (char *) malloc((strlen(argv[1]) + 1) * sizeof(char));
    if (vermelho == NULL) {
        printf("Erro: não foi possível alocar memória para vermelho\n");
        return 1;
    }
    azul = (char *) malloc((strlen(argv[2]) + 1) * sizeof(char));
    if (azul == NULL) {
        printf("Erro: não foi possível alocar memória para azul\n");
        free(vermelho);
        return 1;
    }

    // Aloca memória para a string 'junta'
    junta = (char *) malloc(((strlen(argv[1]) + 1) + (strlen(argv[2]) + 1)) * sizeof(char));
    if (junta == NULL) {
        printf("Erro: não foi possível alocar memória para 'junta'\n");
        return 1;
    }

    // Percorre as strings 'argv[1]' e 'argv[2]' e junta seus caracteres em 'junta'
    for(i = 0; i < strlen(argv[1]) || i < strlen(argv[2]); i++) {
        if (i < strlen(argv[1])) {
            junta[j++] = argv[1][i];
        }
        if (i < strlen(argv[2])) {
            junta[j++] = argv[2][i];
        }
    }
    junta[j] = '\0';
    printf("%s\n", junta);

    strcpy(vermelho, argv[1]);
    strcpy(azul, argv[2]);

    // char vermelho[] = "CCGTCAGTCAACGTACGTACGTACGTACGACGTACGACGTACGTACTGACGTCGCTCAGT";
    // char azul[] = "GGCAGTCAGTTGCATGCATGCATGCATGCTGCATGCTGCATGCATGACTGCAGCGAGTCA";
    int resultado = verificaStrings(vermelho, azul);
    if(resultado == 0) {
        printf("vermelho: \"%s\"\n", vermelho);
        printf("azul:     \"%s\"\n", azul);
        printf("junta: \"%s\"\n", junta);
        printf("SMILES: ?????\n");
        printf("Fita Dupla: Doente\n");
    } else if(resultado == 1) {
        printf("vermelho: \"%s\"\n", vermelho);
        printf("azul:     \"%s\"\n", azul);
        printf("junta: \"%s\"\n", junta);
        printf("SMILES: ?????\n");
        printf("Fita Dupla: Saudavel\n");
    } else {
        printf("Erro desconhecido\n");
    }

    free(vermelho);
    free(azul);
    free(junta);

    return 0;
}
