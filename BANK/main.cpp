//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include<RegisterForm.h>
#include<LoginForm.h>

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::singinButtonClick(TObject *Sender)
{
    myLoginForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::registerButtonClick(TObject *Sender)
{
    myRegisterForm->Show();
}
//---------------------------------------------------------------------------
