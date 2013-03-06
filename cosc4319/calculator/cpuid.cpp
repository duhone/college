#include "stdafx.h"
#include "cpuid.h"


int cpu_type;

void cpuid()
{
	cpu_type = p5;
	unsigned int features;
	char cpu_brand[13] = {"STD CPU"};
	unsigned int *icpu_brand = (unsigned int*)cpu_brand;
	_asm
	{
		push ebp
	
		mov eax,0
		cpuid
		mov ebp,icpu_brand
		mov [ebp],ebx
		mov [ebp+4],edx
		mov [ebp+8],ecx
	
		pop ebp

	}
	cpu_brand[12] = 0;
	if(strcmp(cpu_brand,"AuthenticAMD") == 0)
	{
		_asm
		{
			mov eax,0x80000001
			cpuid
			mov features,edx

		}
		if(features & 0x02000000)
		{
			cpu_type = k7sse;
			::MessageBox(0,"AMD ATHLON XP CPU","cpu type",0);
	
		}
		else if(features & 0x40000000)
		{
			cpu_type = k7mmxe;
			::MessageBox(0,"AMD ATHLON CPU","cpu type",0);
	
		}
		else if(features & 0x00800000)
		{
			cpu_type = p6mmx;
			::MessageBox(0,"AMD k6 CPU","cpu type",0);
	
		}
		else 
		{
			cpu_type = p5;
			::MessageBox(0,"UNKOWN AMD CPU","cpu type",0);
	
		}
	}
}