/*****************************************************************************
Exemplo 9
Mostrar uma sequência de números de 0 a 9 em um display de 7 segmentos ânodo
comum. Estes números deverão ser apresentados com um intervalo de tempo de 0,5
seg aproximadamente. Levar em consideração um arranjo de 4 displays ânodo comum.
Autor:Prof. Antonio Ramirez Hidalgo
 ******************************************************************************/

#define DISPLAY1 PORTD.B0 //Pode ser também PORTD.RD0, para selecionar o display1
#define DISPLAY2 PORTD.B1 //Pode ser também PORTD.RD1, para selecionar o display2
#define DISPLAY3 PORTD.B2 //Pode ser também PORTD.RD2, para selecionar o display3
#define DISPLAY4 PORTD.B3 //Pode ser também PORTD.RD3, para selecionar o display4

//Rotina Principal
void main() {
    // Números de 0 a 9 nos displays anodo comum
    unsigned int num0_9[10] = {192,249,164,176,153,146,131,248,128,152}; // valores em decimal
    // unsigned int num0_9[10]={0xC0,0XF9,0XA4,0XB0,0X99,0X92,0X83,0XF8,0X80,0X98}; // valores em hexadecimal
    unsigned int segmento;
    int i = 0;                 // variável utilizada para reiniciar a contagem

    // Configuração dos registradores
    ANSEL = 0;                 // Configura os pinos AN (analógicos) como digitais
    ANSELH = 0;
    C1ON_bit = 0;              // Desabilita os comparadores
    C2ON_bit = 0;
    TRISB = 0;                 // Toda a porta B será saída
    PORTB = 0;                 // Toda a porta B igual a 0
    TRISD0_bit = 0;            // pino 0 da Porta D como saída
    TRISD1_bit = 0;            // pino 1 da Porta D como saída
    TRISD2_bit = 0;            // pino 2 da Porta D como saída
    TRISD3_bit = 0;            // pino 3 da porta D como saída

    // Valores iniciais
    PORTB = 0xffff;            //limpa a porta B

    // Desligamos todos os displays já que temos transistores PNP
    DISPLAY1 = 1;
    DISPLAY2 = 1;
    DISPLAY3 = 1;
    DISPLAY4 = 1;

    // Ligamos um dos displays
    // DISPLAY1 = 1;
    DISPLAY2 = 0;
    // DISPLAY3 = 1;
    // DISPLAY4 = 1;
    while (1) {
        for (i = 0; i < 10; i++) {
            segmento = num0_9[i];
            PORTB = segmento;
            Delay_ms(500);
        } // fim do for
    } // fim do while
} // fim do main
