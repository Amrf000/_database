#pragma once

// CDialog1 �Ի���

class CDragDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDragDialog)

public:
	CDragDialog();
	CDragDialog(UINT nIDTemplate, CWnd *pParent = NULL);
	virtual ~CDragDialog();
	virtual BOOL PreTranslateMessage(MSG *msg);


	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};