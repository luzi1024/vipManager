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

// vipManagerView.h : CvipManagerView ��Ľӿ�
//

#pragma once
#include "LZGridCtrl.h"
#include "DataType.h"
using namespace DataType;



extern CUSTOM_GSET g_customSet;
extern FLOW_GSET g_flowSet;

class CvipManagerView : public CFormView
{
protected: // �������л�����
	CvipManagerView();
	DECLARE_DYNCREATE(CvipManagerView)

// ����
public:
	CvipManagerDoc* GetDocument() const;
private:
	// lzk add 
	LZGridCtrl* m_pGridView;
// ����
public:
	BOOL CreatGridView(LZGridCtrl::GridType gtp);
// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
// ʵ��
public:
	virtual ~CvipManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtnCustomer();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBtnManagerFlow();
	afx_msg void OnBtnCustomFind();
	afx_msg void OnBtnCustomAdd();
	afx_msg void OnCheckCusShowBaby();
	afx_msg void OnCheckCusShowType();
	afx_msg void OnCheckCusShowTime();
	afx_msg void OnCheckCusShowScort();
	afx_msg void OnCheckCusShowBalance();
	afx_msg void OnUpdateCheckCusShowBaby(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCheckCusShowType(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCheckCusShowTime(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCheckCusShowScort(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCheckCusShowBalance(CCmdUI *pCmdUI);
	afx_msg void OnEditQfindPhone();
	afx_msg void OnDblclkGrid(NMHDR* pNotifyStruct, LRESULT* pResult);
	afx_msg void OnClkGrid(NMHDR* pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBtnCusmShow();
	afx_msg void OnBtnCusmEdit();
	afx_msg void OnCheckFlowComplite();
	afx_msg void OnCheckFlowRuning();
	afx_msg void OnUpdateCheckFlowComplite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCheckFlowRuning(CCmdUI *pCmdUI);
	afx_msg void OnBtnGoodsAdd();
	afx_msg void OnCheckGoodsShowIntopre();
	afx_msg void OnUpdateCheckGoodsShowIntopre(CCmdUI *pCmdUI);
	afx_msg void OnBtnGoodsEdit();
};

#ifndef _DEBUG  // vipManagerView.cpp �еĵ��԰汾
inline CvipManagerDoc* CvipManagerView::GetDocument() const
   { return reinterpret_cast<CvipManagerDoc*>(m_pDocument); }
#endif

