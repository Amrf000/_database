// Dialog3.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "Dialog3.h"
#include "afxdialogex.h"


// CDialog3 对话框

IMPLEMENT_DYNAMIC(CDialog3, CDialogEx)

CDialog3::CDialog3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CDialog3::~CDialog3()
{
}

void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDD_DIALOG1, m_dialog1);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CDialog3, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialog3 消息处理程序


BOOL CDialog3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_tab.InsertItem(0, _T("中国"));
	m_tab.SetCurSel(0);

	m_dialog1.Create(IDD_DIALOG1, &m_tab);

	CRect rc;
	m_tab.GetClientRect(rc);
	//rc.top += 21;
	//rc.bottom -= 2;
	//rc.left += 2;
	//rc.right -= 1;
	m_dialog1.MoveWindow(&rc);
	m_dialog1.ShowWindow(SW_SHOW);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL CDialog3::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CDialog3::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CDialogEx::OnPaint();
}
