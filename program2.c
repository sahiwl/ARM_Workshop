#include<lpc21xx.h>
void delay(unsigned int);
int main()
{
IODIR0=0x000000010;
while(1)
{
IOSET0=0x000000010;
//IOCLR0=0x00000000E;
delay(5);
	
//IOSET0=0x000000002;
IOCLR0=0x000000010;
delay(5);
}
}
void delay(unsigned int m)
{
unsigned int i,j;
for(i=0;i<m;i=i+1)
for(j=0;j<65535;j=j+1);
}