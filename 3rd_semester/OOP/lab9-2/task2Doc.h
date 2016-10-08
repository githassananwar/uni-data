
// task2Doc.h : interface of the Ctask2Doc class
//


#pragma once
#include "Triangle.h"
#include "Rectangle.h"
#include "Circ.h"

class Ctask2Doc : public CDocument
{
protected: // create from serialization only
	Ctask2Doc();
	DECLARE_DYNCREATE(Ctask2Doc)

// Attributes
public:

	Triangle tri ;
	Rect rec ;
	Circ cir ;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~Ctask2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
