#pragma once

#include "MysqlManager.h"
#include "DataType.h"
using namespace DataType;

class CDBManager
{
public:
	CDBManager();
	~CDBManager();

private:
	MysqlManager* m_pDBM;

public:
	// ��ʼ������
	bool init();
	// ��ȡ��һ��ע���û�ID
	bool cusm_get_last_id(CString &strID);
	// ����û�
	bool cusm_add_new_user(const USER_DATA& ud);
};

