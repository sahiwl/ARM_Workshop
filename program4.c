#include<lpc21xx.h>
#define RS 1<<24
#define RW 1<<25
#define EN 1<<26
#define LCD 0xff<<16
unsigned char str1[] = "Welcome to IOT";
void delay(unsigned int m)
{
      int i,j;
      for(i=0;i<m;i=i+1)
      for(j=0;j<65535;j=j+1);
}
void clcd(unsigned char ch)
{
      IOCLR1=RS;
      IOCLR1=LCD;
      IOSET1=ch<<16;
      IOCLR1=RW;
      IOSET1=EN;
      delay(5);
      IOCLR1=EN;
}
void dlcd(unsigned char ch)
{
      IOSET1=RS;
      IOCLR1=LCD;
      IOSET1=ch<<16;
      IOCLR1=RW;
      IOSET1=EN;
      delay(5);
      IOCLR1=EN;
}
void lcd_init(){
	   clcd(0x38);
      clcd(0x0E);
      clcd(0x01);
      clcd(0x06);
      clcd(0x80);
}
int main()
{
	unsigned int i;
  lcd_init(); 
	IODIR1=0x07FF0000;
	for(i=0;str1[i]!='\0';i++){
	dlcd(str1[i]);	
}
}