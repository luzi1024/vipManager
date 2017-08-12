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
	bool manger_get_last_flow(CString &strID);
	// �µ�
	bool manger_order_list(const flowlist_data& fld);

	// ������Ʒ
	bool manger_find_goods(const GOODS_DATA& gd, std::vector<GOODS_DATA>& vecFindGd);

	// ���ݵ��� ��ȡ������Ϣ����ͨ������Ϣ����Ʒ������Ϣ
	bool proper_get_idx(const flow_idx_data& findData, std::vector<flow_idx_data>& vecResData);
	bool proper_get_main(const flow_main_data &findData, std::vector<flow_main_data>& vecResData);
	bool proper_get_goods(const flow_goods_data &findData, std::vector<flow_goods_data>& vecResData);
};

