#pragma once

#include "afxwin.h"
#include "resource.h"
#include "DBManager.h"
#include "afxdtctl.h"
// CFlowListDlg �Ի���

class CFlowListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFlowListDlg)

public:
	CFlowListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlowListDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FLOW_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
