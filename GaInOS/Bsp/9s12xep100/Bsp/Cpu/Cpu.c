

#include "Cpu.h"

#define  OSC_CLOCK		   16000000	   /* ����Ƶ��   */

void CpuFrequencyInit(void) 
{
    CRGINT = 0;                  //���ж�
    CLKSEL_PLLSEL = 0;           //��δ��ʼ��PLLǰ��ʹ��PLL�������ΪCPUʱ��
    
  #if(CPU_FREQUENCY == 40) 
    SYNR = 4;
  #elif(CPU_FREQUENCY == 32)
    SYNR = 3;     
  #elif(CPU_FREQUENCY == 24)
    SYNR = 2;
  #endif 

    REFDV = 1;                   //PLLCLK=2��OSCCLK��(SYNR+1)/(REFDV+1)��64MHz ,fbus=32M
    PLLCTL_PLLON = 1;            //��PLL
    while (CRGFLG_LOCK == 0);    //�ȴ�PLL����Ƶ��
    CLKSEL_PLLSEL = 1;           //ѡ��ϵͳʱ����PLL����

}

void CpuInitOsTick(void) 
{
  CRGINT_RTIE=1;       /* ʹ��ʵʱ�ж� */
  RTICTL = 0x70;       /* ����ʵʱ�жϵ�ʱ����Ϊ32.768ms */
   /* �ж�����=1/16 x 10E-6 x ��0+1��x 2E��7+9��=0.004096s=4.096ms  */
}