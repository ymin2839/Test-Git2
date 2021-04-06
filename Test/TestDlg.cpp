﻿#include "pch.h"
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
	AfxMessageBox(L"마스터:다시설정 변경내용 유지 했더니 변경내용으로 나왔음 아마 내용 삭제 했으면 윗줄 없어 질듯");
	AfxMessageBox(L"마스터:다시설정 했더니 같은 소스 변경 되서 그런지 병합나왔음");
	AfxMessageBox(L"마스터:지우는거 성공 되돌리기 하면 지워진다.");
	AfxMessageBox(L"분기:생성");
	AfxMessageBox(L"분기:커밋&푸시");
	L"이 분기를 다시 마스터에 넣어야지";

	return TRUE;
}

