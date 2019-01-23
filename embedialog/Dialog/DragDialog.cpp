// Dialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "DragDialog.h"
#include "afxdialogex.h"


// CDialog1 对话框

IMPLEMENT_DYNAMIC(CDragDialog, CDialogEx)

CDragDialog::CDragDialog()
{

}

CDragDialog::CDragDialog(UINT nIDTemplate, CWnd *pParent):CDialogEx(nIDTemplate, pParent)
{

}

CDragDialog::~CDragDialog()
{
}

void CDragDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDragDialog::PreTranslateMessage(MSG *msg)
{
	if (msg->message == WM_MOUSEMOVE && (msg->wParam & MK_LBUTTON))
	{
		CPoint p;
		GetCursorPos(&p);
		CRect r;
		GetWindowRect(&r);
		if (r.PtInRect(p))
		{
			ReleaseCapture();
			SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
			SendMessage(WM_NCLBUTTONUP, HTCAPTION, 0);
			return 1;
		}
	}
	return CDialogEx::PreTranslateMessage(msg);
}

BEGIN_MESSAGE_MAP(CDragDialog, CDialogEx)
END_MESSAGE_MAP()


// CDialog1 消息处理程序
