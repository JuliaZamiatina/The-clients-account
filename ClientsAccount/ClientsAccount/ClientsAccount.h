
// ClientsAccount.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CClientsAccountApp:
// Сведения о реализации этого класса: ClientsAccount.cpp
//

class CClientsAccountApp : public CWinApp
{
public:
	CClientsAccountApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CClientsAccountApp theApp;
