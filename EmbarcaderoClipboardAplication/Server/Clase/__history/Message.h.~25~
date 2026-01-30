//---------------------------------------------------------------------------
#ifndef MessageH
#define MessageH
#include <map>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class Message
{
protected:
	String text;
	AnsiString user;
	map <int,string> clientUsers; //Map pentru stocare de handle-uri asociate username-ului clientilor
public:
TDateTime timestamp;
Message();
Message(String text,String user);
//Metode:
void setText(String InputText);
void setUser(String InputUser);
String getText();
String getUser();


};
#endif
