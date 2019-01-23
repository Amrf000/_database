
// DialogDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "Dialog2.h"
#include "Dialog3.h"

// CDialogDlg �Ի���
class CDialogDlg : public CDialogEx
{
// ����
public:
	CDialogDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	enum {
       TAB_MODE_WARN,
       TAB_MODE_REMOTE_CONTRL
	};
	//CDialog1 m_dialog1;
	CDialog2 m_dialog2;
	CDialog3 m_dialog3;
	CDialog *m_pPage[2];
	int m_cur_mode_sel;
	CTabCtrl m_tab;
public:
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
