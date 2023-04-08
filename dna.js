function verificaStrings(vermelho, azul) {
    if (vermelho.length !== azul.length) {
        return false;
    }
    for (let i = 0; i < vermelho.length; i++) {
        if ((vermelho[i] === 'A' && azul[i] !== 'T') ||
            (vermelho[i] === 'T' && azul[i] !== 'A') ||
            (vermelho[i] === 'C' && azul[i] !== 'G') ||
            (vermelho[i] === 'G' && azul[i] !== 'C') ||
            (vermelho[i] === 'A' && azul[i] === 'A') ||
            (vermelho[i] === 'T' && azul[i] === 'T') ||
            (vermelho[i] === 'C' && azul[i] === 'C') ||
            (vermelho[i] === 'G' && azul[i] === 'G')) {
            if (!((vermelho[i] === 'A' && azul[i] === 'A') ||
                (vermelho[i] === 'T' && azul[i] === 'T') ||
                (vermelho[i] === 'C' && azul[i] === 'C') ||
                (vermelho[i] === 'G' && azul[i] === 'G'))) {
                return false;
            }
        }
    }
    return true;
}

function dnaToSmiles(dna) {
    let smiles = "";
    for(let i = 0; i < dna.length; i++) {
        if (dna[i] === 'A') {
            smiles += "UUA";
        } else if (dna[i] === 'C') {
            smiles += "UGU";
        } else if (dna[i] === 'G') {
            smiles += "GUA";
        } else if (dna[i] === 'T') {
            smiles += "UAU";
        }
    }
    return smiles;
}

/* TODO */
/* TAREFA */
/* TESTAR A TRINCA DE RNA */

// const args = process.argv.slice(2);
// if (args.length < 2) {
//     document.querySelector('#resultado').innerText += ("Erro: é necessário informar duas strings na linha de comando");
//     process.exit(1);
// }
function main(vermelho, azul) {
    if(vermelho === undefined) {
        document.querySelector('#resultado').innerText = "Fita vermelha com problema indefinido";
        return;
    } else if(azul === undefined) {
        document.querySelector('#resultado').innerText = "Fita azul com problema indefinido";
        return;
    }
    // const [vermelho, azul] = args;


    // const junta = vermelho + azul;
    let junta = new Array(vermelho.length + 1 + azul.length + 1);
    if (!junta) {
        console.log("Erro: não foi possível alocar memória para 'junta'");
        return 1;
    }

    let j = 0;
    for (let i = 0; i < vermelho.length || i < azul.length; i++) {
        if (i < vermelho.length) {
            junta[j++] = vermelho[i];
        }
        if (i < azul.length) {
            junta[j++] = azul[i];
        }
    }
    junta = junta.join("");





    document.querySelector('#resultado').innerText = "";
    document.querySelector('#resultado').innerText += (`junta: ${junta}`);
    const resultado = verificaStrings(vermelho, azul);
    if(resultado === false || resultado === true) {
        document.querySelector('#resultado').innerText += (`\nvermelho: "${vermelho}"`);
        document.querySelector('#resultado').innerText += (`\nazul:     "${azul}"`);
        document.querySelector('#resultado').innerText += (`\njunta: "${junta}"`);
        document.querySelector('#resultado').innerText += (`\nSMILES: "${dnaToSmiles(junta)}"`);
        if(resultado === false) {
            document.querySelector('#resultado').innerText += ("\nFita Dupla: Doente");
        } else {
            document.querySelector('#resultado').innerText += ("\nFita Dupla: Saudável");
        }
    } 
}