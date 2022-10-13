#pragma once
#include "View.h"

class CLoginView : public CView
{
    public :
        CLoginView() ; 
        virtual ~CLoginView() override ; 
    public :
        virtual void Draw(HDC hDC) override ;
} ;

