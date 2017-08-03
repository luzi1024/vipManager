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

#include "LZGridCtrlFlow.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  IDC_GRIDCTRL 1214
// CvipManagerView

IMPLEMENT_DYNCREATE(CvipManagerView, CFormView)

BEGIN_MESSAGE_MAP(CvipManagerView, CFormView)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CvipManagerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BTN_CUSTOMER, &CvipManagerView::OnBtnCustomer)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CvipManagerView ����/����

CvipManagerView::CvipManagerView()
	: CFormView(IDD_DLG_VIPMANAGER_FROM_VIEW)
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
	return CFormView::PreCreateWindow(cs);
}


// CvipManagerView ��ӡ

void CvipManagerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}


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

void CvipManagerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	//ResizeParentToFit();

	//
	if (!CreatGridView(LZGridCtrl::gFlow))
		return ;
	m_pGridView->Init();
	m_pGridView->show();

}
// CvipManagerView ���

#ifdef _DEBUG
void CvipManagerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CvipManagerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CvipManagerDoc* CvipManagerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvipManagerDoc)));
	return (CvipManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CvipManagerView ��Ϣ�������

BOOL CvipManagerView::CreatGridView(LZGridCtrl::GridType gtp)
{
	if (m_pGridView)
	{
		m_pGridView->CloseWindow();
		m_pGridView->ClearGrid();
		m_pGridView = NULL;
	}
	switch (gtp)
	{
	case LZGridCtrl::gFlow: m_pGridView = new LZGridCtrlFlow(); break;
	default:m_pGridView = NULL;
		return FALSE;
		break;
	}
	return m_pGridView->CreateGrid(this, IDC_GRIDCTRL);
}


void CvipManagerView::OnBtnCustomer()
{
	// TODO: �ڴ���������������
	AfxMessageBox(_T("�ǺǺ�"));
}


void CvipManagerView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if (m_pGridView)
	{
		m_pGridView->AdjustLayout();
	}
	// TODO: �ڴ˴������Ϣ����������
}
