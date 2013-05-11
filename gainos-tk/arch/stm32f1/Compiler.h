/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine China
 * Open Source Society; either version 1 of the License, or (at developer option)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the U-License for more details.
 * Developer should have received a copy of the U-Licensealong with this program;
 * if not, download from www.tecoss.org(the web page of the T-Engine China Open
 * Source Society).
 *
 * GaInOS-TK is a static configured RTOS, which conformed to OSEK OS 2.2.3 Specification
 * and it is based on uTenux(http://www.uloong.cc).
 *
 * Email: parai@foxmail.com
 * Sourrce Open At: https://github.com/parai/gainos-tk/
 */

#ifndef COMPILER_H_H_H
#define COMPILER_H_H_H

#define Inline static

#define EXPORT
#define IMPORT  extern 
#define LOCAL   static

   
#define ISR_IN_C  0
#define ISR_IN_ASSEMBLY  1 
   
#define cfgCORTEX_M3_ISR   ISR_IN_ASSEMBLY 
   
#if (cfgCORTEX_M3_ISR ==  ISR_IN_ASSEMBLY)  
/* ISR entry code should be in assemble */
#define ISR(ISRname) ISRMain##ISRname
#define ISREntry(ISRname) ISRMain##ISRname   
#elif (cfgCORTEX_M3_ISR ==  ISR_IN_C)
/* not supported */
/* I tried a lot, but I still DON'T know why how the fault is generated. 
 * I hate debug about hardware problem. */
#define ISR(ISRname) void ISRMain##ISRname(void)
#define ISREntry(ISRname) ISRMain##ISRname    
#endif   

#endif /* COMPILER_H_H_H */
