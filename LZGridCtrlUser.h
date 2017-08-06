#pragma once
#include "LZGridCtrl.h"
#include "DataType.h"
using namespace  DataType;

extern CUSTOM_GSET g_customSet;

class LZGridCtrlUser :
	public LZGridCtrl
{
public:
	LZGridCtrlUser();
	~LZGridCtrlUser();

private:
	CString   m_strTblName;	// ��׼�����

public:
	virtual bool Init();			// �������� ��ʼ��
									// ���а������ⵥԪ��ʱ ����
	virtual void getCellType(const int& nRow, const int& nCol, const std::vector<CString>& vecRowData, std::vector<CString>& vecopt);
									// ��ʾ���� ����
	virtual void getCellData(std::list<std::pair<int, std::vector<CString>>>& listDataArry);

};

