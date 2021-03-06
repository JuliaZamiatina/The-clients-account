// ClientChange.cpp: файл реализации
//

#include "stdafx.h"
#include "ClientsAccount.h"
#include "ClientsAccountDlg.h"
#include "ClientChange.h"
#include "afxdialogex.h"


// Диалоговое окно ClientChange

IMPLEMENT_DYNAMIC(ClientChange, CDialog)

ClientChange::ClientChange(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHANGECLIENT, pParent)
	, m_surnametext(_T(""))
	, m_nametext(_T(""))
	, m_patronimyctext(_T(""))
{
}

ClientChange::~ClientChange()
{
}

BOOL ClientChange::OnInitDialog()
{
	CClientsAccountDlg  *pMain = (CClientsAccountDlg *)GetParent();
	CEdit* e = (CEdit*)GetDlgItem(SURNAMETEXT); 
	e->SetWindowText(pMain->m_allClientsList.GetItemText(pMain->m_allClientsList.GetSelectionMark(), 1));
	e = (CEdit*)GetDlgItem(NAMETEXT);
	e->SetWindowText(pMain->m_allClientsList.GetItemText(pMain->m_allClientsList.GetSelectionMark(), 2));
	e = (CEdit*)GetDlgItem(PATRONIMYCTEXT);
	e->SetWindowText(pMain->m_allClientsList.GetItemText(pMain->m_allClientsList.GetSelectionMark(), 3));
	return TRUE;
}

void ClientChange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, SURNAMETEXT, m_surnametext);
	DDX_Text(pDX, NAMETEXT, m_nametext);
	DDX_Text(pDX, PATRONIMYCTEXT, m_patronimyctext);
}


BEGIN_MESSAGE_MAP(ClientChange, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений ClientChange
