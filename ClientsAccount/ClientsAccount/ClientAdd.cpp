// ClientAdd.cpp: файл реализации
//

#include "stdafx.h"
#include "ClientsAccount.h"
#include "ClientAdd.h"
#include "afxdialogex.h"


// Диалоговое окно ClientAdd

IMPLEMENT_DYNAMIC(ClientAdd, CDialog)

ClientAdd::ClientAdd(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ADDCLIENT, pParent)
	, m_surnametext(_T(""))
	, m_nametext(_T(""))
	, m_patronimyctext(_T(""))
{

}

ClientAdd::~ClientAdd()
{
}

void ClientAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, SURNAMETEXT, m_surnametext);
	DDX_Text(pDX, NAMETEXT, m_nametext);
	DDX_Text(pDX, PATRONIMYCTEXT, m_patronimyctext);
}


BEGIN_MESSAGE_MAP(ClientAdd, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений ClientAdd
