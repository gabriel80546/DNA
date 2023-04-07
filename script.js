function enviarDados(tipo, valor) {
    if (tipo === "dna") {
        document.querySelector('#resultado').innerText = `dna: ${valor}`;
    } else if (tipo === "rna") {
        document.querySelector('#resultado').innerText = `rna: ${valor}`;
    } else {
        document.querySelector('#resultado').innerText = `ERRO`;
    }
}
