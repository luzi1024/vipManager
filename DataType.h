#pragma once

namespace DataType
{
	typedef struct USER_DATA
	{
		// �û�����
		// <���ݿ��ֶ������ֶ�ֵ>
		USER_DATA();
		// ID
		std::pair<CString, CString> _paID;
		// ��Ա����
		std::pair<CString, CString> _paName;
		// ע��ʱ��
		std::pair<CString, CString> _paRegtime;
		// ��ϵ�绰
		std::pair<CString, CString> _paPhone1;
		// ���õ绰
		std::pair<CString, CString> _paPhone2;
		// ��Ա����  // ! ���ڻ�Ա���͵�˼�� ���ܼ��д��� �������
		std::pair<CString, CString> _paType;
		// ��Ա����
		std::pair<CString, CString> _paScore;
		// �������
		std::pair<CString, CString> _paBalanceCount;
		// �ֽ����
		std::pair<CString, CString> _paBalanceMoney;
		// ��������
		std::pair<CString, CString> _paBabyName;
		// �����Ա�
		std::pair<CString, CString> _paBabySex;
		// ��������
		std::pair<CString, CString> _paBabyAge;
		// ��ע
		std::pair<CString, CString> _paRemark;

		CString _getdb_key() const;
		CString _getdb_val() const;
	} user_data;

	// ��Ʒ����
	typedef struct GOODS_DATA
	{
		// <���ݿ��ֶ������ֶ�ֵ>
		GOODS_DATA();
		bool operator==(GOODS_DATA& gd);
		// ID
		std::pair<CString, CString> _paID;
		// ��Ʒ��
		std::pair<CString, CString> _paCodeNumber;
		// ��Ʒ����
		std::pair<CString, CString> _paType;
		// ��Ʒ����
		std::pair<CString, CString> _paTitle;
		// ��Ʒ�ۼ�
		std::pair<CString, CString> _paPrice;
		// ��Ʒ����
		std::pair<CString, CString> _paIntoPrice;
		// �������
		std::pair<CString, CString> _paTotal;
		// ��Ʒ��Ϣ
		std::pair<CString, CString> _paInfo;

		CString _getdb_key() const;
		CString _getdb_val() const;
	} goods_data;

	// ��������
	typedef struct FLOWLIST_DATA
	{
		FLOWLIST_DATA();
		// ����
		std::pair<CString, CString> _paID;
		// �����˻�
		std::pair<CString, CString> _paPayUser;
		// ������ʼʱ��
		std::pair<CString, CString> _paPayTime;
		// �ܼ�����
		std::pair<CString, CString> _paTotal;
		// ֧������
		std::pair<CString, CString> _paPayType;
		// �Ƿ�Ʊ
		std::pair<CString, CString> _paReceipt;
		// ��Ʊ����
		std::pair<CString, CString> _paReceiptNum;
		// ��ע
		std::pair<CString, CString> _paRemark;
		// ��Ʒ�嵥 <��Ʒ,����>
		std::vector<std::pair<goods_data, double>> _vecList;

	} flowlist_data;

	// manager_main����
	typedef struct FLOW_IDX_DATA
	{
		FLOW_IDX_DATA();
		// ����
		std::pair<CString, CString> _paID;
		// ״̬
		std::pair<CString, CString> _paStatus;
		// �����˻�
		std::pair<CString, CString> _paPayType;
		// ������ʼ����
		std::pair<CString, CString> _paTime;
		// ����
		std::pair<CString, CString> _paValue;
		// ��Ʊ
		std::pair<CString, CString> _paReceipt;
		// ��Ʊ��
		std::pair<CString, CString> _paReceiptNum;
		// ��ע
		std::pair<CString, CString> _paRemark;

	} flow_idx_data;

	// manager_main����
	typedef struct FLOW_MAIN_DATA 
	{
		FLOW_MAIN_DATA();
		// ����
		std::pair<CString, CString> _paFlowID;
		// ״̬
		std::pair<CString, CString> _paStatus;
		// �����˻�
		std::pair<CString, CString> _paPayType;
		// ������ʼ����
		std::pair<CString, CString> _paTime;
		// ���ѽ�������
		std::pair<CString, CString> _paEndTime;
		// Ӧ�����
		std::pair<CString, CString> _paValue;
		// �ۿ�
		std::pair<CString, CString> _paSale;
		// ����
		std::pair<CString, CString> _paCount;
		// ʵ��
		std::pair<CString, CString> _paTotal;
		// �������(�ֽ�ˢ����)
		std::pair<CString, CString> _paValueType;

	} flow_main_data;

	// manager_goods����
	typedef struct FLOW_GOODS_DATA
	{
		FLOW_GOODS_DATA();
		// ����
		std::pair<CString, CString> _paFlowID;
		// ״̬
		std::pair<CString, CString> _paStatus;
		// �����˻�
		std::pair<CString, CString> _paPayType;
		// ������ʼ����
		std::pair<CString, CString> _paTime;
		// ��Ʒ����
		std::pair<CString, CString> _paTitle;
		// Ӧ�����
		std::pair<CString, CString> _paValue;
		// ��Ʒ��
		std::pair<CString, CString> _paCodeNum;
		// �ۿ�
		std::pair<CString, CString> _paSale;
		// ����
		std::pair<CString, CString> _paCount;
		// ʵ��
		std::pair<CString, CString> _paTotal;
		// �������(�ֽ�ˢ����)
		std::pair<CString, CString> _paValueType;
	} flow_goods_data;

	// �û�ȫ�����ýṹ
	typedef struct CUSTOM_GSET
	{
		CUSTOM_GSET();
		BOOL _bShowBaby;
		BOOL _bShowType;
		BOOL _bShowTime;
		BOOL _bShowScort;
		BOOL _bShowBalance;

		CString _sQfindPhone;
	} custom_gSet;

	// ������ȫ�����ýṹ
	typedef struct FLOW_GSET
	{
		FLOW_GSET();
		BOOL _bComplite;
		BOOL _bRuning;
	} flow_gSet;

	typedef struct GOODS_GSET
	{
		GOODS_GSET();
		BOOL _bShowIntoPre;	// ��ʾ����
	} goods_gSet;
}
