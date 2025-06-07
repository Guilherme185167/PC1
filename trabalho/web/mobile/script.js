  // Pega os elementos
    const images = document.querySelectorAll('.image');
    const btn = document.querySelector('.btn');
    let currentIndex = 0; // Começa na primeira imagem (índice 0)

    // Esconde todas as imagens, exceto a ativa
    function updateSlide() {
        images.forEach(img => img.classList.remove('active'));
        images[currentIndex].classList.add('active');
    }

    // Avança para a próxima imagem
    btn.addEventListener('click', () => {
        currentIndex++;
        if (currentIndex >= images.length) currentIndex = 0; // Volta ao início
        updateSlide();
    });

    // Inicia mostrando a primeira imagem
    updateSlide();


    
    // ./img/animais.png 
    // ./img/software.png 
    // ./img/BCO.47133e05-ffec-4b9d-b3f3-33f16216ad55.png 
    // ./img/embreve.png 

    // ./img/blender.png 
    // ./img/cad.png 
    // ./img/docker.png 
    // ./img/node.png 
    // ./img/obs.png 
    // ./img/photoshop.jpeg 
    // ./img/figma.png 
    // ./img/power.jpeg 
    // ./img/vlc.jpeg 
    // ./img/rar.jpeg 
    
    // ./img/cooler.jpeg 
    // ./img/cpu.jpeg 
    // ./img/gpu.jpeg 
    // ./img/hd.jpeg 
    // ./img/lan.jpeg 
    // ./img/placamae.jpeg 
    // ./img/psu.jpeg 
    // ./img/ram.jpeg 
    // ./img/ssd.png 
    // ./img/zoio.jpeg