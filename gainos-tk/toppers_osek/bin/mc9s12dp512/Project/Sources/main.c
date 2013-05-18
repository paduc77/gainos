#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "kernel.h"

#define CPU_FREQUENCY 32000000
void TERMIO_PutChar(char c)
{
    while(!SCI0SR1_TDRE);
	SCI0DRL = c;
}

static void Sci_Init()
{
	SCI0BD = CPU_FREQUENCY/16/115200;  
	SCI0CR1 = 0x00;       
	SCI0CR2 = 0x08;       
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
void sys_initialize(void)
{
    SystemClockInit();
    Sci_Init();
    CRGINT_RTIE=1;       //ʹ��ʵʱ�ж�
    RTICTL = 0x70;       //����ʵʱ�жϵ�ʱ����Ϊ4.096ms
    //�ж�����=1/16 x 10E-6 x ��0+1��x 2E��7+9��=0.004096s=4.096ms
}
void tool_initialize(void)
{

}
void cpu_initialize(void)
{
    CRGINT = 0;                  
    CLKSEL_PLLSEL = 0;           
    
  #if(CPU_FREQUENCY == 40000000) 
    SYNR = 4;
  #elif(CPU_FREQUENCY == 32000000)
    SYNR = 3;     
  #elif(CPU_FREQUENCY == 24000000)
    SYNR = 2;
  #endif 

    REFDV = 1;                   
    PLLCTL_PLLON = 1;            
    PLLCTL_AUTO = 1;             
    while (CRGFLG_LOCK == 0);    
    CLKSEL_PLLSEL = 1;           
}

void StartupHook(void)
{

}
void ShutdownHook(StatusType ercd)
{

}
void PreTaskHook(void)
{
}
void PostTaskHook(void)
{
}
void ErrorHook(StatusType ercd)
{
}

void cpu_terminate(void)
{
}
void sys_exit(void)
{
    for(;;);
}
void main(void) {
	DisableInterrupts;
	StartOS(OSDEFAULTAPPMODE);
    for(;;);
 
}
