#pragma once
#include "LZGridCtrl.h"
class LZGridCtrlFlow :
	public LZGridCtrl
{
public:
	LZGridCtrlFlow();
	~LZGridCtrlFlow();

private:
	CString   m_strTblName;	// ��׼�����

public:
	virtual bool Init();			// �������� ��ʼ��
									// ���а������ⵥԪ��ʱ ����
	virtual void getCellType(const int& nRow, const int& nCol, const std::vector<CString>& vecRowData, std::vector<CString>& vecopt);
									// ��ʾ���� ����
	virtual void getCellData(std::list<std::pair<int, std::vector<CString>>>& listDataArry);

};

