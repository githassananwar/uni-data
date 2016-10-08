
// task2View.h : interface of the Ctask2View class
//

#pragma once


class Ctask2View : public CView
{
protected: // create from serialization only
	Ctask2View();
	DECLARE_DYNCREATE(Ctask2View)

// Attributes
public:
	Ctask2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Ctask2View();
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
};

#ifndef _DEBUG  // debug version in task2View.cpp
inline Ctask2Doc* Ctask2View::GetDocument() const
   { return reinterpret_cast<Ctask2Doc*>(m_pDocument); }
#endif

