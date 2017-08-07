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
	// ���һ���û�
	bool cusm_add_new_user(const CString &strID,const USER_DATA& ud);
	// �޸��û���Ϣ
	bool cusm_edit_user(const USER_DATA& nud, const USER_DATA& oud);
	// ɾ��һ���û� (ͨ��ID)
	bool cusm_delete_user(const USER_DATA& ud);
	// �����û�
	bool cusm_find_user(const USER_DATA& ud,std::vector<USER_DATA>& vecFindUd);



	// ��ȡ��һ������������
	bool cusm_get_last_flow(CString &strID);


	// ������Ʒ
	bool manger_find_goods(const GOODS_DATA& gd, std::vector<GOODS_DATA>& vecFindGd);
};

