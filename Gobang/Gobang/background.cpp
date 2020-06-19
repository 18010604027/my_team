#include "pch.h"

CBitmap bmpBackground;
CImage imgBackground;

void set_bk(int ID)
{
	bmpBackground.LoadBitmap(ID);
	HINSTANCE hIns = AfxGetInstanceHandle();
	imgBackground.LoadFromResource(hIns, ID);
}
void reset_bk(int ID)
{
	bmpBackground.Detach();
	bmpBackground.DeleteObject();
	bmpBackground.LoadBitmap(ID);
	HINSTANCE hIns = AfxGetInstanceHandle();
	imgBackground.Detach();
	imgBackground.Destroy();
	imgBackground.LoadFromResource(hIns, ID);
}