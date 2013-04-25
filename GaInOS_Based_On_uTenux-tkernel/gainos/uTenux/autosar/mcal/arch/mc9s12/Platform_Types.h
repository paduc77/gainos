/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface.
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 *
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_

#define CPU_TYPE            CPU_TYPE_16
#define CPU_BIT_ORDER       MSB_FIRST 
#define CPU_BYTE_ORDER      HIGH_BYTE_FIRST

typedef unsigned int        boolean;
typedef signed char         sint8;        
typedef unsigned char       uint8;
typedef char				char_t;
typedef signed short        sint16;       
typedef unsigned short      uint16;       
typedef signed long         sint32;       
typedef unsigned long       uint32;
typedef unsigned long long  uint64; /* Yeah, This type is not supported by Codewarrior5.0 */
typedef unsigned int        uint8_least;  
typedef unsigned int        uint16_least; 
typedef unsigned long       uint32_least; 
typedef signed int          sint8_least;  
typedef signed int          sint16_least; 
typedef signed long         sint32_least; 
typedef float               float32; 
typedef double              float64; 

/* This is a Cpu ISR Mask type <CCR>*/
typedef uint8               imask_t; 


#endif /* _PLATFORM_TYPES_H_ */

