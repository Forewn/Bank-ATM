//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("..\..\..\..\Embarcadero\Studio\Projects\BANK\main.cpp", Form2);
USEFORM("..\..\..\..\Embarcadero\Studio\Projects\BANK\RegisterForm.cpp", myRegisterForm);
USEFORM("..\..\..\..\Embarcadero\Studio\Projects\BANK\LoginForm.cpp", myLoginForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TmyRegisterForm), &myRegisterForm);
		Application->CreateForm(__classid(TmyLoginForm), &myLoginForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
