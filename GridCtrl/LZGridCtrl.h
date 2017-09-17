/*============================================================================*
* �ļ���:    ZWMenuGrid.h
* ��  Ȩ:    Copyright (c) ZWST, All Rights Reserved
* ��  ��:    1.0
* ��  ��:    lzk
* ��  ��:    �����д˵���ļ� �޸��Զ���Ӧ���ݿ⣬*��Ҫ���ݱ���ID�����ֶ�
* ��  ʷ:    
=============================================================================*/
#pragma once
#include "GridCtrl.h"
#include <list>
#include <vector>
#include "boost/function.hpp"


class LZGridCtrl :public CGridCtrl
{
	DECLARE_DYNAMIC(LZGridCtrl)
public:
	enum GridType
	{
		gNONE = 0,
		gFlow,		// ������
		gUser,		// ��Ա����
		gGoods,		// ��Ʒ����
		gReport		// ����
	};
public:
	LZGridCtrl(void);
	LZGridCtrl(GridType gtp);
	virtual ~LZGridCtrl(void);
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void show();

	virtual void ClearGrid();
	virtual bool CreateGrid(CWnd* parent,UINT nID);
	virtual void AdjustLayout();
	virtual bool IsChanged(BOOL bDelSame = TRUE);
	virtual bool Init();
	// Edit
	virtual bool AddRow();
	virtual bool InsRow();
	virtual bool EmpRow();
	virtual bool DelRow();
	virtual BOOL AddRows(const int& nRows,const BOOL& bUp);
	virtual bool AddMultiRow();
	virtual bool InsMultiRow(std::vector<int>& vecRows);
	virtual bool Save();
	virtual void DbClickGrid(DWORD wp,DWORD lp);

	// �����ݿ��е�ֵ������ʾ��ֵ��Ҫת��ʱ���ش˺���  ����0->�����1->����
	virtual CString getCellStr(const int& nRow,const int& nCol);
	virtual void getCellType(const int& nRow,const int& nCol,const std::vector<CString>& vecRowData,std::vector<CString>& vecopt);
	virtual void getCellData(std::list<std::pair<int,std::vector<CString> > > & listDataArry);
	virtual void endCellType(const int& nRow, const int& nCol, const CString& strData) { return; }; // ���cell������Ĵ���
	virtual bool submit_add(const CString& strField){return false;};
	virtual bool submit_del(const std::vector<int>& vecDel){return false;};
	virtual bool submit_edt(const int& nID,const CString& strField,const int& nRow){return false;};

	// �Զ������и� �п� ncWidthΪ�������� ��ѡ����Ϊ�п� ��������ʱ�����һ��Ϊ׼ ����������
	virtual bool updateCellSize(int ncWidth,...); 

	// Action
	virtual void OnEditCell(int nRow, int nCol, CPoint point, UINT nChar);
	virtual void OnEndEditCell(int nRow, int nCol, CString str);   //��д��Ԫ��༭��Ϻ��� ���ر����ȵ��ø���
	

	GridType gType(){return m_gType;}
	void SetEndEdit();	// �ֶ����cell�༭״̬ �����޷�����onEndEditCellʱʹ��
	int SetItemTextEx(int nRow, int nCol, LPCTSTR str,int nFlag = 1); // 1��ʼ,2ɾ,3��,4��
private:
	bool submit();
	int InsertRowEx(int nRow = -1);
	bool DeleteRowEx(int nRow);
	int GetlastInsert() {return m_nLastInsert;};
protected:
	// ��������
	bool SetFlagNormal(int nRow);
	bool SetFlagAdd(int nRow);
	bool SetFlagEdit(int nRow);
	void updateCellType(int nRow);
	

	int GetTableRowCount(const CString& strTbname);
	bool GetPrg(CProgressCtrl*& pProGress);
	std::vector<int>& GetVecDel(){return m_vecDel;}
	int GetLineText(int nRow,CString& strRes/*OUT*/);
	// ����������
	static bool StatBarBegin(const CString& strText,int nRange );
	static bool StatBarStep();
	static bool StatBarEnd(const CString& strText = _T(""));

	void SetItemMapID(int nRow,int nMapID);
	void SetItemFlag(int nRow,int nFlag);
	int  GetItemMapID(int nRow);
	int  GetItemFlag(int nRow);
public:
	bool  clearCol(int nCol);                               //�����
	bool  clearRow(int nRow);                               //�����													
	void  readOnlyCell(CGridCellBase* cel, bool bEn = true); // ���õ�Ԫ��Ϊֻ��
protected:
	GridType m_gType;
	CWnd* m_pView;

	static CMFCRibbonStatusBar *m_pStatusBar;
	static CProgressCtrl *m_pProGress;
	static int m_nProStep;
	CToolTipCtrl m_TTC;  // ������ʾ
private:
	int m_nLastInsert;				// ��һ�β��������ID
	int m_nIndexNum;				// Grid��������
	std::vector<int> m_vecDel;		// ɾ������sql����
};

