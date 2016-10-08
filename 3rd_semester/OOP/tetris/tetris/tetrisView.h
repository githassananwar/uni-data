
// tetrisView.h : interface of the CtetrisView class
//

#pragma once


class CtetrisView : public CView
{
protected: // create from serialization only
	CtetrisView();
	DECLARE_DYNCREATE(CtetrisView)

// Attributes
public:
	CtetrisDoc* GetDocument() const;
	void DrawPiece(CDC* pDC);

// Operations

public:
	
	void ResizeWindow();

// Overrides
private:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CtetrisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in tetrisView.cpp
inline CtetrisDoc* CtetrisView::GetDocument() const
   { return reinterpret_cast<CtetrisDoc*>(m_pDocument); }
#endif

