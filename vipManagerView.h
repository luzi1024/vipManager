// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问 
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// vipManagerView.h : CvipManagerView 类的接口
//

#pragma once
#include "LZGridCtrl.h"


class CvipManagerView : public CFormView
{
protected: // 仅从序列化创建
	CvipManagerView();
	DECLARE_DYNCREATE(CvipManagerView)

// 特性
public:
	CvipManagerDoc* GetDocument() const;
private:
	// lzk add 
	LZGridCtrl* m_pGridView;
// 操作
public:
	BOOL CreatGridView();
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
// 实现
public:
	virtual ~CvipManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // vipManagerView.cpp 中的调试版本
inline CvipManagerDoc* CvipManagerView::GetDocument() const
   { return reinterpret_cast<CvipManagerDoc*>(m_pDocument); }
#endif

