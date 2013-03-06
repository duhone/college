/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Oct 19 06:01:07 2001
 */
/* Compiler settings for C:\Venkat\UofH\f014319\HW2\CounterComp\CounterComp.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_ICounter = {0x5FBE269E,0x99F8,0x4824,{0xA2,0x3A,0x0A,0xD4,0xEE,0x81,0xE1,0x23}};


const IID LIBID_COUNTERCOMPLib = {0x81025464,0xE7E6,0x4854,{0xAE,0x74,0x90,0xB2,0x47,0x1D,0x39,0x28}};


const CLSID CLSID_Counter = {0xEFFF78AB,0xC02F,0x4888,{0x9B,0xEA,0xEF,0x5E,0x67,0xD0,0x43,0x64}};


#ifdef __cplusplus
}
#endif

