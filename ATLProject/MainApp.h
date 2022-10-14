#pragma once
#include "MainFrame.h"

class CMainApp
{
    private :
        CMainFrame m_MainFrame ; 
        HMENU m_hMenu ;
    public :
        CMainApp() ; 
        ~CMainApp() ; 
    public :
        int Run(HINSTANCE hInstance, int nCmdShow) ; 
    public :    
        static CMainApp &GetInstance() ; 
        static void Release() ; 
} ;

