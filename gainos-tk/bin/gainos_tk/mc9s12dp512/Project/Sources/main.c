#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Std_Types.h"
#include <stdio.h>
#include "Os.h"
#include "osek_os.h"


void TERMIO_PutChar(char c)
{
    while(!SCI0SR1_TDRE);       /* �ȴ��������ݼĴ�������������Ϊ�� */
	SCI0DRL = c;
}
static void Sci_Init()
{
	SCI0BD = CPU_FREQUENCY/16/115200;   /* ����SCI0������Ϊ115200 */
	SCI0CR1 = 0x00;       /* ����SCI0Ϊ����ģʽ����λ����λ������żУ��*/
	SCI0CR2 = 0x08;       /* ���������ݣ���ֹ�жϹ��� */
}

static void SystemClockInit(void)
{
    CRGINT = 0;                  //���ж�
    CLKSEL_PLLSEL = 0;           //��δ��ʼ��PLLǰ��ʹ��PLL�������ΪCPUʱ��
    
  #if(CPU_FREQUENCY == 40000000) 
    SYNR = 4;
  #elif(CPU_FREQUENCY == 32000000)
    SYNR = 3;     
  #elif(CPU_FREQUENCY == 24000000)
    SYNR = 2;
  #endif 

    REFDV = 1;                   //PLLCLK=2��OSCCLK��(SYNR+1)/(REFDV+1)��64MHz ,fbus=32M
    PLLCTL_PLLON = 1;            //��PLL
    PLLCTL_AUTO = 1;             //ѡȡ�Զ�ģʽ
    while (CRGFLG_LOCK == 0);    //�ȴ�PLL����Ƶ��
    CLKSEL_PLLSEL = 1;           //ѡ��ϵͳʱ����PLL����
}

void main(void) {
    SystemClockInit();
    Sci_Init();
    (void)printf("\r\nStart OS.\r\n");
    StartOS(OSDEFAULTAPPMODE);
}
