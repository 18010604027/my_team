#include "pch.h"

CBitmap bmpBackground;
CImage imgBackground;

void set_bk(int ID)
{
	bmpBackground.LoadBitmap(ID);
	HINSTANCE hIns = AfxGetInstanceHandle();
	imgBackground.LoadFromResource(hIns, ID);
}