#include<lpc21xx.h>
int main(){
	int i=0;
char str[] = "Welcome to Alexa";
PINSEL0=0x05;
U0LCR=0x83;
U0DLL=0x5D;
U0LCR=0x03;
for(i=0;str[i]!='\0';i++){
	U0THR=str[i];	
	while(U0LSR==0x20);
}
while(1);
}
