#pragma once

#include "afxwin.h"
#include "resource.h"
#include "DBManager.h"
#include "afxdtctl.h"
#include "afxcmn.h"
// CFlowListDlg �Ի���

class CFlowListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFlowListDlg)

public:
	CFlowListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlowListDlg();

	CFont m_cFontID;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FLOW_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
private:
	// �����嵥
	CListCtrl m_lstFlow;
	// �ܼ�
	CRichEditCtrl m_rEditTotal;

	// ����
	CString m_scValue;
	// ����
	CString m_scCount;
	// �ۿ�
	CString m_scSale;
	// �ۺ��
	CString m_scSaleValue;

	// ��ԱID
	CString m_scCusmID;
	// Ԥ���绰
	CString m_scCusmPhone;

	// ��Ʒ����
	CString m_scGoodsCode;
	// ��Ʒ����
	CString m_scGoodsName;
	// ��Ʒ���
	CString m_scGoodsRep;
	// ��Ʒ��Ϣ
	CString m_scGoodsInfo;
	// ��Ʒ����
	CString m_scGoodsPrice;
	// ��Ʒ����
	CString m_scGoodsCount;
private:
	// ���ݿ�ӿ�
	CDBManager m_DBM;

private:
	void updateMainValue();
	void updateGoodsValue();
	void updateTotalValue();
public:
	afx_msg void OnBnClickedCheckFlowlistNormal();
	afx_msg void OnBnClickedBtnFlowlistAdvfind();
	afx_msg void OnBnClickedBtnFlowlistCheck();
	afx_msg void OnBnClickedBtnFlowlistGoodsAdvfind();
	afx_msg void OnBnClickedBtnFlowlistGoodsFind();
	afx_msg void OnBnClickedBtnFlowlistAddgoods();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditFlowlistCount();
	afx_msg void OnEnChangeEditFlowlistSale();
	afx_msg void OnLvnInsertitemListFlowList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListFlowList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListFlowList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnIdrMenuFlowListDel();
};
