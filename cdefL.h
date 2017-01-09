/* EasyCASE V6.5 01.09.2008 10:06:52 */
/* EasyCASE O
If=vertical
LevelNumbers=no
LineNumbers=yes
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=System,,100,1,-13,0,700,0,0,0,0,0,0,1,2,1,34,96,96
PrinterFont=Courier,,100,65530,-83,0,400,0,0,0,0,0,0,3,2,1,49,600,600
LastLevelId=17 */
/* EasyCASE ( 1 */
#ifndef CDEF_H
#define CDEF_H
/* EasyCASE - */
#include "Platform_Types.h"  // Vector cdef
/* EasyCASE - */
#undef _BIG_ENDIAN_
#define _LITTLE_ENDIAN_
/* EasyCASE ( 9
   typdef */
typedef void (*tFuncPtr) (void);
/* EasyCASE - */
typedef unsigned char   bool;
/* EasyCASE - */
typedef unsigned char byte;
/* EasyCASE - */
typedef unsigned short  word;
/* EasyCASE - */
typedef byte tbBitByte;             /*  8 Bit field type     */
/* EasyCASE - */
typedef word twBitWord;         /* 16 Bit field type     */
/* EasyCASE ) */
/* EasyCASE ( 4
   tunbitb */
/* EasyCASE C */
/*
* Description         : Bitfield data type with 8 bits
*                       The following bitfield depends on the compiler
*                       and machine! The defined structure has to be
*                       redefined for other compilers, so that the following
*/
/**                       conditions are correct:
*                       bitb bibBitF8;
*                       bibBitF8.B == ( bibBitF8.F._7 * 2^7 ) +
*                                     ( bibBitF8.F._6 * 2^6 ) + ...
*                                     ( bibBitF8.F._0 * 2^0 )
*/
typedef union tunbitb
   {
   byte B;                              /* Byte access identifier */
   /* EasyCASE ( 5 */
   /* EasyCASE C */
   struct
      {
      #ifdef _BIG_ENDIAN_
      tbBitByte _7 : 1; /*
      *
      * Description        :
      * Access rights      : r/w
      * Val. range / Coding: 0..1 / Off..On
      */
      tbBitByte _6 : 1;
      tbBitByte _5 : 1;
      tbBitByte _4 : 1;
      tbBitByte _3 : 1;
      tbBitByte _2 : 1;
      tbBitByte _1 : 1;
      tbBitByte _0 : 1;
      #endif
      #ifdef _LITTLE_ENDIAN_
      tbBitByte _0 : 1; /*
      *
      * Description        :
      * Access rights      : r/w
      * Val. range / Coding: 0..1 / Off..On
      */
      tbBitByte _1 : 1;
      tbBitByte _2 : 1;
      tbBitByte _3 : 1;
      tbBitByte _4 : 1;
      tbBitByte _5 : 1;
      tbBitByte _6 : 1;
      tbBitByte _7 : 1;
      #endif
      } F;                                 /* Flag access identifier */
   /* EasyCASE E */
   /* EasyCASE ) */
   } tunbitb;
/* EasyCASE E */
/* EasyCASE ) */
/* EasyCASE ( 6
   tunbitw */
/* EasyCASE C */
/*
* Description         : Bitfield data type with 16 bits
*                       The following bitfield depends on the compiler
*                       and machine! The defined structure has to be
*                       redefined for other compilers, so that the following
*                       conditions are correct:
*                       bitw biwBitF16;
*                       biwBitF16.W    == ( biwBitF16.B._1  * 2^8  ) +
*                                         ( biwBitF16.B._0  * 2^0  )
*                       biwBitF16.W    == ( biwBitF16.F._15 * 2^15 ) +
*                                         ( biwBitF16.F._14 * 2^14 ) + ...
*                                         ( biwBitF16.F._0  * 2^0  )
*/
typedef union tunbitw
   {
   word W;                              /* Word access identifier */
   /* EasyCASE ( 7 */
   /* EasyCASE C */
   struct
      {
      #ifdef _BIG_ENDIAN_
      byte _1; /*
      *
      * Description        : High byte (Bits 8 to 15)
      * Access rights      : r/w
      * Val. range / Coding: 0..255
      */
      byte _0;                       /* Low byte (Bits 0 to 7) */  
      
      #endif
      #ifdef _LITTLE_ENDIAN_
      byte _0; /*
      *
      * Description        : Low byte (Bits 8 to 15)
      * Access rights      : r/w
      * Val. range / Coding: 0..255
      */
      byte _1;                       /* High byte (Bits 0 to 7) */  
      
      #endif
      } B;                                 /* Byte access identifier */
   /* EasyCASE E */
   /* EasyCASE ) */
   /* EasyCASE ( 8 */
   /* EasyCASE C */
   struct
      {
      #ifdef _BIG_ENDIAN_
      
      twBitWord _15: 1; /*
      *
      * Description        :
      * Access rights      : r/w
      * Val. range / Coding: 0..1 / Off..On
      */
      twBitWord _14 : 1;
      twBitWord _13 : 1;
      twBitWord _12 : 1;
      twBitWord _11 : 1;
      twBitWord _10 : 1;
      twBitWord _9 : 1;
      twBitWord _8 : 1;
      
      twBitWord _7 : 1;
      twBitWord _6 : 1;
      twBitWord _5 : 1;
      twBitWord _4 : 1;
      twBitWord _3 : 1;
      twBitWord _2 : 1;
      twBitWord _1 : 1;
      twBitWord _0 : 1;  
      
      #endif
      
      #ifdef _LITTLE_ENDIAN_
                                  
      twBitWord _0: 1; /*
      *
      * Description        :
      * Access rights      : r/w
      * Val. range / Coding: 0..1 / Off..On
      */
      twBitWord _1 : 1;
      twBitWord _2 : 1;
      twBitWord _3 : 1;
      twBitWord _4 : 1;
      twBitWord _5 : 1;
      twBitWord _6 : 1;
      twBitWord _7 : 1;
      
      twBitWord _8 : 1;
      twBitWord _9 : 1;
      twBitWord _10 : 1;
      twBitWord _11 : 1;
      twBitWord _12 : 1;
      twBitWord _13 : 1;
      twBitWord _14 : 1;
      twBitWord _15 : 1;  
      
      #endif
      } F;                                 /* Flag access identifier */
   /* EasyCASE E */
   /* EasyCASE ) */
   } tunbitw;
/* EasyCASE E */
/* EasyCASE ) */
/* typedefinitions according to smk */

typedef tunbitb bit8;                 /*  8 Bit field union     */
typedef tunbitw bit16;                /* 16 Bit field union     */
/* EasyCASE - */
typedef unsigned long       dword;  /* Unsigned 32-bit datatype: 0..4294967296           */
/* EasyCASE - */
typedef bit16 tBitField;
/* EasyCASE - */
#define __far                        /* special keyword from FJ16 ?                     */
/* EasyCASE - */
#define Yes 1
#define No 0
/* EasyCASE - */
#define On 1
#define Off 0
/* EasyCASE - */
#define True 1
#define False 0
/* EasyCASE - */
#endif
/* EasyCASE ) */
