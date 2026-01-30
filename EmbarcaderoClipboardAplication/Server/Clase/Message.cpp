//---------------------------------------------------------------------------

#pragma hdrstop

#include "Message.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Message::Message()
{
	  text="Default";
	  timestamp=Now();
	  user="Unknown";
}

Message::Message(String text,String user)
{
	 this->text=text;
	 timestamp=Now();
     this->user=user;
}
void Message::setText(String InputText)
{
   text=InputText;                    //Modificam text

}
void Message::setUser(String InputUser)
{
	user=InputUser;                 //Modificam user
}
String Message::getText()
{
return text;              //Facem rost de text
}
String Message::getUser()
{
    return user;            //Facem rost de user
}
