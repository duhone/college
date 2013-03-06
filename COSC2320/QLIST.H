#ifndef _qlist_h
#define _qlist_h
typedef struct quelist *Qlist;
Qlist newqlist(int n);
void insertqlist(int n,Qlist q);
void outputqlist(Qlist q);

#endif
