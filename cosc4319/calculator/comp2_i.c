/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Oct 06 20:47:30 2001
 */
/* Compiler settings for C:\cosc4319\calculator\comp2.idl:
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

const IID IID_Icomputation2 = {0x96CCE1ED,0x8884,0x48C7,{0xA1,0x28,0x77,0x0A,0x5A,0x0F,0xB1,0x78}};


const IID LIBID_COMP2Lib = {0x84BF7034,0x9D35,0x43BD,{0x9B,0x19,0x95,0xD7,0x45,0x48,0xC2,0xF4}};


const CLSID CLSID_computation2 = {0x03A6F446,0xADE0,0x4315,{0x8F,0x16,0xCF,0x28,0xC8,0x65,0xF3,0xED}};


#ifdef __cplusplus
}
#endif

