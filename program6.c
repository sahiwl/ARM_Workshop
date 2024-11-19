#include<LPC21xx.h>
int main(){
PINSEL0 = 0x05;
U0LCR = 0x83;
U0DLL = 0x5D;
U0LCR = 0x03;
U0THR = 'A';
while(U0LSR==0x20); //0x00==0x20
while(1);
}