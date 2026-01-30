//---------------------------------------------------------------------------

#pragma hdrstop

#include "Message.h"
//---------------------------------------------------------------------------

bool Message::returnisBold()
{
return isBold;
}
bool Message::returnisItalic()
{
return isItalic;
}
bool Message::returnisUnderline()
{
return isUnderline;
}
TColor Message::getMessageColor()
{
return messageColor;
}
String Message::getUsername()
{
return username;
}
String Message::getMessageText()
{
return messageText;
}
String Message::getTimestamp()
{
return timestamp;
}

    // Setters
void Message::setisBold(bool value)
{
isBold = value;
}
void Message::setisItalic(bool value)
{
isItalic = value;
}
void Message::setisUnderline(bool value)
{
isUnderline = value;
}

void Message::resetValues()
{
    isBold = false;
    isItalic = false;
    isUnderline = false;
    messageColor = clWindowText;
    username = "";
    messageText = "";
    timestamp = "";
}

void Message::ExtractTimestamp(String &text)
{
    timestamp = "";
    int timestampStart = text.LastDelimiter("[");

    if (timestampStart > 0)
    {
        timestamp = " " + text.SubString(timestampStart, text.Length() - timestampStart + 1);
        text = text.SubString(1, timestampStart - 1).Trim();
    }
}

void Message::ExtractUsername(String &text, int colonPos)
{
    username = text.SubString(1, colonPos - 1);
    text = text.SubString(colonPos + 1, text.Length() - colonPos).Trim();
}

void Message::ExtractColor(String &text)
{
    messageColor = clWindowText; // Default
    int colorTagStart = text.Pos("<c:");

    if (colorTagStart == 1)
    {
        int colorTagEnd = text.Pos(">");
        if (colorTagEnd > 0)
        {
            String colorHex = text.SubString(4, colorTagEnd - 4); // Get "RRGGBB"
            text.Delete(1, colorTagEnd); // Remove <c:RRGGBB>

            // Remove closing </c> tag
            int colorCloseTag = text.Pos("</c>");
            if (colorCloseTag > 0)
            {
                text.Delete(colorCloseTag, 4);
            }

            // Convert hex string to TColor
            try
            {
                messageColor = (TColor)StrToInt("0x" + colorHex);
            }
            catch (Exception *e)
            {
                messageColor = clWindowText; // Fallback to default
            }
        }
    }
}

void Message::ExtractStyleTags(String &text)
{
    // Reset flags
    isBold = false;
    isItalic = false;
    isUnderline = false;

    // Check and remove style tags
    while (true)
    {
        bool foundTag = false;

        if (text.Pos("<b>") == 1)
        {
            isBold = true;
            text.Delete(1, 3);
            int endTag = text.Pos("</b>");
            if (endTag > 0) text.Delete(endTag, 4);
            foundTag = true;
        }

        if (text.Pos("<i>") == 1)
        {
            isItalic = true;
            text.Delete(1, 3);
            int endTag = text.Pos("</i>");
            if (endTag > 0) text.Delete(endTag, 4);
            foundTag = true;
        }

		if (text.Pos("<U>") == 1)
        {
            isUnderline = true;
            text.Delete(1, 3);
			int endTag = text.Pos("</U>");
            if (endTag > 0) text.Delete(endTag, 4);
            foundTag = true;
        }

        if (!foundTag) break; // No more tags found
    }
}


//Main

void Message::InterpreteazaMesaj(String receivedText, TRichEdit *richEdit)
{
 if (!richEdit) return; //Verificam existenta, pentru a nu forta crash

	String serverStr = receivedText;


	ExtractTimestamp(serverStr); //Facem rost de timestamp

	// Step 2: Parse username and message
	int colonPos = serverStr.Pos(":");

    if (colonPos > 0)
    {
		// Extract username
        ExtractUsername(serverStr, colonPos);

		// Now serverStr contains only the message part
        messageText = serverStr;

		// Step 3: Extract color
        ExtractColor(messageText);

        // Step 4: Extract style tags
		ExtractStyleTags(messageText);

		// Step 5: Display in RichEdit
        richEdit->SelStart = richEdit->Text.Length();
		richEdit->SelLength = 0;

		// Add username with default style
        richEdit->SelAttributes->Style = TFontStyles();
		richEdit->SelAttributes->Color = clWindowText;
        richEdit->SelText = username + ": ";

        // Build style for message
		TFontStyles style;
        if (isBold) style = style << fsBold;
		if (isItalic) style = style << fsItalic;
        if (isUnderline) style = style << fsUnderline;

        // Apply style and color to message
		richEdit->SelAttributes->Style = style;
        richEdit->SelAttributes->Color = messageColor;
		richEdit->SelText = messageText;

		// Add timestamp with default style
        richEdit->SelAttributes->Style = TFontStyles();
		richEdit->SelAttributes->Color = clWindowText;
        richEdit->SelText = timestamp + "\r\n";
	}
    else
	{
        // System message (no colon found)
		richEdit->SelStart = richEdit->Text.Length();
        richEdit->SelLength = 0;
		richEdit->SelAttributes->Style = TFontStyles();
        richEdit->SelAttributes->Color = clWindowText;
		richEdit->SelText = serverStr + "\r\n";
    }
}

#pragma package(smart_init)
