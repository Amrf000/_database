// Dialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// CDialog1 对话框

IMPLEMENT_DYNAMIC(CDialog1, CDragDialog)

CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDragDialog(IDD_DIALOG1, pParent)
{

}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDragDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog1, CDragDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialog1 消息处理程序


void CDialog1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDragDialog::OnPaint()
	CDragDialog::OnPaint();
}
