//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include<iostream>

#include "RegisterForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmyRegisterForm *myRegisterForm;
//---------------------------------------------------------------------------

int registeredUsers = 0;



__fastcall TmyRegisterForm::TmyRegisterForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TmyRegisterForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	myRegisterForm->nameInput->Text = "";
	myRegisterForm->surnameInput->Text = "";
	myRegisterForm->idInput->Text = "";
	myRegisterForm->emailInput->Text = "";
	myRegisterForm->passwordInput->Text = "";
	myRegisterForm->vrfpasswordInput->Text = "";
	myRegisterForm->creditcardInput->Text = "";
	myRegisterForm->directionInput->Text = "";
	myRegisterForm->IdoptionButton1->IsChecked = False;
	myRegisterForm->IdoptionButton2->IsChecked = False;
	myRegisterForm->IdoptionButton1->IsChecked = False;
	myRegisterForm->RadioButton1->IsChecked = False;
	myRegisterForm->RadioButton2->IsChecked = False;
	myRegisterForm->RadioButton3->IsChecked = False;
	myRegisterForm->genderoption1->IsChecked = False;
	myRegisterForm->genderoption2->IsChecked = False;
	myRegisterForm->genderoption3->IsChecked = False;

}
//---------------------------------------------------------------------------
int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

void __fastcall TmyRegisterForm::registerButtonClick(TObject *Sender)
{
	bool correct = true;
	users user[MAX];
	bankData data;

	if(correct){
		user[registeredUsers]->cardNumber = myRegisterForm->creditcardInput->Text;


		myRegisterForm->nameInput->Text = "";
		myRegisterForm->surnameInput->Text = "";
		myRegisterForm->idInput->Text = "";
		myRegisterForm->emailInput->Text = "";
		myRegisterForm->passwordInput->Text = "";
		myRegisterForm->vrfpasswordInput->Text = "";
		myRegisterForm->creditcardInput->Text = "";
		myRegisterForm->directionInput->Text = "";
		myRegisterForm->IdoptionButton1->IsChecked = False;
		myRegisterForm->IdoptionButton2->IsChecked = False;
		myRegisterForm->IdoptionButton1->IsChecked = False;
		myRegisterForm->RadioButton1->IsChecked = False;
		myRegisterForm->RadioButton2->IsChecked = False;
		myRegisterForm->RadioButton3->IsChecked = False;
		myRegisterForm->genderoption1->IsChecked = False;
		myRegisterForm->genderoption2->IsChecked = False;
		myRegisterForm->genderoption3->IsChecked = False;
		data.registeredUsers++;
	}
}
//---------------------------------------------------------------------------
