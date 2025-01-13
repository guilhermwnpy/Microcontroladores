void main()
{
 unsigned char J = 1; //Inicializamos J = 1.

 ANSEL = 0; // Configura os pinos AN (analógicos) como digitais
 ANSELH = 0;

 C1ON_bit = 0; // Desabilita os comparadores
 C2ON_bit = 0;

 TRISB = 0; //Toda a porta B será saída
 PORTB = 0; //Toda a porta B igual a 0

 while(1) //laço infinito
 {

 PORTB = J; // PORTB recebe o valor de J = liga o led menos significativo
 J = J << 1; //Desloca J (os bits uma casa para esquerda)
 
 if(J == 0) J = 1; //Se J é igual a 0, novamente se faz J = 1.
 delay_ms(200); //tempo de 1 segundo
 }
}