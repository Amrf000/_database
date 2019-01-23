#pragma once

// CDialog1 对话框

class CDragDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDragDialog)

public:
	CDragDialog();
	CDragDialog(UINT nIDTemplate, CWnd *pParent = NULL);
	virtual ~CDragDialog();
	virtual BOOL PreTranslateMessage(MSG *msg);


	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};