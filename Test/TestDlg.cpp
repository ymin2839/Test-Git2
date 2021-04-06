#include "pch.h"
#include "Test.h"
#include "TestDlg.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TEST_DIALOG, pParent)
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
END_MESSAGE_MAP()


BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	AfxMessageBox(L"마스터:킷허브에서 만들어 짐");	

	return TRUE;
}

