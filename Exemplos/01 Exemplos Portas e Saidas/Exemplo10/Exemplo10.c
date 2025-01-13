#define DISPLAY1 PORTD.B0 //Pode ser também PORTD.RD0, para selecionar o display1
#define DISPLAY2 PORTD.B1 //Pode ser também PORTD.RD1, para selecionar o display2
#define DISPLAY3 PORTD.B2 //Pode ser também PORTD.RD2, para selecionar o display3
#define DISPLAY4 PORTD.B3 //Pode ser também PORTD.RD3, para selecionar o display4
/* Esta funcao encontra o padrao de bits a ser enviado para a porta e mostrar
um numero no display de 7 segmentos. O numero eh passado na lista de argumentos
da funcao.
*/
unsigned char Num(unsigned char no)
{
unsigned char Padrao;
//Números de 0 a 9 nos displays anodo comum, em decimal
unsigned int num0_9[10]={192,249,164,176,153,146,131,248,128,152};
Padrao = num0_9[no];
return (Padrao);
}
//Rotina Principal
void main()
{
//Variaveis
unsigned char MSD, LSD, Cnt = 25;
//Configuração dos registradores
ANSEL = 0; // Configura os pinos AN (analógicos) como digitais
ANSELH = 0;
C1ON_bit = 0; // Desabilita os comparadores
C2ON_bit = 0;
TRISB = 0; //Toda a porta B será saída
PORTB = 0; //Toda a porta B igual a 0
TRISD0_bit = 0; //pino 0 da Porta D como saída
TRISD1_bit = 0; //pino 1 da Porta D como saída
TRISD2_bit = 0; //pino 2 da Porta D como saída
TRISD3_bit = 0; //pino 3 da porta D como saída
//Valores iniciais
PORTB = 0xffff; //limpa a porta B
//Desligamos todos os displays
DISPLAY1 = 1; //Digito mais significativo (MSB)
DISPLAY2 = 1;
DISPLAY3 = 1;
DISPLAY4 = 1; //Digito menos significativo (LSB)
while(1)
{
 //Vamos usar os displays 1 e 2.
 MSD = Cnt/10; //Digito mais significativo
 PORTB = Num(MSD); //Envia para a porta B
 DISPLAY1 = 0; //Habilita o display 1
 Delay_ms(1); //Atraso
 DISPLAY1 = 1; // Desabilita o display 1

 LSD = Cnt%10; //Digito menos significativo
 PORTB = Num(LSD); //Envia para a porta B
 DISPLAY2 = 0; //Habilita o display 2
 Delay_ms(1); //Atraso
 DISPLAY2 = 1; //Desabilita o display 2
} //fim do while
} //fim do main