// objetivo 1: testar a fita de dna do usuário.
// objetivo 2: sintetizar a fita de RNA via código SMILES.
// objetivo 3: testar fita de RNA sintetizada (trinca de RNA).
// objetivo 4: transformar a fita de RNA em RNA 3D via construção de um editor molecular.
// Objetivo 5: Visualizar o RNA 3D no editor molecular para encontrar possíveis danos na fita --- caso ela nao tenha sido saudavel no teste do objetivo 3.
// Objetivo 6: Calcular as cargas de hirshfeld sobre cada átomo da fita.
// Objetivo 7: faz uma conta de índices de reatividade Fukui condensados aos Átomos (IFCA) e mapas de cor para identificar a região de ataque eletrofílico externo ou nucleofílico externo ou radicalar (f+ = nucleofílico, f- eletrofílico, f0 = radicalar).
// Objetivo 8: identificar padrões de reatividade possíveis danos na fita de RNA sintetizado.
// Objetivo 9: Duplicar a Fita de RNA sintetizada em 2 FItas duplas de DNA (fase de síntese)
// Objetivo 10: Calcular IFCA das fitas 1 e 2 do objetivo 9.
// Objetivo 11: identificar possíveis danos nas fitas 1 e 2 via identificação nos mapas de cor.
// Objetivo 12: Por fim, criar padronização de probabilidade de cancer do usuário.




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
    char* smiles = (char*) malloc((strlen(dna)*3 + 1) * sizeof(char));
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
        if(resultado == 0) {
          printf("Fita Dupla: Doente\n");
        } else {
          printf("Fita Dupla: Saudavel\n");
        }
    } else {
        printf("Erro desconhecido\n");
    }

    free(vermelho);
    free(azul);
    free(junta);

    return 0;
}
