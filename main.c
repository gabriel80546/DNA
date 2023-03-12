// Fas



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

char* dnaToSmiles(char* dna) {
    char* smiles = (char*) malloc((strlen(dna)*3 + 1) * sizeof(char)); /* aloca memória para a string SMILES */
    if (smiles == NULL) {
        printf("Erro: não foi possível alocar memória para a string SMILES\n");
        return NULL;
    }
    int i, j = 0;
    for(i = 0; i < strlen(dna); i++) {
        if (dna[i] == 'A') {
            strcat(smiles, "UUA");
            j += 3;
        } else if (dna[i] == 'C') {
            strcat(smiles, "UGU");
            j += 3;
        } else if (dna[i] == 'G') {
            strcat(smiles, "GUA");
            j += 3;
        } else if (dna[i] == 'T') {
            strcat(smiles, "UAU");
            j += 3;
        }
    }
    return smiles;
}

/* TODO */
/* TAREFA */
/* TESTAR A TRINCA DE RNA */

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

    junta = (char *) malloc(((strlen(argv[1]) + 1) + (strlen(argv[2]) + 1)) * sizeof(char));
    if (junta == NULL) {
        printf("Erro: não foi possível alocar memória para 'junta'\n");
        return 1;
    }

    for(i = 0; i < strlen(argv[1]) || i < strlen(argv[2]); i++) {
        if (i < strlen(argv[1])) {
            junta[j++] = argv[1][i];
        }
        if (i < strlen(argv[2])) {
            junta[j++] = argv[2][i];
        }
    }
    junta[j] = '\0';

    strcpy(vermelho, argv[1]);
    strcpy(azul, argv[2]);

    /* char vermelho[] = "CCGTCAGTCAACGTACGTACGTACGTACGACGTACGACGTACGTACTGACGTCGCTCAGT"; */
    /* char azul[] = "GGCAGTCAGTTGCATGCATGCATGCATGCTGCATGCTGCATGCATGACTGCAGCGAGTCA"; */
    printf("%s\n", junta);
    int resultado = verificaStrings(vermelho, azul);
    if(resultado == 0 || resultado == 1) {
        printf("vermelho: \"%s\"\n", vermelho);
        printf("azul:     \"%s\"\n", azul);
        printf("junta: \"%s\"\n", junta);
        printf("SMILES: \"%s\"\n", dnaToSmiles(junta));
        printf("SMILES: ?????\n");
        printf("Fita Dupla: Doente\n");
    } else {
        printf("Erro desconhecido\n");
    }

    free(vermelho);
    free(azul);
    free(junta);

    return 0;
}
