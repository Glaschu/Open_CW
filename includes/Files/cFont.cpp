/*
==========================================================================
cFont.cpp
==========================================================================
*/
#pragma warning ( disable : 4996 )
#include "cFont.h"
using namespace std;

/*
==========================================================================
Default Constructor
==========================================================================
*/
cFont::cFont()
{
	theFont = NULL;
}
/*
==========================================================================
Overloaded constructor
==========================================================================
*/
cFont::cFont(LPCSTR fontFileName, int fontSize)
{
	theFont = new FTTextureFont(fontFileName);

	if (theFont == NULL)
	{
		MessageBox(NULL, "Unable to create the required Font!", "An error occurred", MB_ICONERROR | MB_OK);
		delete theFont;
	}

	if (!theFont->FaceSize(fontSize))
	{
		MessageBox(NULL, "Unable to set desired size for Font!", "An error occurred", MB_ICONERROR | MB_OK);
		delete theFont;
	}
}

/*
==========================================================================
Destructor
==========================================================================
*/
cFont::~cFont()
{
	delete theFont;
}
/*
==========================================================================
get the pointer to the font
==========================================================================
*/
FTFont* cFont::getFont()
{
	return theFont;
}

/*
==========================================================================
Render the text using the desired font
==========================================================================
*/
void cFont::printText(LPCSTR text, FTPoint textPos)
{
	glPushMatrix();

	glTranslatef(textPos.X(), textPos.Y(), 0 );
	// glRotatef(180,1, 0, 0); // Will work too
	glScalef(1, -1, 1);
	glColor3f(0.0f, 255.0f, 0.0f);
	theFont->Render(text);

	glPopMatrix();
}
