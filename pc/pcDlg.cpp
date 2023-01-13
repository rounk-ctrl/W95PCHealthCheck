// pcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pc.h"
#include "pcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef BOOL (WINAPI *P_GDFSE)(LPCTSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);

///
/// CRenameDlg
///
class CRenameDlg : public CDialog
{
public:
	CRenameDlg();
	TCHAR pcname;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RENAME };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnButtonOK();

// Implementation
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

CRenameDlg::CRenameDlg() : CDialog(IDD_RENAME)
{
}

void CRenameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRenameDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDOK, OnButtonOK)
END_MESSAGE_MAP()

BOOL CRenameDlg::OnInitDialog()
{
	return TRUE;
}
void CRenameDlg::OnButtonOK()
{
	::GetWindowText(GetDlgItem(IDEDIT)->m_hWnd, &pcname, MAX_COMPUTERNAME_LENGTH);
	EndDialog(IDOK);
	return;
}

///
/// CUnsupportedDlg
///
class CUnsupportedDlg : public CDialog
{
public:
	CUnsupportedDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UNSUPP };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnButtonOK();

// Implementation
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

CUnsupportedDlg::CUnsupportedDlg() : CDialog(IDD_UNSUPP)
{
}

void CUnsupportedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUnsupportedDlg, CDialog)
	ON_WM_SYSCOMMAND()
	//ON_BN_CLICKED(IDOK, OnButtonOK)
END_MESSAGE_MAP()

BOOL CUnsupportedDlg::OnInitDialog()
{
	HFONT hFont = CreateFont (20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, 
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
      DEFAULT_PITCH | FF_DONTCARE, TEXT("MS Sans Serif"));
	::SendMessage(GetDlgItem(IDTITLE2)->m_hWnd, WM_SETFONT, (int)hFont, TRUE);

	CString thing = "This processor isn't supported for Windows 11.\nWhile this PC doesn't meet the system  requirements to run Windows 11, you'll keep getting ";
	CString osname = "unknown";
	OSVERSIONINFO os;
	ZeroMemory(&os, sizeof(OSVERSIONINFO));
    os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if (os.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		if (os.dwMajorVersion == 4 && os.dwMinorVersion == 0)
			osname = "Windows NT 4";
		else if (os.dwMajorVersion == 5 && os.dwMinorVersion == 0)
			osname = "Windows 2000";
		else if (os.dwMajorVersion == 5 && os.dwMinorVersion == 1)
			osname = "Windows XP";
		else if (os.dwMajorVersion == 5 && os.dwMinorVersion == 2)
			osname = "Windows Server 2003";
		else if (os.dwMajorVersion == 6 && os.dwMinorVersion == 0)
			osname = "Windows Vista";
		else if (os.dwMajorVersion == 6 && os.dwMinorVersion == 1)
			osname = "Windows 7";
		else if (os.dwMajorVersion == 6 && os.dwMinorVersion == 2)
			osname = "Windows 8";
	}
	else
	{
		if (os.dwMajorVersion == 4 && os.dwMinorVersion == 00)
			osname = "Windows 95";
		else if (os.dwMajorVersion == 4 && os.dwMinorVersion == 03)
			osname = "Windows 95";
		else if (os.dwMajorVersion == 4 && os.dwMinorVersion == 10)
			osname = "Windows 98";
		else if (os.dwMajorVersion == 4 && os.dwMinorVersion == 90)
			osname = "Windows ME";
	}
	CString final = thing + osname + " updates.";
	::SetWindowText(GetDlgItem(IDCABTDESC)->m_hWnd, final);
	return TRUE;
}
/*
void CUnsupportedDlg::OnButtonOK()
{
	::GetWindowText(GetDlgItem(IDEDIT)->m_hWnd, &pcname, MAX_COMPUTERNAME_LENGTH);
	EndDialog(IDOK);
	return;
}
*/

/////////////////////////////////////////////////////////////////////////////
// CPcDlg dialog

CPcDlg::CPcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPcDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPcDlg, CDialog)
	//{{AFX_MSG_MAP(CPcDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDRENAME, OnButton1)
	ON_BN_CLICKED(IDCHECK, OnButton2)
	ON_BN_CLICKED(IDABOUT, OnButton3)
	ON_BN_CLICKED(IDCABTPIC, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPcDlg message handlers

BOOL CPcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	// SetIcon(m_hIcon, TRUE);			// Set big icon
	// SetIcon(m_hIcon, FALSE);	     	// Set small icon
	
	HFONT hFont = CreateFont (20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, 
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
      DEFAULT_PITCH | FF_DONTCARE, TEXT("MS Sans Serif"));
	::SendMessage(GetDlgItem(IDTITLE)->m_hWnd, WM_SETFONT, (int)hFont, TRUE);

	
	hFont = CreateFont (15, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, 
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
      DEFAULT_PITCH | FF_DONTCARE, TEXT("MS Sans Serif"));
	::SendMessage(GetDlgItem(IDPCNAME)->m_hWnd, WM_SETFONT, (int)hFont, TRUE);

	// pc name
	TCHAR computername[100];
	DWORD  bufCharCount = 100;
	::GetComputerName(computername, &bufCharCount);
	::SetWindowText(GetDlgItem(IDPCNAME)->m_hWnd, computername);

	// ram
	MEMORYSTATUS statex;
	::GlobalMemoryStatus (&statex);
	char buffer[101];
	sprintf(buffer, "%d MB RAM", statex.dwTotalPhys/(1024*1024));
	::SetWindowText(GetDlgItem(IDRAM)->m_hWnd, buffer);

	// disk space
	BOOL  fResult;
	char  *pszDrive = NULL, szDrive[4];
	DWORD dwSectPerClust, dwBytesPerSect, dwFreeClusters, dwTotalClusters;
	P_GDFSE pGetDiskFreeSpaceEx = NULL;
	unsigned __int64 i64FreeBytesToCaller, i64TotalBytes, i64FreeBytes;
	szDrive[0] = 'C';
	szDrive[1] = ':';
	szDrive[2] = '\\';
	szDrive[3] = '\0';
	pGetDiskFreeSpaceEx = (P_GDFSE)GetProcAddress(GetModuleHandle ("kernel32.dll"),"GetDiskFreeSpaceExA");
	if (pGetDiskFreeSpaceEx)
	{
		fResult = pGetDiskFreeSpaceEx (pszDrive, (PULARGE_INTEGER)&i64FreeBytesToCaller, (PULARGE_INTEGER)&i64TotalBytes, (PULARGE_INTEGER)&i64FreeBytes);
	}
	else
	{
		fResult = GetDiskFreeSpace (pszDrive, &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);
		if (fResult)
		{
			i64TotalBytes = dwTotalClusters * dwSectPerClust * dwBytesPerSect;
			i64FreeBytes = dwFreeClusters * dwSectPerClust * dwBytesPerSect;
		 }
	}
	if (fResult)
	{
		char space[256];
		sprintf(space, "%d MB HDD", i64TotalBytes / (1024*1024));
		::SetWindowText(GetDlgItem(IDHDD)->m_hWnd, space);
		
		// % full
		char percent[256];
		int ok = (int)((i64TotalBytes-i64FreeBytes)*100/i64TotalBytes*100)/100;
		sprintf(percent, "%d%% full", ok);
		::SetWindowText(GetDlgItem(IDSPACE)->m_hWnd, percent);
	}

	// age
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	char year[101];
	sprintf(year, "%d years old", lt.wYear - 1995);
	::SetWindowText(GetDlgItem(IDAGE)->m_hWnd, year);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL SystemShutdown()
{

	OSVERSIONINFO os;
	ZeroMemory(&os, sizeof(OSVERSIONINFO));
    os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if(os.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{

	HANDLE hToken; 
	TOKEN_PRIVILEGES tkp; 
 
	// Get a token for this process. 
 
	if (!OpenProcessToken(GetCurrentProcess(), 
		    TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
		return( FALSE ); 
 
	// Get the LUID for the shutdown privilege. 
 
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
			&tkp.Privileges[0].Luid); 
 
	tkp.PrivilegeCount = 1;  // one privilege to set    
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
 
	// Get the shutdown privilege for this process. 
 
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
		    (PTOKEN_PRIVILEGES)NULL, 0); 
 
	if (GetLastError() != ERROR_SUCCESS) 
		  return FALSE; 
	}
	// Shut down the system and force all applications to close. 
 
	if (!ExitWindowsEx(EWX_REBOOT, 0))
		return FALSE; 

	//shutdown was successful
	return TRUE;
}

void CPcDlg::OnButton1() 
{
	CRenameDlg rendlg;
	int result = rendlg.DoModal();
	if (result == IDOK)
	{
		bool ret = SetComputerName(&rendlg.pcname);
		if (ret == 1)
		{
			int dialogres = MessageBox("You need to reboot in order to apply the changes to this PC. Reboot now?", "Rename this PC", MB_YESNO | MB_ICONINFORMATION);
			if (dialogres == IDYES)
			{
				SystemShutdown();
			}
		}
		else
		{
			MessageBox("error", 0,0);
		}
	}
}
void CPcDlg::OnButton2() 
{
	CUnsupportedDlg dlg;
	dlg.DoModal();
}

void CPcDlg::OnButton3() 
{
	MessageBox("W95 PC Health Check\nVersion 1.0", "About", MB_OK | MB_ICONINFORMATION);
}
