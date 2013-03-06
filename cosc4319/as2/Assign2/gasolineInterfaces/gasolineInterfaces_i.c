/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Dec 28 17:00:50 1999
 */
/* Compiler settings for C:\Temp\Doc\examplesAndLabs\session03\Lab\solution\gasolineInterfaces\gasolineInterfaces.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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

const IID IID_IGasReservoir = {0xB6CB97C0,0xBD47,0x11d3,{0x87,0xA2,0x44,0x45,0x53,0x54,0x00,0x00}};


const IID IID_IGasFiller = {0xB6CB97C1,0xBD47,0x11d3,{0x87,0xA2,0x44,0x45,0x53,0x54,0x00,0x00}};


#ifdef __cplusplus
}
#endif

