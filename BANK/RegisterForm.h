//---------------------------------------------------------------------------

#ifndef RegisterFormH
#define RegisterFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Calendar.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.ExtCtrls.hpp>

int const MAX = 20;

typedef struct{
	String cardNumber;
}users[MAX];

typedef struct{
	int registeredUsers;
}bankData;

//---------------------------------------------------------------------------
class TmyRegisterForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *nameInput;
	TLabel *nameText;
	TLabel *surnameLabel;
	TLabel *vrfpasswordtext;
	TLabel *creditcardtext;
	TLabel *idText;
	TLabel *passwordText;
	TEdit *surnameInput;
	TEdit *idInput;
	TEdit *creditcardInput;
	TEdit *passwordInput;
	TEdit *vrfpasswordInput;
	TButton *registerButton;
	TLabel *Emailtext;
	TEdit *emailInput;
	TLabel *civilStatusText;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *IdoptionButton1;
	TRadioButton *IdoptionButton2;
	TCalendar *Calendar1;
	TLabel *stateText;
	TPopupBox *PopupBox1;
	TLabel *DirectionText;
	TEdit *directionInput;
	TLabel *Label1;
	TLabel *BirthdayText;
	TLabel *genderText;
	TRadioButton *genderoption1;
	TRadioButton *genderoption2;
	TRadioButton *genderoption3;
	TLabel *resultText;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall registerButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmyRegisterForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmyRegisterForm *myRegisterForm;
//---------------------------------------------------------------------------
#endif
