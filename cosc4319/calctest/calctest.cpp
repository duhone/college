//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("calctest.res");
USEFORM("test.cpp", Form1);
USEUNIT("C:\Program Files\Borland\CBuilder5\Imports\COMP2Lib_TLB.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
