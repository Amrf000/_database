#include <windows.h>
#include <gl/gl.h>
#include <gl/GLU.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdarg.h>
typedef          __int64 ll;
typedef          char   int8;
typedef          short  int16;
typedef          int    int32;
typedef ll              int64;
template<class T> 
int8 __SETS__(T x)
{
	if (sizeof(T) == 1)
		return int8(x) < 0;
	if (sizeof(T) == 2)
		return int16(x) < 0;
	if (sizeof(T) == 4)
		return int32(x) < 0;
	return int64(x) < 0;
}
template<class T, class U>
int8 __OFSUB__(T x, U y)
{
	if (sizeof(T) < sizeof(U))
	{
		U x2 = x;
		int8 sx = __SETS__(x2);
		return (sx ^ __SETS__(y)) & (sx ^ __SETS__(x2 - y));
	}
	else
	{
		T y2 = y;
		int8 sx = __SETS__(x);
		return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(x - y2));
	}
}
BOOL IsOpenGLInited = FALSE; 
HGLRC gGLRC = NULL; 
float gLookEyeX = 0.0; 
float gLookEyeY = 0; 
float gLookEyeZ;
float gTargetX = 0;
float gTargetY = 0;
float gTargetZ = 0;
HWND gHWND = NULL; 
LARGE_INTEGER gPerformanceCount = { { 0u, 0 } }; 
HDC gWndDC = NULL; 
DWORD gFPS = 0;
class W3EFILE {
public:
	void DrawW3E();
	W3EFILE(char *a2="war3map.w3e");
public:
	DWORD _value[2048*160];
};
W3EFILE gW3eFile; 
char ActiveKeyTable[0xFF]; 
LARGE_INTEGER PerformanceCount; 
LARGE_INTEGER Frequency; 
BOOL IsDisplaySetted; 
float gFpsA; 
float gFpsB; 
int cFPS; 

void InitOpenGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.333333333333333, 1.0, 1000000.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_COLOR_MATERIAL);
	IsOpenGLInited = TRUE;
}
BOOL sub_401250(HDC hdc)
{
	PIXELFORMATDESCRIPTOR ppfd =
	{
		40u,
		1u,
		37u,
		0u,
		32u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		16u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u,
		0u
	};
	int v1 = ChoosePixelFormat(hdc, &ppfd);
	return SetPixelFormat(hdc, v1, &ppfd);
}
void W3EFILE::DrawW3E()
{
	char *v1; 
	GLfloat *v2; 
	signed int v3; 
	GLfloat red; 
	GLfloat v5; 
	GLfloat v6; 
	GLfloat v7; 
	bool v8; 
	int v9; 
	signed int v10; 
	v1 = (char*)this;
	glPushMatrix();
	v10 = 160;
	v9 = (int)(v1 + 12);
	do
	{
		glBegin(GL_TRIANGLE_STRIP);
		v2 = (GLfloat *)v9;
		v3 = 160;
		do
		{
			red = (*v2 * 0.0099999998 + 128.0) * 0.0039215689;
			glColor3f(red, red, red);
			glVertex3f(v2[2], *v2, v2[3]);
			v5 = (v2[7] * 0.0099999998 + 128.0) * 0.0039215689;
			glColor3f(v5, v5, v5);
			glVertex3f(v2[9], v2[7], v2[10]);
			v6 = (v2[1127] * 0.0099999998 + 128.0) * 0.0039215689;
			glColor3f(v6, v6, v6);
			glVertex3f(v2[1129], v2[1127], v2[1130]);
			v7 = (v2[1134] * 0.0099999998 + 128.0) * 0.0039215689;
			glColor3f(v7, v7, v7);
			glVertex3f(v2[1136], v2[1134], v2[1137]);
			v2 += 1127;
			--v3;
		} while (v3);
		glEnd();
		v8 = (v10 == 1);
		v9 += 28;
		--v10;
	} while (!v8);
	glPopMatrix();
}
BOOL SetWndTitle(HWND hWnd, char *a2, ...)
{
	CHAR String[1024]; 
	va_list va; 
	va_start(va, a2);
	vsprintf(&String[0], a2, va);
	return SetWindowTextA(hWnd, &String[0]);
}
BOOL sub_401110()
{
	int contain;
	if (gFpsA - gFpsB < 1.0)
	{
		++cFPS;
	}
	else
	{
		gFPS = cFPS;
		cFPS = 0;
		gFpsB = gFpsA;
	}
	SetWndTitle(gHWND, "W3E Viewer - Brizzard Entertainment [ FPS:%d ]", gFPS);
	gLookEyeY = *(float*)(&(contain = 1176256512));
	gTargetX = *(float*)(&(contain = 1176567808));
	gTargetY = *(float*)(&(contain = 1124073472));
	gTargetZ = *(float*)(&(contain = -970915840));
	glClear(0x4100u);
	glLoadIdentity();
	gluLookAt(
		gLookEyeX,
		gLookEyeY,
		gLookEyeZ,
		gTargetX,
		gTargetY,
		gTargetZ,
		0.0,
		1.0,
		0.0);
	glTranslatef(0.0, -500.0, -200.0);
	((W3EFILE *)&gW3eFile)->DrawW3E();
	glFlush();
	return SwapBuffers(gWndDC);
}
LRESULT CALLBACK WinProc(HWND hWnd, UINT Msg, WPARAM wParam, unsigned int lParam)
{
	double v4; 
	double v5; 
	LRESULT result; 
	GLsizei v7; 
	HDC v8; 
	signed int wParama; 
	if (Msg > WM_CLOSE)
	{
		switch (Msg)
		{
		case WM_KEYDOWN:
			ActiveKeyTable[wParam] = 1;
			return 0;
		case WM_KEYUP:
			result = 0;
			ActiveKeyTable[wParam] = 0;
			return result;
		case WM_MOUSEMOVE:
			return 0;
		}
		return DefWindowProcA(hWnd, Msg, wParam, lParam);
	}
	if (Msg == WM_CLOSE)
	{
		wglMakeCurrent(gWndDC, 0);
		wglDeleteContext(gGLRC);
		PostQuitMessage(0);
		return 0;
	}
	if (Msg == WM_CREATE)
	{
		v8 = GetDC(hWnd);
		gWndDC = v8;
		sub_401250(v8);
		gGLRC = wglCreateContext(gWndDC);
		wglMakeCurrent(gWndDC, gGLRC);
		return 0;
	}
	if (Msg != WM_SIZE)
	{
		if (Msg == WM_PAINT)
		{
			if (IsOpenGLInited)
			{
				QueryPerformanceCounter(&PerformanceCount);
				v4 = gFpsA;
				v5 = (double)(PerformanceCount.QuadPart - gPerformanceCount.QuadPart) / (double)Frequency.QuadPart;
				gFpsA = v5;
				sub_401110();
				return 0;
			}
			return 0;
		}
		return DefWindowProcA(hWnd, Msg, wParam, lParam);
	}
	v7 = lParam >> 16;
	wParama = lParam >> 16;
	if (!(lParam >> 16))
	{
		v7 = 1;
		wParama = 1;
	}
	glViewport(0, 0, (unsigned short)lParam, v7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(54.0, (double)(unsigned short)lParam / (double)wParama, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	DWORD v5; 
	DWORD v6; 
	struct tagRECT Rect = {0,0,800,600};
	WNDCLASSEXA WndClassEx; 
	struct tagMSG Msg; 
	DEVMODEA dmScreenSettings;
	WndClassEx.cbSize = 48;
	WndClassEx.style = 3;
	WndClassEx.lpfnWndProc = (WNDPROC)WinProc;
	WndClassEx.cbClsExtra = 0;
	WndClassEx.cbWndExtra = 0;
	WndClassEx.hInstance = hInstance;
	WndClassEx.hIcon = LoadIconA(0, IDI_APPLICATION);
	WndClassEx.hCursor = LoadCursorA(0, IDI_APPLICATION);
	WndClassEx.hbrBackground = 0;
	WndClassEx.lpszMenuName = 0;
	WndClassEx.lpszClassName = "MyClass";
	WndClassEx.hIconSm = LoadIconA(0, IDI_WINLOGO);
	if (!RegisterClassExA(&WndClassEx))
		return 0;
	if (!IsDisplaySetted)
		goto LABEL_6;
	memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
	dmScreenSettings.dmSize = sizeof(dmScreenSettings);
	dmScreenSettings.dmPelsWidth = 800;
	dmScreenSettings.dmPelsHeight = 600;
	dmScreenSettings.dmBitsPerPel = 32;
	dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	if (ChangeDisplaySettingsA((DEVMODEA *)&dmScreenSettings, CDS_FULLSCREEN))
	{
		MessageBoxA(0, "Display mode failed", 0, 0);
		IsDisplaySetted = FALSE;
	LABEL_6:
		v5 = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		v6 = WS_BORDER | WS_DLGFRAME | WS_SYSMENU | WS_THICKFRAME | WS_GROUP | WS_TABSTOP;//13565952
		goto LABEL_7;
	}
	if (!IsDisplaySetted)
		goto LABEL_6;
	v5 = WS_EX_APPWINDOW;
	v6 = WS_POPUP;//2147483648
	ShowCursor(0);
LABEL_7:
	AdjustWindowRectEx(&Rect, v6, 0, v5);
	gHWND = CreateWindowExA(
		0,
		"MyClass",
		"W3E Viewer - Brizzard Entertainment",
		v6 | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		0,
		0,
		Rect.right - Rect.left,
		Rect.bottom - Rect.top,
		0,
		0,
		hInstance,
		0);
	if (!gHWND)
		return 0;
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&gPerformanceCount);
	MessageBoxA(0, "Brian's .w3e Viewer\n\nUser the arrow keys to move the map around.\nW - Wireframe mode\nP - Point mode\nF - Fill mode\n\nPay attention to the FPS counter in the title if you are curious.\n", "Brian's .w3e Viewer", 0);
	ShowWindow(gHWND, 5);
	UpdateWindow(gHWND);
	InitOpenGL();
	while (1)
	{
		PeekMessageA(&Msg, gHWND, 0, 0, 1u);
		if (Msg.message == 18)
			break;
		if (ActiveKeyTable[29])
			gLookEyeZ = gLookEyeZ - 64.0;
		if (ActiveKeyTable[31])
			gLookEyeZ = gLookEyeZ + 64.0;
		if (ActiveKeyTable[30])
			gLookEyeX = gLookEyeX + 64.0;
		if (ActiveKeyTable[28])
			gLookEyeX = gLookEyeX - 64.0;
		if (ActiveKeyTable[87])
			glPolygonMode(GL_FRONT, GL_LINE);
		if (ActiveKeyTable[80])
			glPolygonMode(GL_FRONT, GL_POINT);
		if (ActiveKeyTable[70])
			glPolygonMode(GL_FRONT, GL_FILL);
		if (ActiveKeyTable[27])
			break;
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}
	if (IsDisplaySetted)
	{
		ChangeDisplaySettingsA(0, 0);
		ShowCursor(1);
	}
	return Msg.wParam;
}
class W3EHEDER {
public:
	W3EHEDER() {
		flag[4] = 0;
	}
public:
	char flag[5];
	int version;
	char maintileset;
	int customflag;
	int numberA;
	void *tilesetstable;
	int numberB;
	void *tilesetstableB;
	int width;
	int height;
	float offsetX;
	float offsetY;
};
#include <iostream>
#include <ostream>
using namespace std;
W3EFILE::W3EFILE(char *a2)
{
	W3EHEDER header;
	FILE *fd;  
	int v62; 
	signed int v63; 
	int v64; 
	short v65; 
	short v66; 
	int v67; 
	int v68; 
	float v69; 
	double v70; 
	unsigned char v71; 
	unsigned char v72; 
	unsigned char v77; 
	short v78; 
	int v79; 
	int v80; 
	char v81[4]; 
	char *v82; 
	int v83; 
	float v84; 
	v82 = (char*)this;
	operator new(0x1Cu);
	fd = fopen(a2, "rb");
	if (!fd)
	{
		cout << "shat" << endl;
	}
	fread(header.flag, 4u, 1u, fd);
	if (!strcmp((const char *)header.flag, "W3E!"))
	{
		cout << (char *)header.flag << " - W3E check passed." << endl;
	}
	fread(&header.version, 4u, 1u, fd);
	if (header.version == 11)
	{
		cout << "Version - " << 11 << ".  Version check passed" << endl;
	}
	fread(&header.maintileset, 1u, 1u, fd);
	cout << "Tile set - " << header.maintileset << endl;
	fread(&header.customflag, 4u, 1u, fd);
	cout << "Custom tile set - "<< header.customflag << endl;
	fread(&header.numberA, 4u, 1u, fd);
	cout << "Number of ground tile sets - "<< header.numberA << endl;
	header.tilesetstable = malloc(4 * header.numberA+1);
	memset(header.tilesetstable, 0, 4 * header.numberA + 1);
	fread(header.tilesetstable, 4 * header.numberA, 1u, fd);
	cout << "Number of cliff tile sets - "<< (char*)header.tilesetstable << endl;
	fread(&header.numberB, 4u, 1u, fd);
	cout << "Number of cliff tile sets - " << header.numberB << endl;
	header.tilesetstableB = malloc(4 * header.numberB+1);
	memset(header.tilesetstableB, 0, 4 * header.numberB + 1);
	fread(header.tilesetstableB, 4 * header.numberB, 1u, fd);
	cout << "Cliff tile set IDs - "<< (char*)header.tilesetstableB << endl;
	fread(&header.width, 4u, 1u, fd);
	cout << "Map width - "<< header.width << endl;
	fread(&header.height, 4u, 1u, fd);
	cout << "Map height - " << header.height << endl;
	fread(&header.offsetX, 4u, 1u, fd);
	cout<< "X offset - "<< header.offsetX << endl;
	fread(&header.offsetY, 4u, 1u, fd);
	cout << "Z offset - " << header.offsetY << endl;
	v80 = 0;
	v62 = (int)(v82 + 2);
	do
	{
		v63 = 0;
		v64 = v62;
		*(DWORD *)v81 = 0;
		v84 = (double)v80 * -128.0;
		do
		{
			fread(&v78, 2u, 1u, fd);
			fread(&v79, 2u, 1u, fd);
			if ((v79 & 0xC000) == 0x4000)
				*(BYTE *)(v64 + 8) = 1;
			v79 &= 0x3FFFu;
			fread(&v77, 1u, 1u, fd);
			v65 = v77 & 0xF;
			*(WORD *)(v64 - 2) = v77 >> 4;
			*(WORD *)v64 = v65;
			fread((void *)(v64 + 2), 1u, 1u, fd);
			fread(&v77, 1u, 1u, fd);
			v66 = v77 & 0xF;
			v67 = v78;
			*(WORD *)(v64 + 4) = v77 >> 4;
			*(WORD *)(v64 + 6) = v66;
			v64 += 4508;
			v83 = v67 + ((v66 - 16) << 9);
			v68 = (signed short)v79 - 0x2000;
			*(float *)(v64 - 4498) = (double)v83 * 0.25;
			v69 = v84;
			v83 = v68 / 4;
			++v63;
			*(float *)(v64 - 4494) = (double)(v68 / 4) - 89.599998;
			v70 = (double)*(signed int *)v81;
			*(DWORD *)v81 = v63;
			*(float *)(v64 - 4490) = v70 * 128.0;
			*(float *)(v64 - 4486) = v69;
		} while (v63 < 161);
		v62 += 28;
		v72 = __OFSUB__(v80 + 1, 161);
		v71 = (v80++ - 160 < 0);
	} while (v71 ^ v72);
	fclose(fd);
	cout << "Done loading" << a2 << endl;
}
