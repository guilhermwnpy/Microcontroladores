void main() {
 unsigned char num = 0x0F; //Declaramos a variável num como hexadecimal, onde 0F = 00001111 (binário)
 ANSEL = 0; // Configura os pinos AN (analógicos) como digitais
 ANSELH = 0;
 C1ON_bit = 0; // Desabilita os comparadores
 C2ON_bit = 0;
 TRISB = 0; //Toda a porta B será saída
 PORTB = 0; //Toda a porta B igual a 0
 for(;;) //laço infinito
 {
 PORTB = num; //PORTB recebe o valor de num = b00001111, liga os 4 leds menos significativos
 }
}
