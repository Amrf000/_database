// Dialog1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dialog.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// CDialog1 �Ի���

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


// CDialog1 ��Ϣ�������


void CDialog1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDragDialog::OnPaint()
	CDragDialog::OnPaint();
}
