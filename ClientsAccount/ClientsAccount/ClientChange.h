#pragma once


// Диалоговое окно ClientChange

class ClientChange : public CDialog
{
	DECLARE_DYNAMIC(ClientChange)

public:
	ClientChange(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ClientChange();

	BOOL OnInitDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGECLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_surnametext;
	CString m_nametext;
	CString m_patronimyctext;
};
