/*
==========================================================================
cFont.h
==========================================================================
*/

#ifndef _CFONT_H
#define _CFONT_H

// OpenGL Headers
#include <Windows.h>
#include <FTGL\ftgl.h>

using namespace std;

class cFont
{
private:
	FTFont* theFont;


public:
	cFont() {
		theFont = NULL;
	}
	cFont(LPCSTR fontFileName, int fontSize) {
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
	~cFont() {
		delete theFont;
	}
	FTFont* getFont() {
		return theFont;
	}
	void printText(LPCSTR text, FTPoint textPos) {
		glPushMatrix();

		glTranslatef(textPos.X(), textPos.Y(), 0);
		// glRotatef(180,1, 0, 0); // Will work too
		glScalef(1, -1, 1);
		glColor3f(0.0f, 255.0f, 0.0f);
		theFont->Render(text);

		glPopMatrix();
	}

};
#endif