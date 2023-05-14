//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>


//---------------------------------------------------------------------------
class TmyLoginForm : public TForm
{
__published:	// IDE-managed Components
	TButton *loginButton;
	TLabel *cardNumberText;
	TEdit *cardnumberInput;
	TLabel *passwordText;
	TEdit *passwordInput;
	TLabel *errorText;
	void __fastcall loginButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmyLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmyLoginForm *myLoginForm;
//---------------------------------------------------------------------------
#endif