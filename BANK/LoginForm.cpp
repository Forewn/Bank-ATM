//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "LoginForm.h"
#include<RegisterForm.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmyLoginForm *myLoginForm;
//---------------------------------------------------------------------------
__fastcall TmyLoginForm::TmyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}


//---------------------------------------------------------------------------
void __fastcall TmyLoginForm::loginButtonClick(TObject *Sender)
{
	users user[MAX];
    bankData data;
	bool correct = false;

	for(int i = 0; i <= data.registeredUsers ; i++){
		if(myLoginForm->cardnumberInput->Text == user[i]->cardNumber){
			correct = true;
            myLoginForm->cardnumberInput->Text = "";
			myLoginForm->passwordInput->Text = "";
			myLoginForm->errorText->Text = "Tarjeta valida";
		}
	}
	if(!correct){
		myLoginForm->errorText->Text = "Tarjeta invalida";
	}
}
//---------------------------------------------------------------------------
