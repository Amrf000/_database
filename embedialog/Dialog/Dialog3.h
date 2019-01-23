#pragma once
#include "Dialog1.h"
#include "afxcmn.h"

// CDialog3 对话框

class CDialog3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog3)

public:
	CDialog3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialog3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
private:
	CTabCtrl m_tab;
	CDialog1 m_dialog1;
};
