// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ������� 
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// vipManagerView.cpp : CvipManagerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "vipManager.h"
#endif

#include "vipManagerDoc.h"
#include "vipManagerView.h"

#include "MysqlManager.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  IDC_GRIDCTRL 1214
// CvipManagerView

IMPLEMENT_DYNCREATE(CvipManagerView, CView)

BEGIN_MESSAGE_MAP(CvipManagerView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CvipManagerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CvipManagerView ����/����

CvipManagerView::CvipManagerView()
{
	// TODO: �ڴ˴���ӹ������
	m_pGridView = NULL;
}

CvipManagerView::~CvipManagerView()
{
}

BOOL CvipManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	CView::PreCreateWindow(cs);

// 	if (!CreatGridView())
// 		return -1;
// 	m_pGridView->Init();
// 	CStringArray strArryColName;
// 	strArryColName.Add(_T("���"));
// 	strArryColName.Add(_T("����"));
// 	strArryColName.Add(_T("����"));
// 	strArryColName.Add(_T("��ɫ"));
// 	int nCol = strArryColName.GetSize();
// 	m_pGridView->SetColumnCount(nCol);
// 	m_pGridView->SetRowCount(3);
// 	for (int i = 0; i < nCol; i++)
// 	{
// 		CString strColNmae = strArryColName.GetAt(i);
// 		m_pGridView->SetItemText(0, i, strColNmae);
// 	}
// 	m_pGridView->updateCellSize(1, 100);

	return true;
}


// CvipManagerView ����

void CvipManagerView::OnDraw(CDC* /*pDC*/)
{
	CvipManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

// CvipManagerView ��ӡ


void CvipManagerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CvipManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CvipManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CvipManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CvipManagerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CvipManagerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CvipManagerView ���

#ifdef _DEBUG
void CvipManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CvipManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CvipManagerDoc* CvipManagerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvipManagerDoc)));
	return (CvipManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CvipManagerView ��Ϣ�������

BOOL CvipManagerView::CreatGridView()
{
	if (m_pGridView)
	{
		m_pGridView->CloseWindow();
		m_pGridView->ClearGrid();
		m_pGridView = NULL;
	}
	m_pGridView = new LZGridCtrl();
	return m_pGridView->CreateGrid(this, IDC_GRIDCTRL);
}