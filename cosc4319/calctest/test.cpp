//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "test.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double result = 0.0;
        if(pComp2 != NULL)  pComp2->Factorial(170,&result);
        pComp2->NPR(170,50,&result);
        pComp2->NCR(170,170,&result);
        pComp2->AddNumList(1);
        pComp2->AddNumList(2);
        pComp2->AddNumList(3);
        pComp2->AddNumList(10);
        pComp2->CalcSum(&result);
        pComp2->CalcAvg(&result);
        pComp2->StdDev(&result);
        Edit1->Text = result;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   CoInitialize(NULL);
   CoCreateInstance(CLSID_computation2,NULL,CLSCTX_ALL,IID_Icomputation2,(void**)&pComp2);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        if(pComp2 != NULL)  pComp2->Release();
        CoUninitialize();       
}
//---------------------------------------------------------------------------
