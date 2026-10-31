// OptionsSheet.cpp : implementation file
//

#include "stdafx.h"
#include "CP_Main.h"
#include "OptionsSheet.h"
#include "OptionsKeyBoard.h"
#include "OptionsGeneral.h"
#include "OptionsQuickPaste.h"
#include "OptionsStats.h"
#include "OptionsTypes.h"
#include "About.h"
#include "OptionFriends.h"
#include "OptionsCopyBuffers.h"
#include "Misc.h"
#include "QuickPasteKeyboard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif 


/////////////////////////////////////////////////////////////////////////////
// COptionsSheet

IMPLEMENT_DYNAMIC(COptionsSheet, CPropertySheet)

COptionsSheet::COptionsSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_themeChanged = FALSE;
	m_pKeyBoardOptions = NULL;
	m_pGeneralOptions = NULL;
	//m_pQuickPasteOptions = NULL;
	m_pCopyBuffers = NULL;
	m_pStats = NULL;
	m_pTypes = NULL;
	m_pAbout = NULL;
	m_pFriends = NULL;
	m_pCopyBuffers = NULL;
	m_pQuickPasteShortCuts = NULL;
	
	m_pUtilites = NULL;
	m_hWndParent = NULL;
	m_backgroundColor = CLR_INVALID;

	EnableStackedTabs(TRUE);

	m_pGeneralOptions = new COptionsGeneral;
	m_pKeyBoardOptions = new COptionsKeyBoard;
	//m_pQuickPasteOptions = new COptionsQuickPaste;
	m_pQuickPasteShortCuts = new CQuickPasteKeyboard;

	m_pCopyBuffers = new COptionsCopyBuffers;
	m_pStats = new COptionsStats;
	m_pTypes = new COptionsTypes;
	m_pAbout = new CAbout;

	AddPage(m_pGeneralOptions);
	AddPage(m_pTypes);
	AddPage(m_pKeyBoardOptions);
	AddPage(m_pCopyBuffers);
	//AddPage(m_pQuickPasteOptions);
	AddPage(m_pQuickPasteShortCuts);
	if(CGetSetOptions::GetAllowFriends())
	{
		m_pFriends = new COptionFriends;
		AddPage(m_pFriends);
	}
	AddPage(m_pStats);
	AddPage(m_pAbout);

	
}

COptionsSheet::~COptionsSheet()
{
	delete m_pGeneralOptions;
	delete m_pKeyBoardOptions;
	//delete m_pQuickPasteOptions;
	delete m_pCopyBuffers;
	delete m_pStats;
	delete m_pTypes;
	delete m_pAbout;	
	delete m_pFriends;
	delete m_pUtilites;
	delete m_pQuickPasteShortCuts;	
}

BEGIN_MESSAGE_MAP(COptionsSheet, CPropertySheet)
	//{{AFX_MSG_MAP(COptionsSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_WM_DESTROY()
	ON_WM_NCDESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	//ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsSheet message handlers

void COptionsSheet::OnDestroy()
{
	CPropertySheet::OnDestroy();
}

void COptionsSheet::SetNotifyWnd(HWND hWnd)
{
	m_hWndParent = hWnd;
}

BOOL COptionsSheet::OnInitDialog() 
{
	m_bModeless = FALSE;   
	m_nFlags |= WF_CONTINUEMODAL;

	HICON b = (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME), IMAGE_ICON, 64, 64, LR_SHARED);
	SetIcon(b, TRUE);

	BOOL bResult = CPropertySheet::OnInitDialog();

	SetWindowText(_T("Options"));

	theApp.m_Language.UpdateOptionsSheet(this);

	::ShowWindow(::GetDlgItem(m_hWnd, ID_APPLY_NOW), SW_HIDE);

	m_bModeless = TRUE;
	m_nFlags &= ~WF_CONTINUEMODAL;

	return bResult;
}

// The sheet's margins (above the tabs, beside them, around OK/Cancel) are
// painted with the COLOR_BTNFACE brush by default. Windowing mods that recolour
// system colours for acrylic (Windhawk translucent-windows) turn that brush
// black, and with no backdrop behind the sheet the margins render pitch black.
// Paint them with the Ditto theme background through our own brush instead.
CBrush &COptionsSheet::BackgroundBrush()
{
	COLORREF color = CGetSetOptions::m_Theme.MainWindowBG();
	if (color != m_backgroundColor || m_backgroundBrush.GetSafeHandle() == NULL)
	{
		m_backgroundBrush.DeleteObject();
		m_backgroundBrush.CreateSolidBrush(color);
		m_backgroundColor = color;
	}
	return m_backgroundBrush;
}

BOOL COptionsSheet::OnEraseBkgnd(CDC* pDC)
{
	CRect rc;
	GetClientRect(rc);
	pDC->FillRect(rc, &BackgroundBrush());
	return TRUE;
}

HBRUSH COptionsSheet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	if (nCtlColor == CTLCOLOR_DLG)
	{
		return (HBRUSH)BackgroundBrush().GetSafeHandle();
	}
	return CPropertySheet::OnCtlColor(pDC, pWnd, nCtlColor);
}

void COptionsSheet::OnNcDestroy()
{
	CPropertySheet::OnNcDestroy();
	::PostMessage(m_hWndParent, WM_OPTIONS_CLOSED, m_themeChanged, 0);
}
