//---------------------------------------------------------------------------

#ifndef ThemeFormH
#define ThemeFormH
//---------------------------------------------------------------------------
#include "UserSettings.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <fstream>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
using namespace std;
//---------------------------------------------------------------------------
class TTheme : public TForm
{
__published:	// IDE-managed Components
	TButton *Nature;
	TButton *Aqua;
	TButton *Red;
	TLabel *LabelNature;
	TLabel *LabelAqua;
	TLabel *LabelRed;
	TButton *btnDefault;
	void __fastcall NatureClick(TObject *Sender);
	void __fastcall AquaClick(TObject *Sender);
	void __fastcall RedClick(TObject *Sender);
	void __fastcall btnDefaultClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:
UserSettings *SetariUser;
ofstream UserSettingsFile;	// User declarations
	__fastcall TTheme(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TTheme *Theme;
//---------------------------------------------------------------------------
#endif
