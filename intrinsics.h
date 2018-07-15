/*****************************************************************************/
/*  INTRINSICS.H                                                             */
/*                                                                           */
/* Copyright (c) 2005 Texas Instruments Incorporated                         */
/* http://www.ti.com/                                                        */
/*                                                                           */
/*  Redistribution and  use in source  and binary forms, with  or without    */
/*  modification,  are permitted provided  that the  following conditions    */
/*  are met:                                                                 */
/*                                                                           */
/*     Redistributions  of source  code must  retain the  above copyright    */
/*     notice, this list of conditions and the following disclaimer.         */
/*                                                                           */
/*     Redistributions in binary form  must reproduce the above copyright    */
/*     notice, this  list of conditions  and the following  disclaimer in    */
/*     the  documentation  and/or   other  materials  provided  with  the    */
/*     distribution.                                                         */
/*                                                                           */
/*     Neither the  name of Texas Instruments Incorporated  nor the names    */
/*     of its  contributors may  be used to  endorse or  promote products    */
/*     derived  from   this  software  without   specific  prior  written    */
/*     permission.                                                           */
/*                                                                           */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS    */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT    */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT    */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT    */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     */
/*                                                                           */
/*****************************************************************************/
#ifndef _INTRINSICS_H_
#define _INTRINSICS_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*---------------------------------------------------------------------------*/
/* Handle legacy conflicts                                                   */
/*---------------------------------------------------------------------------*/
#include "intrinsics_legacy_undefs.h"

/*---------------------------------------------------------------------------*/
/* General MSP Intrinsics                                                    */
/*---------------------------------------------------------------------------*/
void           __no_operation(void);

unsigned short __bic_SR_register         (unsigned short mask);
unsigned short __bic_SR_register_on_exit (unsigned short mask);
unsigned short __bis_SR_register         (unsigned short mask);
unsigned short __bis_SR_register_on_exit (unsigned short mask);
unsigned short __get_SR_register         (void);
unsigned short __get_SR_register_on_exit (void);

unsigned short __get_SP_register(void);
void           __set_SP_register(unsigned short value);

void           __delay_cycles(unsigned long cycles);

unsigned int   __even_in_range(unsigned int val, unsigned int range);

void           __op_code(unsigned short op);

/*---------------------------------------------------------------------------*/
/* General MSP Macros                                                        */
/*---------------------------------------------------------------------------*/
#define __never_executed()      _never_executed()

#define __swap_bytes(x) (((unsigned short)(x) >> 8) | ((unsigned short)(x) << 8))

/*---------------------------------------------------------------------------*/
/* MSP430/430X Intrinsics                                                    */
/*---------------------------------------------------------------------------*/
void             __disable_interrupt(void);
void             __enable_interrupt(void);
void             __set_interrupt_state(unsigned short state);

unsigned short   __get_R4_register(void);
void             __set_R4_register(unsigned short value);
unsigned short   __get_R5_register(void);
void             __set_R5_register(unsigned short value);

unsigned short   __bcd_add_short(unsigned short, unsigned short);
unsigned long    __bcd_add_long(unsigned long, unsigned long);

/*---------------------------------------------------------------------------*/
/* MSP430/430X Macros                                                        */
/*---------------------------------------------------------------------------*/
#define __get_interrupt_state() __get_SR_register()

#define __low_power_mode_0()    __bis_SR_register(0x18)
#define __low_power_mode_1()    __bis_SR_register(0x58)
#define __low_power_mode_2()    __bis_SR_register(0x98)
#define __low_power_mode_3()    __bis_SR_register(0xD8)
#define __low_power_mode_4()    __bis_SR_register(0xF8)
#define __low_power_mode_off_on_exit() __bic_SR_register_on_exit(0xF0)


#if defined(__MSP430X__)
/*---------------------------------------------------------------------------*/
/* MSP430X Intrinsics                                                        */
/*---------------------------------------------------------------------------*/
void           __data16_write_addr(unsigned short, unsigned long);
unsigned long  __data16_read_addr(unsigned short);
void           __data20_write_char(unsigned long, unsigned char);
void           __data20_write_short(unsigned long, unsigned short);
void           __data20_write_long(unsigned long, unsigned long);
unsigned char  __data20_read_char(unsigned long);
unsigned short __data20_read_short(unsigned long);
unsigned long  __data20_read_long(unsigned long);

#endif

/*---------------------------------------------------------------------------*/
/* Legacy Macros                                                             */
/*---------------------------------------------------------------------------*/
#define _nop()                  __no_operation()
#define _no_operation()         __no_operation()
#define _enable_interrupt()     __enable_interrupt()
#define _enable_interrupts()    __enable_interrupt()
#define _disable_interrupt()    __disable_interrupt()
#define _disable_interrupts()   __disable_interrupt()
#define _set_interrupt_state(x) __set_interrupt_state(x)
#define _get_interrupt_state()  __get_interrupt_state()
#define _delay_cycles(x)        __delay_cycles(x)
#define _get_SP_register()      __get_SP_register()
#define _set_SP_register(x)     __set_SP_register(x)
#define _get_R4_register()      __get_R4_register()
#define _set_R4_register(x)     __set_R4_register(x)
#define _get_R5_register()      __get_R5_register()
#define _set_R5_register(x)     __set_R5_register(x)
#define _bic_SR_register(x)         __bic_SR_register(x)
#define _bic_SR_register_on_exit(x) __bic_SR_register_on_exit(x)
#define _bis_SR_register(x)         __bis_SR_register(x)
#define _bis_SR_register_on_exit(x) __bis_SR_register_on_exit(x)
#define _get_SR_register()          __get_SR_register()
#define _get_SR_register_on_exit()  __get_SR_register_on_exit()
#define _low_power_mode_0()         __low_power_mode_0()
#define _low_power_mode_1()         __low_power_mode_1()
#define _low_power_mode_2()         __low_power_mode_2()
#define _low_power_mode_3()         __low_power_mode_3()
#define _low_power_mode_4()         __low_power_mode_4()
#define _low_power_mode_off_on_exit() __low_power_mode_off_on_exit()
#define _even_in_range(x,y)      __even_in_range(x,y)
#define _op_code(x)              __op_code(x)
#define _swap_bytes(x)           __swap_bytes(x)
#define _data16_write_addr(x,y)  __data16_write_addr(x,y)
#define _data16_read_addr(x)     __data16_read_addr(x)
#define _data20_write_char(x,y)  __data20_write_char(x,y)
#define _data20_read_char(x)     __data20_read_char(x)
#define _data20_write_short(x,y) __data20_write_short(x,y)
#define _data20_read_short(x)    __data20_read_short(x)
#define _data20_write_long(x,y)  __data20_write_long(x,y)
#define _data20_read_long(x)     __data20_read_long(x)
#define _bcd_add_short(x,y)      __bcd_add_short(x,y)
#define _bcd_add_long(x,y)       __bcd_add_long(x,y)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _INTRINSICS_H_ */
