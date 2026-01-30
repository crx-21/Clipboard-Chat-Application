//---------------------------------------------------------------------------

#ifndef MessageH
#define MessageH

#include <Vcl.ComCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
using namespace std;

class Message
{
protected:
//Client
bool Bold=false;
bool Italic=false;
bool Underline=false;
TColor messageColor;
String username;
String messageText;
String timestamp;
//Partea ptr sv
bool isBold = false;
bool isItalic = false;
bool isUnderline = false;
public:
// Getters
bool returnisBold();
bool returnisItalic();
bool returnisUnderline();
TColor getMessageColor();
String getUsername();
String getMessageText();
String getTimestamp();

// Setters
void setisBold(bool value);
void setisItalic(bool value);
void setisUnderline(bool value);
void resetValues();

//Metode ajutatoare legate de styling
void ExtractTimestamp(String &text);
void ExtractUsername(String &text, int colonPos);
void ExtractColor(String &text);
void ExtractStyleTags(String &text);

//Main
void InterpreteazaMesaj(String receivedText, TRichEdit *richEdit);


};
#endif
