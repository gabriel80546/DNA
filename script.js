function enviarDados(tipo, valor) {
    document.querySelector('#resultado').innerText = "";
    if (tipo === "dna") {
        if(valor.length != 0) {
            var saida = valor.split(" ");
            if(saida.length >= 2) {
                main(saida[0], saida[1]);
            } else {
                document.querySelector('#resultado').innerText = "é necessário informar duas fitas";
            }
        } else {
            document.querySelector('#resultado').innerText = "use \"CCGT GGCA\" como exemplo";
        }
        // document.querySelector('#resultado').innerText = `dna: ${valor}`;
    } else if (tipo === "rna") {
        if(valor.length != 0) {
            var saida = valor.split(" ");
            if(saida.length >= 2) {
                main(saida[0], saida[1]);
            } else {
                document.querySelector('#resultado').innerText = "é necessário informar duas fitas";
            }
        } else {
            document.querySelector('#resultado').innerText = "use \"CCGT GGCA\" como exemplo";
        }
        // document.querySelector('#resultado').innerText = `rna: ${valor}`;
    } else {
        document.querySelector('#resultado').innerText = `ERRO`;
    }
}



