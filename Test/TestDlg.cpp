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
	AfxMessageBox(L"마스터:되돌리기 했더니 이전으로 돌아갔음");

	return TRUE;
}

