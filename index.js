#!/usr/bin/env node
const dna = `1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
2 1 3 4
1 2 4 3
1 2 3 4
2 1 3 4
1 2 3 4`;
const novo = dna.split("").map(n => {
    if (n === '1') {
        return "A";
    } else if (n === '2') {
        return "C";
    } else if (n === '3') {
        return "G";
    } else if (n === '4') {
        return "T";
    } else {
        return " ";
    }
});
const saida = novo.filter((item) => item != ' ').join("");
// console.log(`novo, mais, typeof(novo)`, novo, typeof(novo));
console.log(saida);
