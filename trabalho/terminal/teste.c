#include <alsa/asoundlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Tabela de frequências (oitava 4)
#define C4 261.63
#define C4S 277.18
#define D4 293.66
#define D4S 311.13
#define E4 329.63
#define F4 349.23
#define F4S 369.99
#define G4 392.00
#define G4S 415.30
#define A4 440.00
#define A4S 466.16
#define B4 493.88
// Definições das notas (3ª oitava)
#define C3 130.81
#define C3S 138.59
#define D3 146.83
#define D3S 155.56
#define E3 164.81
#define F3 174.61
#define F3S 185.00
#define G3 196.00
#define G3S 207.65
#define A3 220.00
#define A3S 233.08
#define B3 246.94

// Definições das notas (5ª oitava)
#define C5 523.25
#define C5S 554.37
#define D5 587.33
#define D5S 622.25
#define E5 659.25
#define F5 698.46
#define F5S 739.99
#define G5 783.99
#define G5S 830.61
#define A5 880.00
#define A5S 932.33
#define B5 987.77

// Frequências da 6ª oitava
#define C6 1046.50
#define C6S 1108.73
#define D6 1174.66
#define D6S 1244.51
#define E6 1318.51
#define F6 1396.91
#define F6S 1479.98
#define G6 1567.98
#define G6S 1661.22
#define A6 1760.00
#define A6S 1864.66
#define B6 1975.53

void play_tone(snd_pcm_t *pcm, float freq, int duration_ms)
{
    int samples = (duration_ms * 44100) / 1000;
    short buffer[samples];

    // Gera o tom
    for (int i = 0; i < samples; i++)
    {
        buffer[i] = 32760 * sin(2 * 3.14159 * freq * i / 44100);
    }

    // Toca o som
    snd_pcm_writei(pcm, buffer, samples);
}

int main()
{
    snd_pcm_t *pcm;
    int err;

    // Abre o dispositivo de áudio
    if ((err = snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0)
    {
        printf("Erro ao abrir dispositivo: %s\n", snd_strerror(err));
        return 1;
    }

    // Configuração do PCM
    snd_pcm_set_params(pcm,
                       SND_PCM_FORMAT_S16_LE,
                       SND_PCM_ACCESS_RW_INTERLEAVED,
                       1,       // Mono
                       44100,   // Sample rate
                       1,       // Permitir ajuste
                       500000); // Tamanho do buffer

    play_tone(pcm, G6S, 400);
    play_tone(pcm, D6S, 400);
    play_tone(pcm, G5S, 400);
    usleep(50000);
    play_tone(pcm, A5S, 1000);


    // Fecha o dispositivo
    snd_pcm_close(pcm);
    return 0;
}
