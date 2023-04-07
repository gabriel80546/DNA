function enviarDados(tipo, valor) {
    if (tipo === "dna") {
        document.querySelector('#resultado').innerText = `dna: ${valor}`;
    } else if (tipo === "rna") {
        document.querySelector('#resultado').innerText = `rna: ${valor}`;
    } else {
        document.querySelector('#resultado').innerText = `ERRO`;
    }
}

fetch('webasmDna.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
    // Atribui as funções do módulo WebAssembly a variáveis JavaScript
    const add = results.instance.exports.add;
    const subtract = results.instance.exports.subtract;
    
    // Usa as funções em sua página da web
    alert(`UnicaVerdadeAbsoluta: ${UnicaVerdadeAbsoluta}`); // 5
    // console.log(subtract(5, 3)); // 2
});
