const fundos = [
    './colors/pexels-pixabay-414144.jpg',
    './colors/pexels-pixabay-459203.jpg',
];

let atual = 0;
const botao = document.getElementById('md_fundo')

botao.addEventListener('click', function() {
    atual = atual === 0 ? 1 : 0;

    document.body.style.backgroundImage = `url('${fundos[atual]}')`;
});

