/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Oct 21 23:32:05 2001
 */
/* Compiler settings for C:\cosc4319\as2\my assign2\assign2.idl:
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

const IID IID_IGasReservoir = {0xF621F82B,0x39D7,0x4CD8,{0xA2,0xAD,0xDF,0x6B,0x70,0x88,0x0C,0x84}};


const IID IID_IGasFiller = {0x168BF217,0xDD5B,0x4406,{0x8D,0xAB,0x67,0x31,0x42,0x1B,0x00,0x63}};


const IID LIBID_ASSIGN2Lib = {0x917B1F42,0xDA08,0x45F1,{0x9F,0xD3,0x7F,0xF1,0xF3,0x57,0x4C,0x6C}};


const CLSID CLSID_GasReservoir = {0x8628F9C5,0x2B0C,0x400F,{0xBE,0x78,0x5B,0x14,0x82,0xE7,0x73,0x6D}};


const CLSID CLSID_GasFiller = {0xC2BF3D02,0xDE1B,0x41EC,{0xAB,0x8B,0x3A,0x21,0xE4,0xBC,0x46,0x97}};


#ifdef __cplusplus
}
#endif

