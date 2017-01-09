/* EasyCASE V6.5 08.02.2010 16:22:02 */
/* EasyCASE O
If=horizontal
LevelNumbers=no
LineNumbers=no
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=System,,100,1,-13,0,700,0,0,0,0,0,0,1,2,1,34,96,96
PrinterFont=Courier,,100,65530,-83,0,400,0,0,0,0,0,0,3,2,1,49,600,600
LastLevelId=1 */
/* EasyCASE ( 1 */
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Provision of Platform Types for Mb86r0x
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2008-07-15  Pl                    Adapt for the Mb86r0x
 *  03.01.01  2008-12-01  Ht                    Version number corrected
 *********************************************************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Mb86r0x CQComponent : Impl_PlatformTypes */
#define COMMONASR_MB86R0X_IMPL_PLATFORMTYPES_VERSION 0x0301
#define COMMONASR_MB86R0X_IMPL_PLATFORMTYPES_RELEASE_VERSION 0x01
 
#define PLATFORM_VENDOR_ID    30u
 
/* AUTOSAR Software Specification Version Information */
/* AUTOSAR Document version 2.2.0 part of release 3.0.0 */
#define PLATFORM_AR_MAJOR_VERSION       (2u)
#define PLATFORM_AR_MINOR_VERSION       (2u)
#define PLATFORM_AR_PATCH_VERSION       (0u)

/* Component Version Information */
#define PLATFORM_SW_MAJOR_VERSION       (3u)
#define PLATFORM_SW_MINOR_VERSION       (1u)
#define PLATFORM_SW_PATCH_VERSION       (1u) 


#define CPU_TYPE_8       8
#define CPU_TYPE_16      16
#define CPU_TYPE_32      32

#define MSB_FIRST        0    /*big endian bit ordering*/
#define LSB_FIRST        1    /*little endian bit ordering*/

#define HIGH_BYTE_FIRST  0    /*big endian byte ordering*/
#define LOW_BYTE_FIRST   1    /*little endian byte ordering*/

#ifndef TRUE
   #define TRUE          1
#endif

#ifndef FALSE
   #define FALSE         0
#endif

#define CPU_TYPE         CPU_TYPE_32

#define CPU_BIT_ORDER    LSB_FIRST        /*little endian bit ordering*/

#define CPU_BYTE_ORDER   LOW_BYTE_FIRST   /*little endian byte ordering*/
                      
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned char         boolean;       /*        TRUE .. FALSE           */

typedef signed char           sint8;         /*        -127 .. +127            */
typedef signed char           int8;         /*        -127 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32767 .. +32767          */
typedef signed short          int16;        /*      -32767 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483647 .. +2147483647     */
typedef signed long           int32;        /* -2147483647 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */
typedef unsigned long long int uint64;  /* Unsigned 64-bit datatype: 0..18446744073709551615  */
                                        
typedef signed char           sint8_least;   /* At least 7 bit + 1 bit sign    */
typedef unsigned char         uint8_least;   /* At least 8 bit                 */
typedef signed short          sint16_least;  /* At least 15 bit + 1 bit sign   */
typedef unsigned short        uint16_least;  /* At least 16 bit                */
typedef signed long           sint32_least;  /* At least 31 bit + 1 bit sign   */
typedef unsigned long         uint32_least;  /* At least 32 bit                */


                                        
typedef float                 float32;
typedef double                float64;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h
 *********************************************************************************************************************/
/* EasyCASE ) */
