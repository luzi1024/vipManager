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

#include "stdafx.h"

#include "PropertiesWnd.h"
#include "Resource.h"
#include "MainFrm.h"
#include "vipManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define ID_BTN_CMB_LIST 1

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar

CPropertiesWnd::CPropertiesWnd()
{
	m_nComboHeight = 0;
}

CPropertiesWnd::~CPropertiesWnd()
{
}

BEGIN_MESSAGE_MAP(CPropertiesWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_EXPAND_ALL, OnExpandAllProperties)
	ON_UPDATE_COMMAND_UI(ID_EXPAND_ALL, OnUpdateExpandAllProperties)
	ON_COMMAND(ID_SORTPROPERTIES, OnSortProperties)
	ON_UPDATE_COMMAND_UI(ID_SORTPROPERTIES, OnUpdateSortProperties)
	ON_COMMAND(ID_PROPERTIES1, OnProperties1)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES1, OnUpdateProperties1)
	ON_COMMAND(ID_PROPERTIES2, OnProperties2)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES2, OnUpdateProperties2)
	ON_WM_SETFOCUS()
	ON_WM_SETTINGCHANGE()
	ON_CBN_SELCHANGE(ID_BTN_CMB_LIST, &CPropertiesWnd::OnBtnSelchangedCmbList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar ��Ϣ�������

void CPropertiesWnd::AdjustLayout()
{
	if (GetSafeHwnd () == NULL || (AfxGetMainWnd() != NULL && AfxGetMainWnd()->IsIconic()))
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	//int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndObjectCombo.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), m_nComboHeight, SWP_NOACTIVATE | SWP_NOZORDER);
	//m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top + m_nComboHeight, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndPropList.SetWindowPos(NULL, rectClient.left, rectClient.top + m_nComboHeight-1/* + cyTlb*/, rectClient.Width(), rectClient.Height() -(m_nComboHeight/*+cyTlb*/), SWP_NOACTIVATE | SWP_NOZORDER);
}

int CPropertiesWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	if (!m_DBM.init())
	{
		AfxMessageBox(_T("��ʼ�����ݿ�ʧ�ܣ�"));
		return -1;
	}

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// �������: 
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_BORDER | CBS_SORT | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	if (!m_wndObjectCombo.Create(dwViewStyle, rectDummy, this, ID_BTN_CMB_LIST))
	{
		TRACE0("δ�ܴ���������� \n");
		return -1;      // δ�ܴ���
	}

	m_wndObjectCombo.AddString(_T("Ӧ�ó���")); // ��ʾ����
	m_wndObjectCombo.AddString(_T("���Դ���"));
	m_wndObjectCombo.SetCurSel(0);
	m_wndObjectCombo.EnableWindow(FALSE);
	CRect rectCombo;
	m_wndObjectCombo.GetClientRect (&rectCombo);

	m_nComboHeight = rectCombo.Height();

	if (!m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2))
	{
		TRACE0("δ�ܴ�����������\n");
		return -1;      // δ�ܴ���
	}
	InitPropList();
	//InitPropListSimple();
/*
	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_PROPERTIES);
	m_wndToolBar.LoadToolBar(IDR_PROPERTIES, 0, 0, TRUE );//������
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_PROPERTIES_HC : IDR_PROPERTIES, 0, 0, TRUE );// ����

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));
	m_wndToolBar.SetOwner(this);

	// �������ͨ���˿ؼ�·�ɣ�������ͨ�������·��: 
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);
*/
	AdjustLayout();
	return 0;
}

void CPropertiesWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CPropertiesWnd::OnExpandAllProperties()
{
	m_wndPropList.ExpandAll();
}

void CPropertiesWnd::OnUpdateExpandAllProperties(CCmdUI* /* pCmdUI */)
{
}

void CPropertiesWnd::OnSortProperties()
{
	m_wndPropList.SetAlphabeticMode(!m_wndPropList.IsAlphabeticMode());
}

void CPropertiesWnd::OnUpdateSortProperties(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropList.IsAlphabeticMode());
}

void CPropertiesWnd::OnProperties1()
{
	// TODO: �ڴ˴���������������
}

void CPropertiesWnd::OnUpdateProperties1(CCmdUI* /*pCmdUI*/)
{
	// TODO: �ڴ˴����������� UI ����������
}

void CPropertiesWnd::OnProperties2()
{
	// TODO: �ڴ˴���������������
}

void CPropertiesWnd::OnUpdateProperties2(CCmdUI* /*pCmdUI*/)
{
	// TODO: �ڴ˴����������� UI ����������
}

void CPropertiesWnd::InitPropList()
{

	SetPropListFont();

	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea();
	m_wndPropList.SetVSDotNetLook();
	m_wndPropList.MarkModifiedProperties();

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("��Ʒ�б�"));

	pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("��ά���"), (_variant_t)false, _T("ָ�����ڵ����岻ʹ�ô��壬���ҿؼ���ʹ����ά�߿�")));

	CMFCPropertyGridProperty* pProp = new CMFCPropertyGridProperty(_T("�߿�"), _T("�Ի������"), _T("����֮һ: ���ޡ�����ϸ�������ɵ�����С���򡰶Ի������"));
	pProp->AddOption(_T("��"));
	pProp->AddOption(_T("ϸ"));
	pProp->AddOption(_T("�ɵ�����С"));
	pProp->AddOption(_T("�Ի������"));
	pProp->AllowEdit(FALSE);

	pGroup1->AddSubItem(pProp);
	CMFCPropertyGridProperty* pTitle = new CMFCPropertyGridProperty(_T("����"), (_variant_t)_T("����"), _T("ָ�����ڱ���������ʾ���ı�"));
	pTitle->AllowEdit(FALSE);
	pGroup1->AddSubItem(pTitle);

	m_wndPropList.AddProperty(pGroup1);
}

void CPropertiesWnd::InitPropListSimple()
{
	SetPropListFont();

	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea();
	m_wndPropList.SetVSDotNetLook();
	m_wndPropList.MarkModifiedProperties();

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("��Ʒ�б�"));

	pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("��ά���"), (_variant_t) false, _T("ָ�����ڵ����岻ʹ�ô��壬���ҿؼ���ʹ����ά�߿�")));

	CMFCPropertyGridProperty* pProp = new CMFCPropertyGridProperty(_T("�߿�"), _T("�Ի������"), _T("����֮һ: ���ޡ�����ϸ�������ɵ�����С���򡰶Ի������"));
	pProp->AddOption(_T("��"));
	pProp->AddOption(_T("ϸ"));
	pProp->AddOption(_T("�ɵ�����С"));
	pProp->AddOption(_T("�Ի������"));
	pProp->AllowEdit(FALSE);

	pGroup1->AddSubItem(pProp);
	CMFCPropertyGridProperty* pTitle = new CMFCPropertyGridProperty(_T("����"), (_variant_t)_T("����"), _T("ָ�����ڱ���������ʾ���ı�"));
	pTitle->AllowEdit(FALSE);
	pGroup1->AddSubItem(pTitle);

	m_wndPropList.AddProperty(pGroup1);

	CMFCPropertyGridProperty* pSize = new CMFCPropertyGridProperty(_T("���ڴ�С"), 0, TRUE);

	pProp = new CMFCPropertyGridProperty(_T("�߶�"), (_variant_t) 250l, _T("ָ�����ڵĸ߶�"));
	pProp->EnableSpinControl(TRUE, 50, 300);
	pSize->AddSubItem(pProp);

	pProp = new CMFCPropertyGridProperty( _T("���"), (_variant_t) 150l, _T("ָ�����ڵĿ��"));
	pProp->EnableSpinControl(TRUE, 50, 200);
	pSize->AddSubItem(pProp);

	m_wndPropList.AddProperty(pSize);

	CMFCPropertyGridProperty* pGroup2 = new CMFCPropertyGridProperty(_T("����"));

	LOGFONT lf;
	CFont* font = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	font->GetLogFont(&lf);

	_tcscpy_s(lf.lfFaceName, _T("����, Arial"));

	pGroup2->AddSubItem(new CMFCPropertyGridFontProperty(_T("����"), lf, CF_EFFECTS | CF_SCREENFONTS, _T("ָ�����ڵ�Ĭ������")));
	pGroup2->AddSubItem(new CMFCPropertyGridProperty(_T("ʹ��ϵͳ����"), (_variant_t) true, _T("ָ������ʹ�á�MS Shell Dlg������")));

	m_wndPropList.AddProperty(pGroup2);

	CMFCPropertyGridProperty* pGroup3 = new CMFCPropertyGridProperty(_T("����"));
	pProp = new CMFCPropertyGridProperty(_T("(����)"), _T("Ӧ�ó���"));
	pProp->Enable(FALSE);
	pGroup3->AddSubItem(pProp);

	CMFCPropertyGridColorProperty* pColorProp = new CMFCPropertyGridColorProperty(_T("������ɫ"), RGB(210, 192, 254), NULL, _T("ָ��Ĭ�ϵĴ�����ɫ"));
	pColorProp->EnableOtherButton(_T("����..."));
	pColorProp->EnableAutomaticButton(_T("Ĭ��"), ::GetSysColor(COLOR_3DFACE));
	pGroup3->AddSubItem(pColorProp);

	static const TCHAR szFilter[] = _T("ͼ���ļ�(*.ico)|*.ico|�����ļ�(*.*)|*.*||");
	pGroup3->AddSubItem(new CMFCPropertyGridFileProperty(_T("ͼ��"), TRUE, _T(""), _T("ico"), 0, szFilter, _T("ָ������ͼ��")));

	pGroup3->AddSubItem(new CMFCPropertyGridFileProperty(_T("�ļ���"), _T("c:\\")));

	m_wndPropList.AddProperty(pGroup3);

	CMFCPropertyGridProperty* pGroup4 = new CMFCPropertyGridProperty(_T("��νṹ"));

	CMFCPropertyGridProperty* pGroup41 = new CMFCPropertyGridProperty(_T("��һ���Ӽ�"));
	pGroup4->AddSubItem(pGroup41);

	CMFCPropertyGridProperty* pGroup411 = new CMFCPropertyGridProperty(_T("�ڶ����Ӽ�"));
	pGroup41->AddSubItem(pGroup411);

	pGroup411->AddSubItem(new CMFCPropertyGridProperty(_T("�� 1"), (_variant_t) _T("ֵ 1"), _T("��Ϊ˵��")));
	pGroup411->AddSubItem(new CMFCPropertyGridProperty(_T("�� 2"), (_variant_t) _T("ֵ 2"), _T("��Ϊ˵��")));
	pGroup411->AddSubItem(new CMFCPropertyGridProperty(_T("�� 3"), (_variant_t) _T("ֵ 3"), _T("��Ϊ˵��")));

	pGroup4->Expand(FALSE);
	m_wndPropList.AddProperty(pGroup4);
}

void CPropertiesWnd::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
	m_wndPropList.SetFocus();
}

void CPropertiesWnd::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CDockablePane::OnSettingChange(uFlags, lpszSection);
	SetPropListFont();
}

void CPropertiesWnd::OnBtnSelchangedCmbList()
{
	int nsel = m_wndObjectCombo.GetCurSel();
	CString str;
	m_wndObjectCombo.GetLBText(nsel, str);
	AfxMessageBox(str);
}



void CPropertiesWnd::SetPropListFont()
{
	::DeleteObject(m_fntPropList.Detach());

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);

	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);

	afxGlobalData.GetNonClientMetrics(info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;

	m_fntPropList.CreateFontIndirect(&lf);

	m_wndPropList.SetFont(&m_fntPropList);
	m_wndObjectCombo.SetFont(&m_fntPropList);
}

void CPropertiesWnd::clearShow()
{
	m_wndPropList.RemoveAll();
	m_wndObjectCombo.ResetContent();
}

BOOL CPropertiesWnd::showProper(CString strFlowID)
{
	if (strFlowID.IsEmpty())
		return false;
	clearShow();
	m_wndObjectCombo.AddString(strFlowID);
	m_wndObjectCombo.SetCurSel(0);

	flow_idx_data idata;
	flow_main_data mdata;
	flow_goods_data gdata;
	idata._paID.second = strFlowID;
	mdata._paFlowID.second = strFlowID;
	gdata._paFlowID.second = strFlowID;

	std::vector<flow_idx_data> vecIdata;
	std::vector<flow_main_data> vecMdata;
	std::vector<flow_goods_data> vecGdata;
	// ������Ϣ
	m_DBM.proper_get_idx(idata, vecIdata);
	if (vecIdata.size()!=1)
	{
		AfxMessageBox(_T("�������ݴ���"));
		return false;
	}
	if (vecIdata[0]._paPayType.second.CompareNoCase(_T("0"))==0)
	{
		// ��ͨ�˻�
	}
	else
	{
		// ��Ա�˻�
		user_data ud;
		std::vector<user_data> vecUD;
		ud._paID.second = vecIdata[0]._paPayType.second;
		m_DBM.cusm_find_user(ud, vecUD);
		if (vecUD.size() != 1)
		{
			AfxMessageBox(_T("�û���Ϣ����,�봦��!"));
			return false;
		}
		CMFCPropertyGridProperty* pGroupCustom = new CMFCPropertyGridProperty(_T("��Ա��Ϣ"));
		{
			CMFCPropertyGridProperty* pName = new CMFCPropertyGridProperty(_T("����"), (_variant_t)vecUD[0]._paName.second, vecUD[0]._paRemark.second);
			pName->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pName);

			CMFCPropertyGridProperty* pID = new CMFCPropertyGridProperty(_T("ID"), (_variant_t)vecUD[0]._paID.second, _T("�û���ΨһID����"));
			pID->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pID);

			CMFCPropertyGridProperty* pPhone = new CMFCPropertyGridProperty(_T("�绰"), (_variant_t)vecUD[0]._paPhone1.second, _T("�û���Ҫ�绰����"));
			pPhone->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pPhone);

			CMFCPropertyGridProperty* pType = new CMFCPropertyGridProperty(_T("��Ա����"), (_variant_t)vecUD[0]._paType.second, _T("ע���Ա����"));
			pType->AddOption(_T("Ԥ����"));
			pType->AddOption(_T("Ԥ������"));
			pType->AddOption(_T("�ۿۻ�Ա"));
			pType->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pType);

			CMFCPropertyGridProperty* pbcount = new CMFCPropertyGridProperty(_T("ʣ�����"), (_variant_t)vecUD[0]._paBalanceCount.second, _T("�������ͻ�Ա��ʣ��ʹ�ô���"));
			pbcount->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pbcount);

			CMFCPropertyGridProperty* pbmoney = new CMFCPropertyGridProperty(_T("���"), (_variant_t)vecUD[0]._paBalanceMoney.second, _T("Ԥ�������ͻ�Ա��ʣ��ʹ�ý��"));
			pbmoney->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pbmoney);

			CMFCPropertyGridProperty* pbScoer = new CMFCPropertyGridProperty(_T("����"), (_variant_t)vecUD[0]._paScore.second, _T("��Ա����"));
			pbScoer->AllowEdit(FALSE);
			pGroupCustom->AddSubItem(pbScoer);

		}
		m_wndPropList.AddProperty(pGroupCustom);
	}
	// ��ͨ����
	m_DBM.proper_get_main(mdata, vecMdata);
	if (vecMdata.size()>1)
	{
		AfxMessageBox(_T("�����ظ����ݣ��봦��"));
		return false;
	}
	else if (vecMdata.size() == 1)
	{
		CMFCPropertyGridProperty* pGroupMain = new CMFCPropertyGridProperty(_T("��ͨ����"));
		{
			CMFCPropertyGridProperty* pPropStatus = new CMFCPropertyGridProperty(_T("״̬"), vecMdata[0]._paStatus.second, _T("��ǰ����״̬����"));
			pPropStatus->AddOption(_T("�����"));
			pPropStatus->AddOption(_T("������"));
			pPropStatus->AddOption(_T("����ʧ��"));
			pPropStatus->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pPropStatus);

			CMFCPropertyGridProperty* pSTime = new CMFCPropertyGridProperty(_T("��ʼʱ��"), (_variant_t)vecMdata[0]._paTime.second, _T("������ʼ��ʱ��"));
			pSTime->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pSTime);

			CMFCPropertyGridProperty* pETime = new CMFCPropertyGridProperty(_T("���ʱ��"), (_variant_t)vecMdata[0]._paEndTime.second, _T("�����뿪��ʱ��"));
			pETime->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pETime);

			CMFCPropertyGridProperty* pValue = new CMFCPropertyGridProperty(_T("����"), (_variant_t)vecMdata[0]._paValue.second, _T("��׼����"));
			pValue->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pValue);

			CMFCPropertyGridProperty* pSale = new CMFCPropertyGridProperty(_T("�ۿ�"), (_variant_t)vecMdata[0]._paSale.second, _T("�ۿ�0-1"));
			pSale->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pSale);

			CMFCPropertyGridProperty* pCount = new CMFCPropertyGridProperty(_T("����"), (_variant_t)vecMdata[0]._paCount.second, _T("��������"));
			pCount->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pCount);

			CMFCPropertyGridProperty* pTotal = new CMFCPropertyGridProperty(_T("�ܼ�"), (_variant_t)vecMdata[0]._paTotal.second, _T("�ۺ���ܼ۸�"));
			pTotal->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pTotal);

			CMFCPropertyGridProperty* pvType = new CMFCPropertyGridProperty(_T("֧������"), (_variant_t)vecMdata[0]._paValueType.second, _T("֧������(�ֽ�ˢ����)"));
			pvType->AllowEdit(FALSE);
			pGroupMain->AddSubItem(pvType);
		}
		m_wndPropList.AddProperty(pGroupMain);
	}

	
	// ��Ʒ�б�
	m_DBM.proper_get_goods(gdata, vecGdata);
	if (vecGdata.size())
	{
		// ��Ʒ��Ϣ
		CMFCPropertyGridProperty* pGroupGoods = new CMFCPropertyGridProperty(_T("��Ʒ�б�"));
		for each (flow_goods_data var in vecGdata)
		{
			goods_data gd;
			std::vector<GOODS_DATA> vecGD;
			gd._paCodeNumber.second = var._paCodeNum.second;
			m_DBM.manger_find_goods(gd, vecGD);
			if (vecGD.size() != 1)
			{
				AfxMessageBox(_T("δ�ҵ���Ʒ��Ϣ��"));
				continue;
			}
			CMFCPropertyGridProperty* pGood = new CMFCPropertyGridProperty(var._paTitle.second, (_variant_t)var._paTotal.second, vecGD[0]._paInfo.second);
			{
				/*
				CMFCPropertyGridProperty* pGoodCodeNum = new CMFCPropertyGridProperty(_T("��Ʒ��"), (_variant_t)var._paCodeNum.second, _T("���м�¼����Ʒ��"));
				CMFCPropertyGridProperty* pGoodType = new CMFCPropertyGridProperty(_T("��Ʒ����"), (_variant_t)vecGD[0]._paType.second, _T("���м�¼����Ʒ����"));
				CMFCPropertyGridProperty* pGoodValue = new CMFCPropertyGridProperty(_T("����"), (_variant_t)var._paValue.second, _T("ָ����ʱ�ĵ���"));
				CMFCPropertyGridProperty* pGoodCount = new CMFCPropertyGridProperty(_T("����"), (_variant_t)var._paCount.second, _T("ָ����ʱ����Ʒ����"));
				CMFCPropertyGridProperty* pGoodAllCount = new CMFCPropertyGridProperty(_T("���"), (_variant_t)vecGD[0]._paTotal.second, _T("ָ����ʱ����Ʒ����"));
				CMFCPropertyGridProperty* pGoodTotal = new CMFCPropertyGridProperty(_T("��Ʒ�ܼ�"), (_variant_t)var._paCount.second, _T("ָ�˼���Ʒ���ܼ�"));
				pGood->AddSubItem(pGoodCodeNum);
				pGood->AddSubItem(pGoodType);
				pGood->AddSubItem(pGoodValue);
				pGood->AddSubItem(pGoodAllCount);
				pGood->AddSubItem(pGoodCount);
				pGood->AddSubItem(pGoodTotal);
				*/
			}
			pGood->AllowEdit(FALSE);
			pGroupGoods->AddSubItem(pGood);
		}

		m_wndPropList.AddProperty(pGroupGoods);
	}
	


	return true;
}

