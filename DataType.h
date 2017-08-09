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
		// �������
		std::pair<CString, CString> _paTotal;
		// ��Ʒ��Ϣ
		std::pair<CString, CString> _paInfo;
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
}
