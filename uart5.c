#include <lpc21xx.h>

void transmitString(char ch[]){
      int i;
      for(i=0;ch[i]!='\0';i++){
            U0THR=ch[i];
            while(U0LSR==0x20);
      }
}
void transmitChar(char ch){
            U0THR=ch;
            while(U0LSR==0x20);
}

char receive(){
      while(!(U0LSR&0x01));
      return U0RBR;
}
void serial_init(){
      PINSEL0=0x05;
      U0LCR=0x83;
      U0DLL=0x5D;
      U0LCR=0x03;
}


int main(){
      char ch;
      serial_init();
      transmitString("Enter a character: ");
      ch=receive();
      transmitChar(ch);
      transmitChar('\n');
      switch(ch)
      {
            case '1':
                  IODIR0=0x00000001;
									transmitString("LED1 is on \n");
									break;
            case '2':
									IOCLR0=0x00000001;
									transmitString("LED1 is off \n");
									break;
						case '3':
									IOSET0=0x00000002;
									while(1);
									transmitString("LED2 is on \n");
									break;
						case '4':
									IOCLR0=0x00000002;
									transmitString("LED2 is off \n");
									break;
}
}