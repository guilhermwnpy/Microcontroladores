void main() {
 ANSEL = 0; // Configura os pinos AN (analógicos) como digitais
 ANSELH = 0;
 C1ON_bit = 0; // Desabilita os comparadores
 C2ON_bit = 0;
 TRISB = 0; //Toda a porta B será saída
 PORTB = 0; //Toda a porta B igual a 0
 while(1) //laço infinito
 {
 PORTB = 0XFF; //PORTB recebe o valor de OXFF
 delay_ms(1000); //atraso de 1 segundo
 PORTB = 0; //PORTB recebe o valor de O
 delay_ms(1000); //atraso de 1 segundo
 }
}
