#include<reg51.h>
//================
sbit    Led1  =  P2^0;
sbit    Led2  =  P2^1;
#define LEDPORT P0
//=================
unsigned char led7[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int x=0;
//=================
void delay(unsigned int t)
{
	unsigned int i;
	for(i=0;i<=t;i++);
}
//=================
void main()
{
	IE=0x81;
	IT0=1;
	while(1)
	{
		Led1=1;  //led dau tien sang
		P0=led7[x/10];
		delay(50);
		Led1=0; 
		P0=0xff;//xoa du lieu
		Led2=1;  //led 2 sang
		P0=led7[x%10];
		delay(50); 
		Led2=0;
		P0=0xff;//xoa du lieu
	}
}
//=================
void ngat0(void) interrupt 0
{
	EA=0;
	x++;
	if(x==100)x=0;
	delay(1000);
	EA=1;
}