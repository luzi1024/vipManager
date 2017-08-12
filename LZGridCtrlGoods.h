#pragma once
#include "LZGridCtrl.h"
#include "DataType.h"
using namespace  DataType;

extern GOODS_GSET g_goodsSet;

class LZGridCtrlGoods :
	public LZGridCtrl
{
public:
	LZGridCtrlGoods();
	~LZGridCtrlGoods();

private:
	CString   m_strTblName;	// ��׼�����

public:
	virtual bool Init();			// �������� ��ʼ��
									// ���а������ⵥԪ��ʱ ����
	virtual void getCellType(const int& nRow, const int& nCol, const std::vector<CString>& vecRowData, std::vector<CString>& vecopt);
									// ��ʾ���� ����
	virtual void getCellData(std::list<std::pair<int, std::vector<CString>>>& listDataArry);

	virtual void endCellType(const int& nRow, const int& nCol, const CString& strData);
};

