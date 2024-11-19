#include<lpc21xx.h>
int main(){
char r;
PINSEL0=0x05;
U0LCR=0x83;
U0DLL=0x5D;
U0LCR=0x03;
while(!(U0LSR&0x01));
r=U0RBR;
U0THR=r;
while(U0LSR==0x20);
}