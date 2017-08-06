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
#include "LZGridCtrlUser.h"

#include "CustomAddDlg.h"
#include "FlowListDlg.h"
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
	ON_COMMAND(ID_BTN_MANAGER_FLOW, &CvipManagerView::OnBtnManagerFlow)
	ON_COMMAND(ID_BTN_CUSTOM_FIND, &CvipManagerView::OnBtnCustomFind)
	ON_COMMAND(ID_BTN_CUSTOM_ADD, &CvipManagerView::OnBtnCustomAdd)

	ON_COMMAND(ID_CHECK_CUS_SHOW_BABY, &CvipManagerView::OnCheckCusShowBaby)
	ON_COMMAND(ID_CHECK_CUS_SHOW_TYPE, &CvipManagerView::OnCheckCusShowType)
	ON_COMMAND(ID_CHECK_CUS_SHOW_TIME, &CvipManagerView::OnCheckCusShowTime)
	ON_COMMAND(ID_CHECK_CUS_SHOW_SCORT, &CvipManagerView::OnCheckCusShowScort)
	ON_COMMAND(ID_CHECK_CUS_SHOW_BALANCE, &CvipManagerView::OnCheckCusShowBalance)
	ON_UPDATE_COMMAND_UI(ID_CHECK_CUS_SHOW_BABY, &CvipManagerView::OnUpdateCheckCusShowBaby)
	ON_UPDATE_COMMAND_UI(ID_CHECK_CUS_SHOW_TYPE, &CvipManagerView::OnUpdateCheckCusShowType)
	ON_UPDATE_COMMAND_UI(ID_CHECK_CUS_SHOW_TIME, &CvipManagerView::OnUpdateCheckCusShowTime)
	ON_UPDATE_COMMAND_UI(ID_CHECK_CUS_SHOW_SCORT, &CvipManagerView::OnUpdateCheckCusShowScort)
	ON_UPDATE_COMMAND_UI(ID_CHECK_CUS_SHOW_BALANCE, &CvipManagerView::OnUpdateCheckCusShowBalance)
	ON_COMMAND(ID_EDIT_QFIND_PHONE, &CvipManagerView::OnEditQfindPhone)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL, &CvipManagerView::OnDblclkGrid)
	ON_COMMAND(ID_BTN_CUSM_SHOW, &CvipManagerView::OnBtnCusmShow)
	ON_COMMAND(ID_BTN_CUSM_EDIT, &CvipManagerView::OnBtnCusmEdit)
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


void CvipManagerView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if (m_pGridView)
	{
		m_pGridView->AdjustLayout();
	}
	// TODO: �ڴ˴������Ϣ����������
}

void CvipManagerView::OnBtnCustomer()
{
	// TODO: �˿͹��� ��ť
	AfxMessageBox(_T("�ǺǺ�"));
}




void CvipManagerView::OnBtnManagerFlow()
{
	// TODO: ������ ��ť
	AfxInitRichEdit();
	CFlowListDlg fdlg;
	if (fdlg.DoModal() == IDOK)
	{
		;
	}

}



void CvipManagerView::OnBtnCustomFind()
{
	// TODO: ��Ա���� ���� ��ť
	AfxMessageBox(_T("��Ա���� ���� ��ť"));
}


void CvipManagerView::OnBtnCustomAdd()
{
	// TODO: ��Ա���� ��� ��ť
	CCustomAddDlg adDlg;
	if (adDlg.DoModal() == IDOK)
	{
		AfxMessageBox(_T("��ӳɹ�!"));
		CreatGridView(m_pGridView->gType());
	}
}



// 
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
	case LZGridCtrl::gUser: m_pGridView = new LZGridCtrlUser(); break;
	default:m_pGridView = NULL;
		return false;
		break;
	}
	if (m_pGridView->CreateGrid(this, IDC_GRIDCTRL))
	{
		m_pGridView->Init();
		m_pGridView->show();
		return true;
	}

	return false;
}




void CvipManagerView::OnCheckCusShowBaby()
{
	// TODO: �ڴ���������������
	g_customSet._bShowBaby = !g_customSet._bShowBaby;
 	CreatGridView(m_pGridView->gType());	
}


void CvipManagerView::OnCheckCusShowType()
{
	// TODO: �ڴ���������������
	g_customSet._bShowType = !g_customSet._bShowType;
	CreatGridView(m_pGridView->gType());
}


void CvipManagerView::OnCheckCusShowTime()
{
	// TODO: �ڴ���������������
	g_customSet._bShowTime = !g_customSet._bShowTime;
	CreatGridView(m_pGridView->gType());
}


void CvipManagerView::OnCheckCusShowScort()
{
	// TODO: �ڴ���������������
	g_customSet._bShowScort = !g_customSet._bShowScort;
	CreatGridView(m_pGridView->gType());
}


void CvipManagerView::OnCheckCusShowBalance()
{
	// TODO: �ڴ���������������
	g_customSet._bShowBalance = !g_customSet._bShowBalance;
	CreatGridView(m_pGridView->gType());
}


void CvipManagerView::OnUpdateCheckCusShowBaby(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(g_customSet._bShowBaby);
}


void CvipManagerView::OnUpdateCheckCusShowType(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(g_customSet._bShowType);
}


void CvipManagerView::OnUpdateCheckCusShowTime(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(g_customSet._bShowTime);
}


void CvipManagerView::OnUpdateCheckCusShowScort(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(g_customSet._bShowScort);
}


void CvipManagerView::OnUpdateCheckCusShowBalance(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(g_customSet._bShowBalance);
}


void CvipManagerView::OnEditQfindPhone()
{
	// TODO: �ڴ���������������
	CMainFrame* pMainF = dynamic_cast<CMainFrame*>(theApp.GetMainWnd());
	if (pMainF)
	{
		CMFCRibbonBar* pRibbonBar = pMainF->getWndRibbonBar();
		if (pRibbonBar)
		{
			CMFCRibbonEdit* pEdit = dynamic_cast<CMFCRibbonEdit *>(pRibbonBar->FindByID(ID_EDIT_QFIND_PHONE));
			if (pEdit)
			{
				CString strText = pEdit->GetEditText();
				g_customSet._sQfindPhone = strText;
				CreatGridView(m_pGridView->gType());
			}

		}
	}
}

void CvipManagerView::OnDblclkGrid(NMHDR* pNotifyStruct, LRESULT* pResult)
{
	OnBtnCusmEdit();
}


void CvipManagerView::OnBtnCusmShow()
{
	// TODO: �ڴ���������������
	CMainFrame* pMainF = dynamic_cast<CMainFrame*>(theApp.GetMainWnd());
	if (pMainF)
	{
		CMFCRibbonBar* pRibbonBar = pMainF->getWndRibbonBar();
		if (pRibbonBar)
		{
			CMFCRibbonEdit* pEdit = dynamic_cast<CMFCRibbonEdit *>(pRibbonBar->FindByID(ID_EDIT_QFIND_PHONE));
			if (pEdit)
			{
				pEdit->SetEditText(_T(""));
				g_customSet._sQfindPhone = _T("");
			}

		}
	}
	CreatGridView(m_pGridView->gType());
}


void CvipManagerView::OnBtnCusmEdit()
{
	// TODO: �ڴ���������������
	CCellID cid = m_pGridView->GetFocusCell();
	CMainFrame* pMainF = dynamic_cast<CMainFrame*>(theApp.GetMainWnd());
	if (!pMainF)
		return;

	if (2 == pMainF->getCategoryIndex() && cid.IsValid() && cid.row > 0)
	{
		CString strId = m_pGridView->GetItemText(cid.row, 1);

		if (!strId.IsEmpty())
		{
			CCustomAddDlg adDlg(strId);
			if (adDlg.DoModal() == IDOK)
			{
				AfxMessageBox(_T("�����ɹ�!"));
				CreatGridView(m_pGridView->gType());
			}
		}
	}
}
