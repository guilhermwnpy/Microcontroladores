void main()
{
 //declaracao de variavel vetor num, onde cada valor representa o bit (pino)
 //da porta B que será ligada, exemplo 0x81 = 10000001, 0x42=01000010,...
// unsigned char num[8] = {0x81,0x42, 0x24, 0x18, 0x24, 0x42};
 unsigned char num[8] = {0b00000011, 0b00001100, 0b00110000, 0b11000000, 0b00110000, 0b00001100};
 int i;
 ANSEL = 0; // Configura os pinos AN (analógicos) como digitais
 ANSELH = 0;
 C1ON_bit = 0; // Desabilita os comparadores
 C2ON_bit = 0;
 TRISB = 0; //Toda a porta B será saída
 PORTB = 0; //Toda a porta B igual a 0
 while(1) //laço infinito
 {
 for(i=0; i<6; i++) //quantidade de elementos do vetor num, vai de 0 a 3
 {
 PORTB = num[i]; // PORTB recebe o valor de num, elemento 0 = 0x01
 delay_ms(1000); //tempo de 1 segundo
 } //fim do for
 } //fim do while(1)
} //fim do main