/*****************************************************************************
Exemplo 7
=========
Mostrar uma sequência de números de 0 a 9 em um display de 7 segmentos catodo
comum.
Estes números deverão ser apresentados com um intervalo de tempo de 0,5 seg
aproximadamente.
Autor: Prof. Antonio Ramirez Hidalgo
Data:
Arquivo:
Microcontrolador: PIC16F887
 ******************************************************************************/
void main() {
    // Declaração das variáveis
    // Números de 0 a 9 nos display catodo comum
    unsigned int num0_9[10] = {63,6,91,79,102,109,124,7,127,103};
    // unsigned int num0_9[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67};
    int i = 0;                 // variável utilizada para reiniciar a contagem
    ANSEL = 0;                 // Configura os pinos AN (analógicos) como digitais
    ANSELH = 0;
    C1ON_bit = 0;              // Desabilita os comparadores
    C2ON_bit = 0;
    TRISB = 0;                 // Toda a porta B será saída
    PORTB = 0;                 // Toda a porta B igual a 0
    while (1)                  // laço infinito
    {
        for (i = 0; i < 10; i++) {
            PORTB = num0_9[i];
            Delay_ms(500);
        } //fim do for
    } //fim do while(1)
} //fim do main