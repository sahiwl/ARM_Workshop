//transmits a string of characters depending on the character received using UART0
#include <lpc21xx.h>

void transmit(char ch[])//transmits a string of array
{
      int i;
      for(i=0;ch[i]!='\0';i++){
            U0THR=ch[i];
            while(U0LSR==0x20);
      }
}
void transmitChar(char ch)//transmits a single character
{
            U0THR=ch;
            while(U0LSR==0x20);
}

char receive()//receives a single character and returns it
{
      while(!(U0LSR&0x01));
      return U0RBR;
}
void serial_init()//initalization of the UART
{
      PINSEL0=0x05;
      U0LCR=0x83;
      U0DLL=0x5D;
      U0LCR=0x03;
}


int main()
{
      char ch;

      serial_init();
      transmit("Enter a character: ");
      ch=receive();
      transmitChar(ch);
      transmitChar('\n');
      switch(ch)
      {
            case 'k':
                  transmit("Welcome to CSE");
                  transmitChar('\n');
                  break;
            case 'i':
                  transmit("Welcome to IOT");
                  transmitChar('\n');
                  break;
            default:
                  transmit("Exiting code...");
                  while(1);
      }
}