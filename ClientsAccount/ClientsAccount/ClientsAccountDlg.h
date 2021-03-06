
// ClientsAccountDlg.h: файл заголовка
//

#pragma once
#include "afxcmn.h"


// Диалоговое окно CClientsAccountDlg
class CClientsAccountDlg : public CDialog
{
// Создание
public:
	CClientsAccountDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENTSACCOUNT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	void ListInitialise();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_allClientsList;
	afx_msg void OnBnClickeddeleteclientbutton();
	afx_msg void OnBnClickedaddclientbutton();
	afx_msg void OnBnClickedchangeclientdatabutton();
};
