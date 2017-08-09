// FlowListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vipManager.h"
#include "FlowListDlg.h"
#include "afxdialogex.h"


// CFlowListDlg �Ի���

IMPLEMENT_DYNAMIC(CFlowListDlg, CDialogEx)

CFlowListDlg::CFlowListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FLOW_LIST, pParent)
	, m_strFlowID(_T(""))
	, m_scValue(_T(""))
	, m_scCount(_T(""))
	, m_scSale(_T(""))
	, m_scSaleValue(_T(""))
	, m_scCusmID(_T("0"))
	, m_scCusmPhone(_T(""))
	, m_scGoodsCode(_T(""))
	, m_scGoodsName(_T(""))
	, m_scGoodsRep(_T(""))
	, m_scGoodsInfo(_T(""))
	, m_scGoodsPrice(_T(""))
	, m_scGoodsCount(_T(""))
{

}

CFlowListDlg::~CFlowListDlg()
{
}

void CFlowListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FLOW_LIST, m_lstFlow);
	DDX_Control(pDX, IDC_RICHEDIT_FLOW_TOTAL, m_rEditTotal);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_VALUE, m_scValue);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_COUNT, m_scCount);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_SALE, m_scSale);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_SALEVALUE, m_scSaleValue);
	DDX_Text(pDX, IDC_EDIT_CUSM_ID, m_scCusmID);
	DDX_Text(pDX, IDC_EDIT_CUSM_PHONE, m_scCusmPhone);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_GOODS_CODE, m_scGoodsCode);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_GOODS_NAME, m_scGoodsName);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_GOODS_REPERTORY, m_scGoodsRep);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_GOODS_INFO, m_scGoodsInfo);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_GOODS_PRICE, m_scGoodsPrice);
	DDX_Text(pDX, IDC_EDIT_FLOWLIST_GOODS_COUNT, m_scGoodsCount);
}


BEGIN_MESSAGE_MAP(CFlowListDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK_FLOWLIST_NORMAL, &CFlowListDlg::OnBnClickedCheckFlowlistNormal)
	ON_BN_CLICKED(IDC_BTN_FLOWLIST_ADVFIND, &CFlowListDlg::OnBnClickedBtnFlowlistAdvfind)
	ON_BN_CLICKED(IDC_BTN_FLOWLIST_CHECK, &CFlowListDlg::OnBnClickedBtnFlowlistCheck)
	ON_BN_CLICKED(IDC_BTN_FLOWLIST_GOODS_ADVFIND, &CFlowListDlg::OnBnClickedBtnFlowlistGoodsAdvfind)
	ON_BN_CLICKED(IDC_BTN_FLOWLIST_GOODS_FIND, &CFlowListDlg::OnBnClickedBtnFlowlistGoodsFind)
	ON_BN_CLICKED(IDC_BTN_FLOWLIST_ADDGOODS, &CFlowListDlg::OnBnClickedBtnFlowlistAddgoods)
	ON_BN_CLICKED(IDCANCEL, &CFlowListDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CFlowListDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_FLOWLIST_COUNT, &CFlowListDlg::OnEnChangeEditFlowlistCount)
	ON_EN_CHANGE(IDC_EDIT_FLOWLIST_SALE, &CFlowListDlg::OnEnChangeEditFlowlistSale)
	ON_NOTIFY(LVN_INSERTITEM, IDC_LIST_FLOW_LIST, &CFlowListDlg::OnLvnInsertitemListFlowList)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_FLOW_LIST, &CFlowListDlg::OnLvnItemchangedListFlowList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_FLOW_LIST, &CFlowListDlg::OnNMRClickListFlowList)
	ON_COMMAND(ID_IDR_MENU_FLOW_LIST_DEL, &CFlowListDlg::OnIdrMenuFlowListDel)
END_MESSAGE_MAP()


// CFlowListDlg ��Ϣ�������


HBRUSH CFlowListDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_FLOW_ID)
	{
		pDC->SetTextColor(RGB(255,0,0));
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}



BOOL CFlowListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (!m_DBM.init())
	{
		AfxMessageBox(_T("��ʼ�����ݿ�ʧ�ܣ�"));
		CDialogEx::OnCancel();
		return FALSE;
	}

	m_DBM.manger_get_last_flow(m_strFlowID);
	if (m_strFlowID.IsEmpty())
	{
		AfxMessageBox(_T("��ȡ����ʧ�ܣ�"));
		CDialogEx::OnCancel();
		return FALSE;
	}
	GetDlgItem(IDC_STATIC_FLOW_ID)->SetWindowTextW(m_strFlowID);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_cFontID.CreatePointFont(180, _T("����"));
	GetDlgItem(IDC_STATIC_FLOW_ID)->SetFont(&m_cFontID);
	//
	m_lstFlow.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_lstFlow.InsertColumn(0, _T("���"), LVCFMT_CENTER, 40);	//������
	m_lstFlow.InsertColumn(1, _T("����"), LVCFMT_LEFT,150);
	m_lstFlow.InsertColumn(2, _T("����"), LVCFMT_RIGHT, 80);
	m_lstFlow.InsertColumn(3, _T("����"), LVCFMT_RIGHT, 80);


// 	int nRow = m_lstFlow.InsertItem(0, _T("1"));//������
// 	m_lstFlow.SetItemText(nRow,1, _T("Сƻ��"));//��������
// 	m_lstFlow.SetItemText(nRow,2, _T("x3"));//��������
// 	m_lstFlow.SetItemText(nRow,3, _T("8.5"));//��������
// 	nRow = m_lstFlow.InsertItem(nRow+1, _T("2"));//������
// 	m_lstFlow.SetItemText(nRow, 1, _T("��ͯ���"));//��������
// 	m_lstFlow.SetItemText(nRow, 2, _T("x15"));//��������
// 	m_lstFlow.SetItemText(nRow, 3, _T("1"));//��������


	m_scValue = _T("30");
	m_scCount = _T("1");
	m_scSaleValue = _T("30");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}



void CFlowListDlg::OnBnClickedCheckFlowlistNormal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (((CButton*)GetDlgItem(IDC_CHECK_FLOWLIST_NORMAL))->GetCheck())
	{
		UpdateData(FALSE);
		int n = m_lstFlow.InsertItem(0, _T("1"));				// ������
		m_lstFlow.SetItemText(0, 1, _T("��ͨ����"));	// ����
		m_lstFlow.SetItemText(0, 2, _T("x")+m_scCount);	// ����
		m_lstFlow.SetItemText(0, 3, m_scSaleValue);		// ����

		GOODS_DATA* pgd = new GOODS_DATA;
		pgd->_paCodeNumber.second = _T("2");
		pgd->_paPrice.second = m_scSaleValue;
		pgd->_paTitle.second = _T("��ͨ����");
		m_lstFlow.SetItemData(0,(DWORD_PTR)pgd);
		
	}
	else
	{
		DWORD dptr = m_lstFlow.GetItemData(0);
		GOODS_DATA* pgd = (GOODS_DATA*)dptr;
		delete pgd;
		pgd = NULL;
		m_lstFlow.DeleteItem(0);
	}
	int nC = m_lstFlow.GetItemCount();
	for (int i = 0; i < nC; ++i)
	{
		CString str;
		str.Format(_T("%d"), i + 1);
		m_lstFlow.SetItemText(i, 0, str);//��������
	}
}


void CFlowListDlg::OnBnClickedBtnFlowlistAdvfind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFlowListDlg::OnBnClickedBtnFlowlistCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFlowListDlg::OnBnClickedBtnFlowlistGoodsAdvfind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFlowListDlg::OnBnClickedBtnFlowlistGoodsFind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_scGoodsCode = _T("");
	m_scGoodsRep = _T("");
	m_scGoodsInfo = _T("");
	m_scGoodsPrice = _T("");
	m_scGoodsCount = _T("");
	GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_NAME)->GetWindowTextW(m_scGoodsName);
	GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_CODE)->SetWindowTextW(m_scGoodsCode);
	GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_REPERTORY)->SetWindowTextW(m_scGoodsRep);
	GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_INFO)->SetWindowTextW(m_scGoodsInfo);
	GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_PRICE)->SetWindowTextW(m_scGoodsPrice);
	GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_COUNT)->SetWindowTextW(m_scGoodsCount);

	GOODS_DATA gd;
	gd._paTitle.second = m_scGoodsName;
	std::vector<GOODS_DATA> ggd;
	m_DBM.manger_find_goods(gd, ggd);
	if (ggd.size() == 0)
	{
		AfxMessageBox(_T("δ�ҵ���Ʒ��"));
	}
	else if (ggd.size() == 1)
	{
		GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_CODE)->SetWindowTextW(ggd[0]._paCodeNumber.second);
		GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_NAME)->SetWindowTextW(ggd[0]._paTitle.second);
		GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_REPERTORY)->SetWindowTextW(ggd[0]._paTotal.second);
		GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_INFO)->SetWindowTextW(ggd[0]._paInfo.second);
		GetDlgItem(IDC_EDIT_FLOWLIST_GOODS_PRICE)->SetWindowTextW(ggd[0]._paPrice.second);
		m_scGoodsCode = ggd[0]._paCodeNumber.second;
		m_scGoodsName = ggd[0]._paTitle.second;
		m_scGoodsRep = ggd[0]._paTotal.second;
		m_scGoodsInfo = ggd[0]._paInfo.second;
		m_scGoodsPrice = ggd[0]._paPrice.second;
	}
	else
	{
		AfxMessageBox(_T("�ҵ������Ʒ��"));
	}
}


void CFlowListDlg::OnBnClickedBtnFlowlistAddgoods()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_scGoodsCount.IsEmpty())
	{
		AfxMessageBox(_T("��Ʒ��������Ϊ��!"));
		return;
	}
	GOODS_DATA gd;
	gd._paCodeNumber.second = m_scGoodsCode;
	std::vector<GOODS_DATA> ggd;
	m_DBM.manger_find_goods(gd, ggd);
	if (ggd.size() == 0)
	{
		AfxMessageBox(_T("δ�ҵ���Ʒ��"));
	}
	else if (ggd.size() == 1)
	{
		addGoodsToList(ggd[0],m_scGoodsCount);
	}
}


void CFlowListDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CFlowListDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	flowlist_data fld;
	fld._paID.second = m_strFlowID;
	fld._paPayUser.second = m_scCusmID;
	fld._paPayTime.second = _T("2017/08/10");
	m_rEditTotal.GetWindowTextW(fld._paTotal.second); // ������
	fld._paPayType.second = _T("�ֽ�");
	fld._paReceipt.second = _T("��");
	fld._paReceiptNum.second = _T("");
	fld._paRemark.second = _T("");


	int nListCount = m_lstFlow.GetItemCount();
	for (int i = 0; i < nListCount; ++i)
	{
		CString strCount =  m_lstFlow.GetItemText(i, 2);
		strCount.TrimLeft('x');
		double dc = _ttof(strCount);
		
		GOODS_DATA* pgd = reinterpret_cast<GOODS_DATA*>(m_lstFlow.GetItemData(i));
		ASSERT(pgd);
		fld._vecList.push_back(std::make_pair(*pgd, dc));
		delete pgd;
	}

	if (!m_DBM.manger_order_list(fld))
	{
		AfxMessageBox(_T("�µ�ʧ��!"));
	}

	CDialogEx::OnOK();
}


void CFlowListDlg::OnEnChangeEditFlowlistCount()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT_FLOWLIST_COUNT)->GetWindowTextW(m_scCount);
	updateMainValue();
}


void CFlowListDlg::OnEnChangeEditFlowlistSale()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT_FLOWLIST_SALE)->GetWindowTextW(m_scSale);
	updateMainValue();
}

void CFlowListDlg::updateMainValue()
{
	// ת����Ҫʹ��boost����
	CString strValue, strCount, strSale, strSalevalue;
	double dValue(0), dCount(0), dSale(0), dSalevalue(0);
	GetDlgItem(IDC_EDIT_FLOWLIST_VALUE)->GetWindowTextW(strValue);
	GetDlgItem(IDC_EDIT_FLOWLIST_COUNT)->GetWindowTextW(strCount);
	GetDlgItem(IDC_EDIT_FLOWLIST_SALE)->GetWindowTextW(strSale);
	dValue = _wtof(strValue);
	dCount = _wtof(strCount);
	dSale = _wtof(strSale);
	if (dCount > 9999 || dValue > 99999)
	{
		return;
	}
	if ((dSale > -0.00001 && dSale < 0.00001) || dSale < 0)
	{
		// ������
		strSalevalue.Format(_T("%.2lf"), dValue*dCount);
	}
	else
	{
		// ����
		strSalevalue.Format(_T("%.2lf"), dValue*dSale*dCount);
	}

	GetDlgItem(IDC_EDIT_FLOWLIST_SALEVALUE)->SetWindowTextW(strSalevalue);
	m_scSaleValue = strSalevalue;
}



void CFlowListDlg::addGoodsToList(const GOODS_DATA& agoods, CString strCount)
{
// 	CString strvalue;
// 	double dValue(0), dCount(0), dSale(0), dSalevalue(0);
// 	// �ݲ�������Ʒ�ۿ�
// 	dValue = _wtof(m_scGoodsPrice);
// 	dCount = _wtof(m_scGoodsCount);
// 	strvalue.Format(_T("%.2lf"), dValue*dCount);
	GOODS_DATA* pgd = new GOODS_DATA(agoods);

	int nC = m_lstFlow.GetItemCount();
	int nRow = m_lstFlow.InsertItem(nC+1, _T("0"));
	m_lstFlow.SetItemText(nRow, 1, pgd->_paTitle.second);// ����
	m_lstFlow.SetItemText(nRow, 2, _T("x")+ strCount);		// ���� ��ʱʹ�ñ���
	m_lstFlow.SetItemText(nRow, 3, pgd->_paPrice.second);		// ����
	m_lstFlow.SetItemData(nRow, (DWORD_PTR)pgd);
	nC = m_lstFlow.GetItemCount();
	for (int i = 0; i < nC; ++i)
	{
		CString str;
		str.Format(_T("%d"), i + 1);
		m_lstFlow.SetItemText(i, 0, str);//��������
	}

}

void CFlowListDlg::updateTotalValue()
{
	int nCount = m_lstFlow.GetItemCount();
	double dTotal = 0;
	for (int i = 0; i < nCount; ++i)
	{
		CString strCt = m_lstFlow.GetItemText(i, 2);
		strCt.TrimLeft('x');
		dTotal += (_wtof(strCt)*_wtof(m_lstFlow.GetItemText(i, 3)));
	}
	CString str;
	str.Format(_T("%.2lf"), dTotal);
	m_rEditTotal.SetWindowTextW(str);
}

void CFlowListDlg::OnLvnInsertitemListFlowList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CFlowListDlg::OnLvnItemchangedListFlowList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	updateTotalValue();
	*pResult = 0;
}


void CFlowListDlg::OnNMRClickListFlowList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = m_lstFlow.GetFirstSelectedItemPosition(); //posѡ�е�����λ��
	if (pos == NULL)
		return;
	int nItem = m_lstFlow.GetNextSelectedItem(pos);
	if (nItem == 0 && ((CButton*)GetDlgItem(IDC_CHECK_FLOWLIST_NORMAL))->GetCheck())
		return;
	*pResult = 0;
	CMenu menu;
	POINT pt = { 0 };
	GetCursorPos(&pt);//�õ������λ�� 
	menu.LoadMenu(IDR_MENU_FLOW_LIST);//�˵���ԴID 
	menu.GetSubMenu(0)->TrackPopupMenu(0, pt.x, pt.y, this); //m_newListCtrl��CListCtrl����
}


void CFlowListDlg::OnIdrMenuFlowListDel()
{
	// TODO: �ڴ���������������
	POSITION pos = m_lstFlow.GetFirstSelectedItemPosition(); //posѡ�е�����λ��
	if (pos == NULL)
		return;
	int nItem = m_lstFlow.GetNextSelectedItem(pos);
	DWORD dptr = m_lstFlow.GetItemData(nItem);
	GOODS_DATA* pgd = (GOODS_DATA*)dptr;
	delete pgd;
	pgd = NULL;

	m_lstFlow.DeleteItem(nItem);

	updateTotalValue();
	int nC = m_lstFlow.GetItemCount();
	for (int i = 0; i < nC; ++i)
	{
		CString str;
		str.Format(_T("%d"), i + 1);
		m_lstFlow.SetItemText(i, 0, str);//��������
	}

}
