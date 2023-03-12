# Detector de fita dupla de DNA

Este é um programa simples escrito em C que verifica se duas sequências de DNA fornecidas são complementares uma à outra, ou seja, se elas podem se unir para formar uma fita dupla de DNA saudável. Se as sequências não são complementares, então é provável que a fita dupla esteja doente ou defeituosa.

## Como usar

1. Clone este repositório em sua máquina local usando o comando `git clone https://github.com/gabriel80546/DNA.git`
2. Compile o código-fonte usando o Makefile fornecido: `make`
3. Execute o arquivo executável gerado: `./dna`

## Objetivos do código.

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

## Licença

Este projeto é licenciado sob a licença [WTFPL](http://www.wtfpl.net/). Veja o arquivo `LICENSE` para obter mais detalhes.
