#ifndef  cpuid_h
#define cpuid_h

#define p5 0
#define p6mmx 1
#define p6sse 2
#define p7sse2 3
#define k7mmxe 4
#define k7sse 5

extern int cpu_type;

extern void cpuid();

#endif