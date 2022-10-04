
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	HBRUSH brush = CreatePatternBrush(bitmap);
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW |CS_DBLCLKS, ::LoadCursor(nullptr, IDC_ARROW), brush, NULL);
	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	dc.TextOut(100, 50, CString(" TRANSPARENT 모드 [1] "));
	CWnd::Invalidate(false);

}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CClientDC dc(this);
	dc.SetBkMode(OPAQUE);
	dc.TextOut(100, 50, CString(" OPAQUE 모드"));
	CWnd::Invalidate(false);

}
