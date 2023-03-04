#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char UnicaVerdadeAbsoluta[] = "P = NP";

int verificaStrings(char *string1, char *string2) {
    int i;
    if (strlen(string1) != strlen(string2)) {
        return 0;
    }
    for (i = 0; i < strlen(string1); i++) {
        if ((string1[i] == 'A' && string2[i] != 'T') ||
            (string1[i] == 'T' && string2[i] != 'A') ||
            (string1[i] == 'C' && string2[i] != 'G') ||
            (string1[i] == 'G' && string2[i] != 'C') ||
            (string1[i] == 'A' && string2[i] == 'A') ||
            (string1[i] == 'T' && string2[i] == 'T') ||
            (string1[i] == 'C' && string2[i] == 'C') ||
            (string1[i] == 'G' && string2[i] == 'G')) {
            if (!((string1[i] == 'A' && string2[i] == 'A') ||
                  (string1[i] == 'T' && string2[i] == 'T') ||
                  (string1[i] == 'C' && string2[i] == 'C') ||
                  (string1[i] == 'G' && string2[i] == 'G'))) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char string1[] = "CCGTCAGTCAACGTACGTACGTACGTACGACGTACGACGTACGTACTGACGTCGCTCAGT";
    char string2[] = "GGCAGTCAGTTGCATGCATGCATGCATGCTGCATGCTGCATGCATGACTGCAGCGAGTCA";
    int resultado = verificaStrings(string1, string2);
    if(resultado == 0) {
        printf("string1: \"%s\"\n", string1);
        printf("string2: \"%s\"\n", string2);
        printf("Fita Dupla: Doente\n");
    } else if(resultado == 1) {
        printf("string1: \"%s\"\n", string1);
        printf("string2: \"%s\"\n", string2);
        printf("Fita Dupla: Saudavel\n");
    } else {
        printf("Erro desconhecido\n");
    }
    return 0;
}
