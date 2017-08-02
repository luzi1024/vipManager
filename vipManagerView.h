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
	BOOL CreatGridView();
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
};

#ifndef _DEBUG  // vipManagerView.cpp �еĵ��԰汾
inline CvipManagerDoc* CvipManagerView::GetDocument() const
   { return reinterpret_cast<CvipManagerDoc*>(m_pDocument); }
#endif

