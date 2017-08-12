// CustomAddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vipManager.h"
#include "CustomAddDlg.h"
#include "afxdialogex.h"
#include "DataType.h"

// CCustomAddDlg �Ի���

IMPLEMENT_DYNAMIC(CCustomAddDlg, CDialogEx)

CCustomAddDlg::CCustomAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_CUSTOM_ADD, pParent)
	, m_bEdit(FALSE)
	, m_strID(_T("0"))
	, m_strName(_T(""))
	, m_strRegtime(_T(""))
	, m_strPhone1(_T(""))
	, m_strPhone2(_T(""))
	, m_strBabyName(_T(""))
	, m_strBabyAge(_T(""))
	, m_strRemark(_T(""))
	, m_strScore(_T("0"))
	, m_strBalanceCount(_T("0"))
	, m_strBalanceMoney(_T("0.00"))
{

}

CCustomAddDlg::CCustomAddDlg(CString strUserID, CWnd* pParent /*= NULL*/)
	: CDialogEx(IDD_DLG_CUSTOM_ADD, pParent)
	, m_bEdit(TRUE)
	, m_strID(strUserID)
	, m_strName(_T(""))
	, m_strRegtime(_T(""))
	, m_strPhone1(_T(""))
	, m_strPhone2(_T(""))
	, m_strBabyName(_T(""))
	, m_strBabyAge(_T(""))
	, m_strRemark(_T(""))
	, m_strScore(_T("0"))
	, m_strBalanceCount(_T("0"))
	, m_strBalanceMoney(_T("0.00"))
{

}

CCustomAddDlg::~CCustomAddDlg()
{
}

void CCustomAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_CUSTOM_TYPE, m_cmbType);
	DDX_Control(pDX, IDC_CMB_BABYSEX, m_cmbBabySex);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_REGTIME, m_strRegtime);
	DDX_Text(pDX, IDC_EDIT_PHONE1, m_strPhone1);
	DDX_Text(pDX, IDC_EDIT_PHONE2, m_strPhone2);
	DDV_MaxChars(pDX, m_strPhone1, 18);
	DDV_MaxChars(pDX, m_strPhone2, 18);
	DDX_Text(pDX, IDC_EDIT_BABYNAME, m_strBabyName);
	DDX_Text(pDX, IDC_EDIT_BABYAGE, m_strBabyAge);
	DDX_Text(pDX, IDC_EDIT_REMARK, m_strRemark);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_strScore);
	DDX_Text(pDX, IDC_EDIT_BALANCE_COUNT, m_strBalanceCount);
	DDX_Text(pDX, IDC_EDIT_BALANCE_MONEY, m_strBalanceMoney);
	DDV_MaxChars(pDX, m_strScore, 8);
	DDV_MaxChars(pDX, m_strBalanceCount, 4);
	DDV_MaxChars(pDX, m_strBalanceMoney, 7);
	DDX_Control(pDX, IDC_DATETIME_REGTIME, m_dtcRegTime);
}


BEGIN_MESSAGE_MAP(CCustomAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCustomAddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCustomAddDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTN_CUS_DELUSER, &CCustomAddDlg::OnBnClickedBtnCusDeluser)
END_MESSAGE_MAP()


// CCustomAddDlg ��Ϣ�������


BOOL CCustomAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (!m_DBM.init())
	{
		AfxMessageBox(_T("��ʼ�����ݿ�ʧ�ܣ�"));
		CDialogEx::OnCancel();
		return FALSE;
	}
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_cmbBabySex.AddString(_T("��"));
	m_cmbBabySex.AddString(_T("Ů"));
	m_cmbType.AddString(_T("Ԥ������"));
	m_cmbType.AddString(_T("Ԥ����"));
	GetDlgItem(IDC_EDIT_ID)->EnableWindow(FALSE);

	if (!m_bEdit)
	{
		// ���ģʽ��ʼ��
		m_cmbBabySex.SetCurSel(0);
		m_cmbType.SetCurSel(0);
		m_DBM.cusm_get_last_id(m_strID);
		GetDlgItem(IDC_BTN_CUS_DELUSER)->ShowWindow(SW_HIDE);
	}
	else
	{
		// �༭ģʽ��ʼ��
		GetDlgItem(IDC_BTN_CUS_DELUSER)->ShowWindow(SW_SHOW);

		USER_DATA ud;
		ud._paID.second = m_strID;
		std::vector<USER_DATA> udd;
		if (!m_DBM.cusm_find_user(ud, udd) || udd.size() == 0)
		{
			AfxMessageBox(_T("�û����ݴ���"));
			CDialogEx::OnCancel();
			return FALSE;
		}
		m_initud = udd[0];
		m_strName = m_initud._paName.second;
		m_strRegtime = m_initud._paRegtime.second;
		m_strPhone1 = m_initud._paPhone1.second;
		m_strPhone2 = m_initud._paPhone2.second;
		m_cmbType.SelectString(0, m_initud._paType.second);
		m_strScore = m_initud._paScore.second;
		m_strBalanceCount = m_initud._paBalanceCount.second;
		m_strBalanceMoney = m_initud._paBalanceMoney.second;
		m_strBabyName = m_initud._paBabyName.second;
		m_cmbBabySex.SelectString(0, m_initud._paBabySex.second);
		m_strBabyAge = m_initud._paBabyAge.second;
		m_strRemark = m_initud._paRemark.second;
	}


	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CCustomAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strType;
	CString strBabySex;
	m_cmbType.GetWindowTextW(strType);
	m_cmbBabySex.GetWindowTextW(strBabySex);
	// ���ݼ��
	if (!checkInput())
	{
		return;
	}

	if (m_bEdit)
	{
		if (AfxMessageBox(_T("ȷ���޸�?"), MB_YESNO) == IDNO)
			return;
		CDialogEx::OnOK();
		DataType::USER_DATA ud;
		ud._paID.second = m_strID;
		ud._paName.second = m_strName;
		ud._paRegtime.second = m_strRegtime; // ������
		ud._paPhone1.second = m_strPhone1;
		ud._paPhone2.second = m_strPhone2;
		ud._paType.second = strType;
		ud._paScore.second = m_strScore;
		ud._paBalanceCount.second = m_strBalanceCount;
		ud._paBalanceMoney.second = m_strBalanceMoney;
		ud._paBabyName.second = m_strBabyName;
		ud._paBabySex.second = strBabySex;
		ud._paBabyAge.second = m_strBabyAge;
		ud._paRemark.second = m_strRemark;
		m_DBM.cusm_edit_user(ud, m_initud);
	}
	else
	{
		if (AfxMessageBox(_T("ȷ�����?"), MB_YESNO) == IDNO)
			return;

		CDialogEx::OnOK();
		DataType::USER_DATA ud;
		ud._paName.second = m_strName;
		ud._paRegtime.second = m_strRegtime; // ������
		ud._paPhone1.second = m_strPhone1;
		ud._paPhone2.second = m_strPhone2;
		ud._paType.second = strType;
		ud._paScore.second = m_strScore;
		ud._paBalanceCount.second = m_strBalanceCount;
		ud._paBalanceMoney.second = m_strBalanceMoney;
		ud._paBabyName.second = m_strBabyName;
		ud._paBabySex.second = strBabySex;
		ud._paBabyAge.second = m_strBabyAge;
		ud._paRemark.second = m_strRemark;
		m_DBM.cusm_add_new_user(m_strID, ud);
	}


}


void CCustomAddDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (!m_bEdit && !m_strName.IsEmpty() && AfxMessageBox(_T("ȷ��ȡ�����?"), MB_YESNO) == IDNO)
		return;
	CDialogEx::OnCancel();
}


void CCustomAddDlg::OnBnClickedBtnCusDeluser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (AfxMessageBox(_T("ȷ��ɾ��?"), MB_YESNO) == IDNO)
		return;
	USER_DATA ud;
	ud._paID.second = m_strID;
	if (!m_DBM.cusm_delete_user(ud))
	{
		AfxMessageBox(_T("ɾ��ʧ��!"));
	}
	else
	{
		return CDialogEx::OnOK();
	}
}


bool CCustomAddDlg::checkInput()
{
	UpdateData(TRUE);
	m_strName.Trim(_T(" "));
	m_strPhone1.Trim(_T(" "));
	if (m_strName.IsEmpty())
	{
		AfxMessageBox(_T("��������Ϊ��!"));
		return false;
	}

	if (m_strPhone1.IsEmpty() || (m_strPhone1.GetLength() != 7 && m_strPhone1.GetLength() != 11))
	{
		AfxMessageBox(_T("��ϵ�绰��������!"));
		return false;
	}
	if (m_bEdit)
		return true;

	// �Ƿ������ͬ�绰(���)
	USER_DATA ud;
	ud._paPhone1.second = m_strPhone1;
	std::vector<USER_DATA> udd;
	if (!m_DBM.cusm_find_user(ud, udd))
		return false;
	if (udd.size())
	{
		AfxMessageBox(_T("�õ绰�����ѱ�ʹ��!"));
		return false;
	}

	return true;
}

