#!/usr/bin/env node

const str1 = "CCGTCAGTCAACGTACGTACGTACGTACGACGTACGACGTACGTACTGACGTCGCTCAGT";
const str2 = "GGCAGTCAGTTGCATGCATGCATGCATGCTGCATGCTGCATGCATGACTGCAGCGAGTCA";
var saida = "";


for(var i = 0; i < str1.length + str2.length; i++) {
    saida += str1.charAt(i);
    saida += str2.charAt(i);
}

console.log(`saida: "${saida}"`);
