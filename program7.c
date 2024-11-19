//transmits a string of characters depending on the character received using UART0
//same as uart4.c
#include<lpc21xx.h>
void serial_init(){
PINSEL0=0x05;
U0LCR=0x83;
U0DLL=0x5D;
U0LCR=0x03;
}
void serial_tx(unsigned char ch){
	U0THR=ch;
	while(U0LSR==0x20);
}

void serial_tx_str( char str1[40]){
	int i;
	for(i=0;str1[i]!='\0';i++){
		serial_tx(str1[i]);
	}
}

char serial_rx(){
	char r;
	while(!(U0LSR&0x01));
	r=U0RBR;
	serial_tx(r);
	return r;
}

int main(){
serial_init();
char p;
while(1){
serial_tx_str("enter any char: ");
p=serial_rx();
if(p=='k'){
serial_tx_str("Welcome to ECE");
}
else if(p=='i'){
	serial_tx_str("Welcome to IOT");
}
else{
	break;
}
}
}


	