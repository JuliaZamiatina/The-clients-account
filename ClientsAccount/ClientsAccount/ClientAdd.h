#pragma once


// Диалоговое окно ClientAdd

class ClientAdd : public CDialog
{
	DECLARE_DYNAMIC(ClientAdd)

public:
	ClientAdd(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ClientAdd();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDCLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_surnametext;
	CString m_nametext;
	CString m_patronimyctext;
};
