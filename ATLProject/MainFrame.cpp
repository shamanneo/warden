#include "pch.h"
#include "LoginView.h"
#include "constants.h"
#include "MainFrame.h"

CMainFrame::CMainFrame()
{
    
}

CMainFrame::~CMainFrame()
{

}

LRESULT CMainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    CRect rcMain ; 
    GetClientRect(&rcMain) ; 
    CRect rc { 0, 0, 774, 765 } ; 
    m_apView.Attach(new CLoginView) ; // First program view.
    m_apView->Create(
        m_hWnd, 
        rc, 
        NULL, 
        WS_EX_CHILDWINDOW,
        NULL
    ) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    return 0 ; 
}

LRESULT CMainFrame::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ; 

    EndPaint(&ps) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    m_nWidth = LOWORD(lParam) ; 
    m_nHeight = HIWORD(wParam) ; 
    return 0 ;
}

LRESULT CMainFrame::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PostQuitMessage(0) ; 
    return 0 ; 
}