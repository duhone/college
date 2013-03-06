#ifndef _poly_h
#define _poly_h
typedef struct PolyNode *Poly;
Poly ReadPoly(void);
void PrintPoly(Poly p);
Poly AddPoly(Poly p1, Poly p2);
Poly SubPoly(Poly p1, Poly p2);
Poly MulPoly(Poly p1, Poly p2);
Poly DifPoly(Poly p);
void DeletePoly(Poly p);
#endif
