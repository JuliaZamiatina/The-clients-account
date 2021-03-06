
// ClientsAccountDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "ClientsAccount.h"
#include "ClientsAccountDlg.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "ClientAdd.h"
#include "ClientChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CClientsAccountDlg



CClientsAccountDlg::CClientsAccountDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CLIENTSACCOUNT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientsAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, allClientsList, m_allClientsList);
}

BEGIN_MESSAGE_MAP(CClientsAccountDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(deleteClientButton, &CClientsAccountDlg::OnBnClickeddeleteclientbutton)
	ON_BN_CLICKED(addClientButton, &CClientsAccountDlg::OnBnClickedaddclientbutton)
	ON_BN_CLICKED(changeClientDataButton, &CClientsAccountDlg::OnBnClickedchangeclientdatabutton)
END_MESSAGE_MAP()


// Обработчики сообщений CClientsAccountDlg

BOOL CClientsAccountDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	ListInitialise();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CClientsAccountDlg::ListInitialise()
{
	m_allClientsList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_allClientsList.InsertColumn(0, L"№", 0, 30);
	m_allClientsList.InsertColumn(1, L"Фамилия", 0, 170);
	m_allClientsList.InsertColumn(2, L"Имя", 0, 120);
	m_allClientsList.InsertColumn(3, L"Отчество", 0, 150);

	CDatabase cdbMyDB;
	cdbMyDB.Open(L"ClientDataBase");

	CRecordset cr(&cdbMyDB);

	cr.Open(CRecordset::forwardOnly, L"SELECT КОД FROM ФИО;", CRecordset::readOnly);
	CString var;
	short index = 0;
	short col = 0;
	while (!cr.IsEOF())
	{
		cr.GetFieldValue(index, var);
		m_allClientsList.InsertItem(col, LPCTSTR(var));
		col++;
		cr.MoveNext();
	}
	cr.Close();

	cr.Open(CRecordset::forwardOnly, L"SELECT ФАМИЛИЯ FROM ФИО;", CRecordset::readOnly);
	index = 0;
	col = 0;
	while (!cr.IsEOF())
	{
		cr.GetFieldValue(index, var);
		m_allClientsList.SetItemText(col, 1, LPCTSTR(var));
		col++;
		cr.MoveNext();
	}
	cr.Close();

	cr.Open(CRecordset::forwardOnly, L"SELECT ИМЯ FROM ФИО;", CRecordset::readOnly);
	index = 0;
	col = 0;
	while (!cr.IsEOF())
	{
		cr.GetFieldValue(index, var);
		m_allClientsList.SetItemText(col, 2, LPCTSTR(var));
		col++;
		cr.MoveNext();
	}
	cr.Close();

	cr.Open(CRecordset::forwardOnly, L"SELECT ОТЧЕСТВО FROM ФИО;", CRecordset::readOnly);
	index = 0;
	col = 0;
	while (!cr.IsEOF())
	{
		cr.GetFieldValue(index, var);
		m_allClientsList.SetItemText(col, 3, LPCTSTR(var));
		col++;
		cr.MoveNext();
	}
	cr.Close();
	cdbMyDB.Close();
}

void CClientsAccountDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CClientsAccountDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CClientsAccountDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClientsAccountDlg::OnBnClickeddeleteclientbutton()
{
	if (m_allClientsList.GetSelectionMark() == -1)
	{
		MessageBox(L"Вы не выбрали клиента", L"Ошибка", MB_OK | MB_ICONERROR);
		return;
	}
	int answer = MessageBox(L"Вы действительно хотите удалить клиента?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION);
	if (answer == IDNO) return;	
	
	CDatabase cdbMyDB;
	cdbMyDB.Open(L"ClientDataBase");

	int i = m_allClientsList.GetSelectionMark()+1;

	CString str1;
	
	str1.Format(L"DELETE FROM ФИО WHERE КОД=%d", i);
	cdbMyDB.ExecuteSQL(str1);
	cdbMyDB.Close();

	m_allClientsList.DeleteItem(m_allClientsList.GetSelectionMark());
}


void CClientsAccountDlg::OnBnClickedaddclientbutton()
{
	ClientAdd diag;
	if (diag.DoModal() == IDOK)
	{
		int raw = _ttoi(m_allClientsList.GetItemText(m_allClientsList.GetItemCount() - 1, 0));
		CString t;
		t.Format(_T("%d"), raw+1);
		raw = m_allClientsList.GetItemCount();
		int n = m_allClientsList.InsertItem(raw, t);
		m_allClientsList.SetItemText(raw, 1, diag.m_surnametext);
		m_allClientsList.SetItemText(raw, 2, diag.m_nametext);
		m_allClientsList.SetItemText(raw, 3, diag.m_patronimyctext);

		CDatabase cdbMyDB;
		cdbMyDB.Open(L"ClientDataBase");
	
		CString str1;

		str1.Format(L"INSERT INTO ФИО (Код, Фамилия, Имя, Отчество) VALUES (%s, '%s', '%s', '%s')", t, diag.m_surnametext, diag.m_nametext, diag.m_patronimyctext);
		cdbMyDB.ExecuteSQL(str1);
		cdbMyDB.Close();
	}
}


void CClientsAccountDlg::OnBnClickedchangeclientdatabutton()
{
	if (m_allClientsList.GetSelectionMark() == -1)
	{
		MessageBox(L"Вы не выбрали клиента", L"Ошибка", MB_OK | MB_ICONERROR);
		return;
	}
	ClientChange diag(this);
	if (diag.DoModal() == IDOK)
	{
		int raw = m_allClientsList.GetSelectionMark();
		m_allClientsList.SetItemText(raw, 1, diag.m_surnametext);
		m_allClientsList.SetItemText(raw, 2, diag.m_nametext);
		m_allClientsList.SetItemText(raw, 3, diag.m_patronimyctext);

		CDatabase cdbMyDB;
		cdbMyDB.Open(L"ClientDataBase");

		CString str1;

		str1.Format(L"UPDATE ФИО SET Фамилия = '%s', Имя = '%s', Отчество = '%s' WHERE Код = %s", diag.m_surnametext, diag.m_nametext, diag.m_patronimyctext, m_allClientsList.GetItemText(raw,0));
		cdbMyDB.ExecuteSQL(str1);
		cdbMyDB.Close();
	}
}