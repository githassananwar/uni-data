
// task2View.cpp : implementation of the Ctask2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "task2.h"
#endif

#include "task2Doc.h"
#include "task2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctask2View

IMPLEMENT_DYNCREATE(Ctask2View, CView)

BEGIN_MESSAGE_MAP(Ctask2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Ctask2View construction/destruction

Ctask2View::Ctask2View()
{
	// TODO: add construction code here

}

Ctask2View::~Ctask2View()
{
}

BOOL Ctask2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Ctask2View drawing

void Ctask2View::OnDraw(CDC* pDC)
{
	Ctask2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	point p1,p2 ; p1.x = 300 ; p1.y = 0 ;p2.x = 400 ; p2.y = 50 ;

	Triangle T = pDoc->tri ;
	pDC->MoveTo(T.getinitial().x, T.getinitial().y);
	pDC->LineTo(T.getfinal().x, T.getfinal().y);

	pDC->MoveTo(T.getfinal().x, T.getfinal().y);
	pDC->LineTo(T.getinitial().x, T.getfinal().y);

	pDC->MoveTo(T.getinitial().x, T.getfinal().y);
	pDC->LineTo(T.getinitial().x,T.getinitial().y);
	
	T.rotateRight();
	
	pDC->MoveTo(T.getinitial().x, T.getinitial().y);
	pDC->LineTo(T.getfinal().x, T.getfinal().y);

	pDC->MoveTo(T.getfinal().x, T.getfinal().y);
	pDC->LineTo(T.getfinal().x, T.getinitial().y);

	pDC->MoveTo(T.getfinal().x, T.getinitial().y);
	pDC->LineTo(T.getinitial().x,T.getinitial().y);

	T.rotateRight();
	
	pDC->MoveTo(T.getinitial().x, T.getinitial().y);
	pDC->LineTo(T.getfinal().x, T.getfinal().y);

	pDC->MoveTo(T.getfinal().x, T.getfinal().y);
	pDC->LineTo(T.getinitial().x, T.getfinal().y);

	pDC->MoveTo(T.getinitial().x, T.getfinal().y);
	pDC->LineTo(T.getinitial().x,T.getinitial().y);

	T.rotateRight();

	pDC->MoveTo(T.getinitial().x, T.getinitial().y);
	pDC->LineTo(T.getfinal().x, T.getfinal().y);

	pDC->MoveTo(T.getfinal().x, T.getfinal().y);
	pDC->LineTo(T.getfinal().x, T.getinitial().y);

	pDC->MoveTo(T.getfinal().x, T.getinitial().y);
	pDC->LineTo(T.getinitial().x,T.getinitial().y);
	
	
	p1.x = 300 ; p1.y = 55 ;p2.x = 400 ; p2.y = 100 ; 
	Rect R = pDoc->rec ;
	pDC->Rectangle(R.getinitial().x, R.getinitial().y, R.getfinal().x, R.getfinal().y);	

	
	Circ c =pDoc->cir ;
	pDC->Ellipse(450,103,600,300);

	

	// TODO: add draw code for native data here
}

void Ctask2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctask2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctask2View diagnostics

#ifdef _DEBUG
void Ctask2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctask2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctask2Doc* Ctask2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctask2Doc)));
	return (Ctask2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctask2View message handlers
