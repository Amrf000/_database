
// DialogDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "DialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDialogDlg 对话框



CDialogDlg::CDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CDialogDlg::OnSelchangeTab1)
END_MESSAGE_MAP()


// CDialogDlg 消息处理程序

BOOL CDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);
	//=======
	//CWnd *pTab = GetDlgItem(IDC_TAB1);
	//for (CWnd *pWnd = pTab->GetWindow(GW_CHILD); pWnd != NULL; pWnd = pWnd->GetNextWindow(GW_HWNDNEXT))
	//{
	//	pWnd->GetDlgCtrlID();
	//}
	m_tab.InsertItem(0, _T("中国"));
	m_tab.InsertItem(1, _T("人民"));
	m_cur_mode_sel = TAB_MODE_WARN;
	m_tab.SetCurSel(m_cur_mode_sel);

	m_dialog3.Create(IDD_DIALOG3, &m_tab);
	m_pPage[0] = &m_dialog3;
	//m_dialog1.Create(IDD_DIALOG1, &m_dialog3);
	
	m_dialog2.Create(IDD_DIALOG2, &m_tab);
	m_pPage[1] = &m_dialog2;
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 21;
	rc.bottom -= 2;
	rc.left += 2;
	rc.right -= 1;
	m_pPage[0]->MoveWindow(&rc);
	m_pPage[0]->ShowWindow(SW_SHOW);
	//m_dialog1.ShowWindow(SW_SHOW);

	m_pPage[1]->MoveWindow(&rc);
	m_pPage[1]->ShowWindow(SW_HIDE);
	UpdateData(false);
	//=====
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int cur_sel = m_tab.GetCurSel();

	if (m_cur_mode_sel != cur_sel) {
		m_pPage[m_cur_mode_sel]->ShowWindow(SW_HIDE);
		m_pPage[cur_sel]->ShowWindow(SW_SHOW);
		m_cur_mode_sel = cur_sel;
	}
	*pResult = 0;
}
