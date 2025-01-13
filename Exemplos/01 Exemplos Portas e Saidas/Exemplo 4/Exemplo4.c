void main()
{
 //declaracao de variavel vetor num, onde cada valor representa o bit (pino)
 //da porta B que será ligada, exemplo 0x01 = 00000001, 0x02=00000010,...
 unsigned char num[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
 int i;

 ANSEL = 0; // Configura os pinos AN (analógicos) como digitais
 ANSELH = 0;
 C1ON_bit = 0; // Desabilita os comparadores
 C2ON_bit = 0;
 TRISB = 0; //Toda a porta B será saída
 PORTB = 0; //Toda a porta B igual a 0
 while(1) //laço infinito
 {
 for(i=0; i<8; i++) //quantidade de elementos do vetor num, aqui vai de 0 a 7
 {
 PORTB = num[i]; // PORTB recebe o valor de num, elemento 0 = 0x01
 delay_ms(20); //tempo de 1 segundo
 } //fim do for
 } //fim do while(1)
} //fim do main