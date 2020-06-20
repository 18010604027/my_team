#pragma once
 

extern CBitmap bmpBackground;
extern CImage imgBackground;

void set_bk(int ID);
void reset_bk(int ID);
void clear_bk();
#define draw_bk(way)\
{\
CPaintDC dc(this);\
CRect   rect;\
GetClientRect(&rect);\
CDC   dcMem;\
dcMem.CreateCompatibleDC(&dc);\
BITMAP   bitmap;\
bmpBackground.GetBitmap(&bitmap);\
dcMem.SelectObject(bmpBackground);\
if(way==0)\
{\
dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY); \
}\
else\
{\
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY); \
}\
dcMem.DeleteDC();\
}