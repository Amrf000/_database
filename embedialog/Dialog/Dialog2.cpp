// Dialog2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dialog.h"
#include "Dialog2.h"
#include "afxdialogex.h"


// CDialog2 �Ի���

IMPLEMENT_DYNAMIC(CDialog2, CDragDialog)

CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDragDialog(IDD_DIALOG2, pParent)
{

}

CDialog2::~CDialog2()
{
}

void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDragDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog2, CDragDialog)
END_MESSAGE_MAP()


// CDialog2 ��Ϣ�������
