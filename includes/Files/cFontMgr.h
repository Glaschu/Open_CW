/*
== == == == == == == == =
cFontMgr.h
- Header file for class definition - SPECIFICATION
- Header file for the InputMgr class
== == == == == == == == =
*/
#ifndef _CFONTMGR_H
#define _CFONTMGR_H

#include <Files/cFont.h>

class cFontMgr
{
private:

	static cFontMgr* pInstance ;
	map<LPCSTR, cFont*> gameFonts;

public:
	static cFontMgr* getInstance() {
		if (pInstance == NULL)
		{
			pInstance = new cFontMgr();
		}
		return cFontMgr::pInstance;
	}

	cFontMgr() {

	}							// Constructor
	~cFontMgr() {
		deleteFont();
	}							// Destructor.
	void addFont(LPCSTR fontName, LPCSTR fileName, int fontSize) {
		if (!getFont(fontName))
		{
			cFont * newFont = new cFont(fileName, fontSize);
			gameFonts.insert(make_pair(fontName, newFont));
		}
	} // add font to the Font collection
	cFont* getFont(LPCSTR fontName) {
		map<LPCSTR, cFont*>::iterator theFont = gameFonts.find(fontName);
		if (theFont != gameFonts.end())
		{
			return theFont->second;
		}
		else
		{
			return NULL;
		}
	}			// return the font for use
	void deleteFont() {
		for (map<LPCSTR, cFont*>::const_iterator theFont = gameFonts.begin(); theFont != gameFonts.end(); theFont++)
		{
			delete theFont->second;
		}
	}
	// delete font.

};

#endif