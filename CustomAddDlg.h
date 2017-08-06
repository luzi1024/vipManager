#pragma once
#include "afxwin.h"
#include "resource.h"
#include "DBManager.h"
#include "afxdtctl.h"

// CCustomAddDlg �Ի���

class CCustomAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomAddDlg)

public:
	CCustomAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CCustomAddDlg(CString strUserID, CWnd* pParent = NULL);// �༭ģʽ
	virtual ~CCustomAddDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CUSTOM_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
private:
	bool checkInput();
private:
	// �༭ģʽ
	BOOL m_bEdit;

	// ���ݿ�ӿ�
	CDBManager m_DBM;
private:
	// ID
	CString m_strID;
	// ��Ա����
	CString m_strName;
	// ע��ʱ��
	CString m_strRegtime;
	// ע��ʱ��
	CDateTimeCtrl m_dtcRegTime;
	// ��ϵ�绰
	CString m_strPhone1;
	// ���õ绰
	CString m_strPhone2;
	// ��Ա����  // ! ���ڻ�Ա���͵�˼�� ���ܼ��д��� �������
	CComboBox m_cmbType;
	// ��Ա����
	CString m_strScore;
	// �������
	CString m_strBalanceCount;
	// �ֽ����
	CString m_strBalanceMoney;
	// ��������
	CString m_strBabyName;
	// �����Ա�
	CComboBox m_cmbBabySex;
	// ��������
	CString m_strBabyAge;
	// ��ע
	CString m_strRemark;


};
