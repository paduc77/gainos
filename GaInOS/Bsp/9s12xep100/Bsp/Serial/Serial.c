#include "Serial.h"
#include "stdio.h"
#include "stdlib.h"

#define  BUS_CLOCK		   CPU_FREQUENCY*1000000	   /* ����Ƶ��   */
#define BAUD 9600                      /* ���ڲ����� */

#define SCI_UNINITIALISED 0 
#define SCI_INITIALISED  1

static unsigned int g_sci_state = SCI_UNINITIALISED;
static void Sci_Init()
{
	SCI0BD = BUS_CLOCK/16/BAUD;   /* ����SCI0������Ϊ9600 */
	SCI0CR1 = 0x00;       /* ����SCI0Ϊ����ģʽ����λ����λ������żУ��*/
	SCI0CR2 = 0x08;       /* ���������ݣ���ֹ�жϹ��� */
}
static void Sci_Send(unsigned char data)
{
	while(!SCI0SR1_TDRE);       /* �ȴ��������ݼĴ�������������Ϊ�� */
	SCI0DRL = data;
}
void printk(char *fmt,...){
	unsigned int i=0;
    char *buf=NULL;
	int len;
	va_list args;
	if(SCI_UNINITIALISED==g_sci_state){
		Sci_Init();
		g_sci_state=SCI_INITIALISED;
	}
	va_start(args,fmt);
	buf=malloc(64);
	if(NULL==buf)return;		/* �����ڴ�ʧ�ܣ�ֱ�ӷ��� */
	len = vsprintf((char*)buf,(char *)fmt,args)+1;
	while('\0'!=buf[i]&&i<len)  Sci_Send(buf[i++]) ;
	free(buf);
	va_end(args);
}
