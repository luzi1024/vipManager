#pragma once
#include "afxwin.h"
#include "resource.h"
#include "DBManager.h"
#include "afxdtctl.h"

// CGoodsAddDlg �Ի���

class CGoodsAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsAddDlg)

public:
	CGoodsAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CGoodsAddDlg(CString strCodeNum, CWnd* pParent = NULL);// �༭ģʽ
	virtual ~CGoodsAddDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_GOODS_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnGoodsAddDelgoods();
private:
	bool checkInput();
	CString getStrUnixTime();
private:
	// �༭ģʽ
	BOOL m_bEdit;
	// ���ݿ�ӿ�
	CDBManager m_DBM;
	// ����ʼ������
	goods_data m_initgd;
private:
	// ��Ʒ����
	CString m_scCodeNum;
	// ��Ʒ����
	CString m_scType;
	// ��Ʒ����
	CComboBox m_cmbType;
	// ��Ʒ����
	CString m_scTitle;
	// ��Ʒ����
	CString m_scInterPre;
	// ��Ʒ�ۼ�
	CString m_scPrice;
	// �������
	CString m_scTotal;
	// ��ע��Ϣ
	CString m_scInfo;
};
