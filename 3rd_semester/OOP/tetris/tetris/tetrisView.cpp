
// tetrisView.cpp : implementation of the CtetrisView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "tetris.h"
#endif

#include "tetrisDoc.h"
#include "tetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtetrisView

IMPLEMENT_DYNCREATE(CtetrisView, CView)

BEGIN_MESSAGE_MAP(CtetrisView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CtetrisView construction/destruction

CtetrisView::CtetrisView()
{
	// TODO: add construction code here

}

CtetrisView::~CtetrisView()
{
}

BOOL CtetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CtetrisView drawing

void CtetrisView::OnDraw(CDC* pDC)
{
	CtetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here

	pDoc->g.clearCompleteRows() ;

	int nDCSave = pDC->SaveDC();
	//  Get the client rectangle
	CRect rcClient;
	GetClientRect(&rcClient);
	//  Get the background color of the board
	COLORREF clr = pDoc->g.getCellColor(0,0);
	//	Draw the background first
	pDC->FillSolidRect(&rcClient, clr);
	//  Create the brush for drawing
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	//	Draw the squares
	for(int r = 0; r < pDoc->g.getrow(); r++)
	{
		for(int c = 0; c < pDoc->g.getcol(); c++)
		{
			//  Get the color for this board space
			clr = pDoc->g.getCellColor(c, r);
			//  Calculate the size and position of this space
			CRect rcBlock;
			rcBlock.top = r * BLOCK_HEIGHT ;
			rcBlock.left = c * BLOCK_WIDTH ;
			rcBlock.right = rcBlock.left + BLOCK_WIDTH ;
			rcBlock.bottom = rcBlock.top + BLOCK_HEIGHT ;
	 
			//  Fill in the block with the correct color
			pDC->FillSolidRect(&rcBlock,clr);
			//  Draw the block outline
			pDC->Rectangle(&rcBlock);
		}	
	 }

	if(!pDoc->g.isGameOver())
	{
		GetClientRect(&rcClient);
		RedrawWindow(rcClient,0,RDW_ERASE|RDW_INVALIDATE);
		DrawPiece(pDC);
		Sleep(375);
	}

	//  Restore the device context settings
	pDC->RestoreDC(nDCSave);
	br.DeleteObject();

}


void CtetrisView::DrawPiece(CDC* pDC)
{
	CtetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//Four block points to access colors
	Pt block1, block2, block3, block4 ;

	block1=pDoc->g.getPtr()->getfptr()->blockPts[0];
	block1.x = block1.x + pDoc->g.getCurrentCol();
	block1.y = block1.y + pDoc->g.getCurrentRow();

	block2=pDoc->g.getPtr()->getfptr()->blockPts[1];
	block2.x = block2.x + pDoc->g.getCurrentCol();
	block2.y = block2.y + pDoc->g.getCurrentRow();

	block3=pDoc->g.getPtr()->getfptr()->blockPts[2];
	block3.x = block3.x + pDoc->g.getCurrentCol();
	block3.y = block3.y + pDoc->g.getCurrentRow();

	block4=pDoc->g.getPtr()->getfptr()->blockPts[3];
	block4.x = block4.x + pDoc->g.getCurrentCol();
	block4.y = block4.y + pDoc->g.getCurrentRow();

	if(pDoc->g.getPtr()->getfptr()->maxima + pDoc->g.getCurrentRow() < 20 
	&& pDoc->g.getCellColor(block1.x,block1.y) == colorArray[0]
	&& pDoc->g.getCellColor(block2.x,block2.y) == colorArray[0]
	&& pDoc->g.getCellColor(block3.x,block3.y) == colorArray[0]
	&& pDoc->g.getCellColor(block4.x,block4.y) == colorArray[0]
	 )
	{
		
		for (int i=0; i < 4; i++)
		{

			int getx=pDoc->g.getPtr()->getfptr()->blockPts[i].x;
			int gety=pDoc->g.getPtr()->getfptr()->blockPts[i].y;

			COLORREF clr = colorArray[pDoc->g.getcolor()] ;
			//  Calculate the size and position of this space
			CRect rcBlock;
			rcBlock.top = (pDoc->g.getCurrentRow() + gety) * 30 ;
			rcBlock.left = (pDoc->g.getCurrentCol() + getx) * 30 ;
			rcBlock.right = rcBlock.left + 30 ;
			rcBlock.bottom = rcBlock.top + 30 ;
			//  Fill in the block with the correct color
			pDC->FillSolidRect(&rcBlock, clr);
			//  Draw the block outline
			pDC->Rectangle(&rcBlock);
		}

		//and go to Next row
		pDoc->g.updateCrow(1);

	}
	else
	{
		pDoc->g.updateCrow(-1) ;
		for (int i=0; i < 4; i++)
		{

			int getx=pDoc->g.getPtr()->getfptr()->blockPts[i].x;
			int gety=pDoc->g.getPtr()->getfptr()->blockPts[i].y;

			COLORREF clr = colorArray[pDoc->g.getcolor()] ;
			//  Calculate the size and position of this space
			CRect rcBlock;
			rcBlock.top = (pDoc->g.getCurrentRow() + gety) * 30 ;
			rcBlock.left = (pDoc->g.getCurrentCol() + getx) * 30 ;
			rcBlock.right = rcBlock.left + 30 ;
			rcBlock.bottom = rcBlock.top + 30 ;
			//  Fill in the block with the correct color
			pDC->FillSolidRect(&rcBlock, clr);
			//  Draw the block outline
			pDC->Rectangle(&rcBlock);
		}

		pDoc->g.setCellColor(block1.x, block1.y-1, pDoc->g.getcolor()) ;
		pDoc->g.setCellColor(block2.x, block2.y-1, pDoc->g.getcolor()) ;
		pDoc->g.setCellColor(block3.x, block3.y-1, pDoc->g.getcolor()) ;
		pDoc->g.setCellColor(block4.x, block4.y-1, pDoc->g.getcolor()) ;

		pDoc->g.selectNextPiece() ;
		pDoc->g.setCurrentRow(0) ;
		pDoc->g.setCurrentCol(6) ;

	}	

}

void CtetrisView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CtetrisView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CtetrisView diagnostics

#ifdef _DEBUG
void CtetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CtetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtetrisDoc* CtetrisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtetrisDoc)));
	return (CtetrisDoc*)m_pDocument;
}
#endif //_DEBUG

void CtetrisView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	ResizeWindow();
}

void CtetrisView::ResizeWindow()
{
  //  First get a pointer to the document
  CtetrisDoc* pDoc = GetDocument();
  ASSERT_VALID(pDoc);
  if(!pDoc)
    return;
  //  Get the size of the client area and the window
  CRect rcClient, rcWindow;
  GetClientRect(&rcClient);
  GetParentFrame()->GetWindowRect(&rcWindow);
  //  Calculate the difference
  int nWidthDiff = rcWindow.Width() - rcClient.Width();
  int nHeightDiff = rcWindow.Height() - rcClient.Height();
  //  Change the window size based on the size of the game board
  rcWindow.right = rcWindow.left +
	  BLOCK_WIDTH * pDoc->g.getcol() + nWidthDiff;
  rcWindow.bottom = rcWindow.top +
	  BLOCK_HEIGHT * pDoc->g.getrow() + nHeightDiff;
  //  The MoveWindow function resizes the frame window
  GetParentFrame()->MoveWindow(&rcWindow);
}


// CtetrisView message handlers


void CtetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CtetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(nChar==VK_UP)
	{
		pDoc->g.rotatePiece() ;
	}

	else if(nChar==VK_LEFT)
	{
		bool move=1;
		int xl = pDoc->g.getPtr()->getfptr()->blockPts[0].x; 
		
		for(int i=1;i<4;i++)
		{
			if(xl > pDoc->g.getPtr()->getfptr()->blockPts[i].x)
			{
				xl= pDoc->g.getPtr()->getfptr()->blockPts[i].x;
			}
		}

		//Move check
		for(int i=0;i<4;i++)
		{
			Pt block=pDoc->g.getPtr()->getfptr()->blockPts[i];

			if(block.x == xl 
			&& pDoc->g.getCellColor( (pDoc->g.getCurrentCol()+block.x)-1, (pDoc->g.getCurrentRow()+block.y) ) != colorArray[0])
			{
				move=0;
			}
		}

		if(move)
		{
			pDoc->g.updateCcol(-1);
		}
	}

	else if(nChar == VK_RIGHT)
	{
		bool move=1;
		int xl = pDoc->g.getPtr()->getfptr()->blockPts[0].x; 
		
		for(int i=1;i<4;i++)
		{
			if(xl < pDoc->g.getPtr()->getfptr()->blockPts[i].x)
			{
				xl= pDoc->g.getPtr()->getfptr()->blockPts[i].x;
			}
		}

		//Move check
		for(int i=0;i<4;i++)
		{
			Pt block=pDoc->g.getPtr()->getfptr()->blockPts[i];

			if(block.x == xl 
			&& pDoc->g.getCellColor( (pDoc->g.getCurrentCol()+block.x)+1, (pDoc->g.getCurrentRow()+block.y) ) != colorArray[0])
			{
				move=0;
			}
		}

		if(move)
		{
			pDoc->g.updateCcol(1);
		}
	}
	


	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
