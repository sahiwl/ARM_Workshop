#include<lpc21xx.h>
#define RS 1<<24
#define RW 1<<25
#define EN 1<<26
#define LCD 0xff<<16
void clcd(unsigned char);
void dlcd(unsigned char);
void delay(unsigned int);
unsigned char str1[]="Noida Institute of Eng and Tech";
unsigned char str2[]="Welcome to CSE";
unsigned int i;

void lcd_init()
{
      clcd(0x38);
      clcd(0x01);
      clcd(0x0E);
      clcd(0x06);
      clcd(0x80);
}
int main()
{
      IODIR1=0x07ff0000;
      lcd_init();
      clcd(0x80);
      for(i=0;i<16;i=i+1)
{
            dlcd(str1[i]);
}
      clcd(0xc0);
      for(i=16;str1[i]!='\0';i=i+1)
{
      dlcd(str1[i]);
}
}
void clcd(unsigned char ch)
{
      IOCLR1=RS;
      IOCLR1=LCD;
      IOSET1=ch<<16;
      IOCLR1=0;
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
void delay(unsigned int m)
{
      unsigned int i,j;
for(i=0;i<m;i=i+1);
for (j=0;j<65535;j=j+1);      
}