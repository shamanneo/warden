#include "pch.h"
#include "Resource.h"
#include "MainApp.h"

static CMainApp *g_pMainApp = nullptr ; 

CMainApp::CMainApp()
{

}

CMainApp::~CMainApp()
{

}

int CMainApp::Run(HINSTANCE hInstance, int nCmdShow)
{
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ATLPROJECT)) ;
    MSG msg ;
    CRect rc { 0, 0, 790, 824 } ; 
    m_MainFrame.Create(
        NULL, 
        rc, 
        _T("Warden"), 
        WS_OVERLAPPEDWINDOW,
        NULL,
        IDR_MAIN_MENU
    ) ; 
    m_MainFrame.ShowWindow(nCmdShow) ; 
    m_MainFrame.CenterWindow() ; 
    m_MainFrame.UpdateWindow() ; 
    while(::GetMessage(&msg, nullptr, 0, 0)) // main message loop.
    {
        if(!::TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            ::TranslateMessage(&msg) ;
            ::DispatchMessage(&msg) ;
        }
    }
    return static_cast<int>(msg.wParam) ; 
}

//      static 

CMainApp &CMainApp::GetInstance() 
{
    if(g_pMainApp == nullptr)
    {
        g_pMainApp = new CMainApp ; 
    }
    return *g_pMainApp ; 
}

void CMainApp::Release()
{
    if(g_pMainApp != nullptr)
    {
        delete g_pMainApp ; 
        g_pMainApp = nullptr ; 
    }
}
