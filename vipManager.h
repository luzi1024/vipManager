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

// vipManager.h : vipManager Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "MysqlManager.h"

// CvipManagerApp:
// �йش����ʵ�֣������ vipManager.cpp
//
using namespace IUDB;

class CvipManagerApp : public CWinAppEx
{
public:
	CvipManagerApp();
	~CvipManagerApp()
	{
		if (m_pMysqlManger)
			delete m_pMysqlManger;
	}
private:
	MysqlManager* m_pMysqlManger;
public:
	BOOL initMysqlManager();
	MysqlManager* GetDBCon()
	{
		if (!m_pMysqlManger)
			return NULL;
		return m_pMysqlManger;
	}
	BOOL SetDBCon(MysqlManager*& pCon)
	{
		m_pMysqlManger = pCon;
		return TRUE;
	}
// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CvipManagerApp theApp;
