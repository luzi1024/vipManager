

#include "StdAfx.h"
#include <mysql_connection.h>   
#include <mysql_driver.h>   
#include <statement.h> 
#include "sqlstring.h"
#include "exception.h"

#pragma once
#define MAX_SQL 1024
#define MAX_SQL2 2048

#	ifdef MYSQL_MODULE
#		define MYSQLExport   __declspec(dllexport)
#	else
#		define MYSQLExport   __declspec(dllimport)
#	endif

namespace IUDB
{
	class CMysqlDbConnect;
}

namespace IUDB
{
	enum EnTableMode
	{
		enTableRead,		//��ȡ��ʽ
		enTableWrite,	//д�뷽ʽ
		enTableModify	//���ķ�ʽ
	};

	class /*MYSQLExport*/ MysqlManager
	{
	public:
		MysqlManager(const CString& strDbName,const CString& strTcpIp, const int& iPort,const CString& strUesrName,const CString& strPassWord,const CString& dbType);
		~MysqlManager(void);

	public:
		static CString DBLZManager;		// �ۺϹ����
		static CString DBLZCustomer;	// �û������
		
		const CString& getType(void)const { return m_dbType; }
		const CString& getTcpIp(void)const { return m_strTcpIp; }
		const int& getPort(void)const { return m_iPort; }
		const CString& getUesrName(void)const { return m_strUesrName; }
		const CString& getPassWord(void)const { return m_strPassWord; }
		const CString& getDbName(void)const { return m_stdDbName; }

	public:
		/*!
		 * �������ݿ� ������ǰ�û���������Ȩ��
		 * \param [in] dbName ����
		 */
		bool CreateDb(const CString& dbName);

		/*!
		 * �������ݿ����ԱȨ��
		 */
		bool GrantAllPrivileges(const CString& pszUser);

		/*!
		 * �õ���ǰ���ڲ��������ݿ�
		 */
		CString GetCurrentDataBase();

		/*! 
		 * ѡ�����ݿ�, �л���ǰΪָ�������ݿ�
		 */
		bool SelectDataBase(const CString& pszDbName);

		/*!
		 * �ж��Ƿ�������ݿ�
		 * \param [in] dbName ����
		 */
		bool isExitsDataBase(const CString& dbName);

		/*!
		 * �ж��Ƿ����ָ����
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblname ����
		 */
		bool IsExitTable(const CString& tblName);

		/*!
		 * �ж�ָ�������Ƿ����ָ����
		 * \param [in] dbName ����
		 * \param [in] tblName ����
		 */
		bool IsExitTable(const CString& dbName, const CString& tblName);

		/*!
		 * �ж�ָ����ָ�������Ƿ����ָ���ֶ�
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblName ����
		 * \param [in] fieldName �ֶ���
	 	 */
		bool isExitsField(const CString& tblName, const CString& fieldName);

		/*!
		 * �ж�ָ����ָ�������Ƿ����ָ���ֶ�
		 * \param [in] dbName ����
		 * \param [in] tblName ����
		 * \param [in] fieldName �ֶ���
	 	 */
		bool isExitsField(const CString& dbName, const CString& tblName, const CString& fieldName);

		/*!
		 * ��ȡָ���������(��¼��)
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tableName ����
		 */
		int GetRowCounts(const CString& tableName);
		
		/*!
		 * ��ȡָ����ָ���������(��¼��)
		 * \param [in] dbName ����
		 * \param [in] tableName ����
		 */
		int GetRowCounts(const CString& dbName,const CString& tableName);
		
		/*!
		 * ��ȡָ���������(�ֶ���)
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tableName ����
		 */
		int GetColCounts(const CString& tableName);
		
		/*!
		 * ��ȡָ����ָ���������(�ֶ���)
		 * \param [in] dbName ����
		 * \param [in] tableName ����
		 */
		int GetColCounts(const CString& dbName, const CString& tableName);

		//�����ͷŲ�֪ԭ����� ����
		bool GetColsInfo(const CString& dbName, const CString& tblName, CStringArray& fieldNames,CStringArray& filedTypes);

		/*!
		 * ����ָ������ID������ֵ
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \note ���������ID��ʧ��
		 * \param [in] tableName ����
		 */
		int GetLastId(const CString& tableName);

		/*!
		 * ����ָ����ָ������ID������ֵ
		 * \note ���������ID��ʧ��
		 * \param [in] dbName ����
		 * \param [in] tableName ����
		 */
		int GetLastId(const CString& dbName, const CString& tableName);
		

		/////////   ��ѯ�������    //////////////////
		/*!
		 * ����ǰ���������������ʼ��֮ǰ(����������ֻ��λ��)
		 */
		void BeforeFirst();
		/*!
		 * ����ѯ�����ָ������Ϊ��ǰ��
		 */
		bool MoveRow(int rowIndex);
		/*!
		 * �ƶ�����һ��
		 */
		bool Next();
		/////////   ��ѯ�������    //////////////////


		/////////////  ������  ///////////////////////////////
		/*!
		 * �Ӳ�ѯ�����ǰ�л�ȡ������ֵ
		 * \param [in] columnIndex ����������1��ʼ
		 */
		bool GetBoolean(int columnIndex) const;
		bool GetBoolean(const CString& columnLabel) const;

		/*!
		 * �Ӳ�ѯ�����ǰ�л�ȡ������ֵ
		 * \param [in] columnIndex ����������1��ʼ
		 */
		long double GetDouble(int columnIndex) const ;
		long double GetDouble(const CString& columnLabel) const;

		/*!
		 * �Ӳ�ѯ�����ǰ�л�ȡ����ֵ
		 * \param [in] columnIndex ����������1��ʼ
		 */
		int GetInt32(int columnIndex) const;
		int GetInt32(const CString& columnLabel) const;

		/*!
		 * �Ӳ�ѯ�����ǰ�л�ȡ�ַ���
		 * \param [in] columnIndex ����������1��ʼ
		 */
		CString GetString(int columnIndex)  const ;
		CString GetString(const CString& columnLabel) const ;

		/*!
		 * �Ӳ�ѯ�����ǰ�л�ȡ������
		 * \param [in] columnIndex ����������1��ʼ
		 */
		std::istream* GetBlob(int columnIndex) const;
		std::istream* GetBlob(const CString& columnLabel)const;
		/////////////  end ��������  ///////////////////////////

		///////////////  ����д��  ////////////////////////////////
		void SetInt(unsigned int parameterIndex, int val, bool bNull=false);
		void SetString(unsigned int parameterIndex, const CString& val, bool bNull=false);
		void SetDouble(unsigned int parameterIndex, double val, bool bNull=false);
		void SetBoolean(unsigned int parameterIndex, bool val, bool bNull=false);
		void SetBlob(unsigned int parameterIndex, std::istream * blob, bool bNull=false);
		////////////// end ����д��  ////////////////////////////////

		///////////////      ����¼����    /////////////////////////
		/*!
		 * ���һ��
		 * \param [in] ����
		 * \param [in] ����
		 * \param [in] ��ǰ�м�¼ֵ
		 */
		bool addOneRow(const CString& tblName,const CStringArray&colNames, const CStringArray&rowVals);
		
		/*!
		 * ������
		 * \param [in] ����
		 * \param [in] ������
		 * \param [in] ����
		 * \param [in] ��ǰ��¼ֵ
		 */
		bool updateOneRow(const  CString& tblName, const int& rowIndex,
			const CStringArray&colNames, const CStringArray&rowVals);
		
		/*!
		 * ɾ����
		 * \param [in] ����
		 * \param [in] ������
		 */
		bool deleteOneRow(const CString& pTblName,const int rowIndex);
		///////////////   end   ����¼����    /////////////////////////

		////////////////     �в���  //////////////////////////////////////
		/*!
		 * ��ָ����������
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblName ����
		 * \param [in] columnName ����
		 * \param [in] columType ������
		 */
		bool AddColumn(const CString& tblName, const CString& columnName, 
			const CString& columType);
		/*!
		 * ��ָ����������
		 * \param [in] dbName ����
		 * \param [in] tblName ����
		 * \param [in] columnName ����
		 * \param [in] columType ������
		 */
		bool AddColumn(const CString& dbName, const CString& tblName, const CString& columnName, 
			const CString& columType);
		
		/*!
		 * �޸�ָ����ָ���е�����
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblName ����
		 * \param [in] oldColumnName ������
		 * \param [in] newColmName ������
		 * \param [in] columnType ������
		 */
		bool ModifyColumName(const CString& tblName,const CString& oldColumnName,
			const CString& newColmName,const CString& columType);
		/*!
		 * �޸�ָ����ָ����ָ���е�����
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] dbName ����
		 * \param [in] tblName ����
		 * \param [in] oldColumnName ������
		 * \param [in] newColmName ������
		 * \param [in] columnType ������
		 */
		bool ModifyColumName(const CString& dbName, const CString& tblName,const CString& oldColumnName,
			const CString& newColmName,const CString& columType);
		
		/*!
		 * �޸�ָ����ָ���е�����
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \note [in] tblName ����
		 * \note [in] columnName ����
		 * \note [in] newColmType ������
		 */
		bool ModifyColumType(const CString& tblName,const CString& columnName,
			const CString& newColmType);
		/*!
		 * �޸�ָ����ָ����ָ���е�����
		 * \note [in] dbName ����
		 * \note [in] tblName ����
		 * \note [in] columnName ����
		 * \note [in] newColmType ������
		 */
		bool ModifyColumType(const CString& dbName, const CString& tblName,const CString& columnName,
			const CString& newColmType);
		////////////////   end  �в���  //////////////////////////////////////
		
		//////////////////      �����  /////////////////////////////////
		bool CreateCustomTable(const CString& strSql);

#ifndef NDEBUG
		//�ýӿڿ��ܴ������⣬��ʱ�Ȳ�Ҫʹ��
		bool CreateTable(const CString& dbName, const CString& tblName);	

		//�ýӿڿ��ܴ������⣬��ʱ�Ȳ�Ҫʹ��
		//primarkKey:����
		bool CreateTable(const  CString& tblName, const CStringArray& colNames,
			const CStringArray& colTypes,const  CString& primarkKey);
#endif
		
		/*!
		 * ɾ��ָ����
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblName ����
		 */
		bool DropTable(const CString& tblName);

		/*!
		 * ɾ��ָ����ָ����
		 * \param [in] dbname ����
		 * \param [in] tblName ����
		 */
		bool DropTable(const CString& dbName, const CString& tblName);

		/*!
		 * Ϊָ����ָ���д�������
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblName ����
		 * \param [in] colName ����
		 * \param [in] idexName ��������
		 */
		bool CreateIndex(const CString& tblName, const CString& colName,const CString& idxName);	

		/*!
		 * Ϊָ����ָ����ָ���д�������
		 * \param [in] dbName ����
		 * \param [in] tblName ����
		 * \param [in] colName ����
		 * \param [in] idexName ��������
		 */
		bool CreateIndex(const CString& dbName, const CString& tblName, const CString& colName,const CString& idxName);	

		/*!
		 * ��ձ�������
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] tblname ����
		 */
		bool ClearTable(const CString& tblName);

		/*!
		 * ���ָ������ָ�����ڵ�����
		 * \param [in] dbName ����
		 * \param [in] tblName ����
		 */
		bool ClearTable(const CString& dbName, const CString& tblName);

		/*!
		 * ������
		 * \note ���ݿ�Ϊ��ʱ��ʹ��֮ǰ����SelectDataBase()ѡ��Ŀ�
		 * \param [in] destTblName Ŀ�����
		 * \param [in] orgTblNaME Դ����
		 * \param [in] isContainData �Ƿ�ͬʱ������������
		 * \param [in] destDBName Ŀ���
		 * \param [in] orgDBName Դ��
		 */
		bool CopyTable(const CString& destTblName,
			const CString& orgTblName,
			bool isContainData=false,
			const CString& destDBName = _T(""),
			const CString& orgDBName = _T(""));

		/*!
		 * �����޶�����������(ֻ����������)
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 */
		bool CopyTableData(const CString& pDestTblName,const CString& pSelectSql);

		/*!
		 * copy������ݵ�Ŀ����ָ������(���޶�������δ�����쳣����)
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 */
		bool CopyTableDataByDefCols(const CString& pDestTblName,const CStringArray& colNames,
			const CString& pSelectSql);

		/*!
		 * ��ָ����
		 * \note ʹ��ǰ���뱣֤�ѵ��ù�SelectDataBase()
		 * \param [in] ����
		 * \param [in] ��ģʽ
		 */
		int OpenTable(const CString& tableName, EnTableMode enM);

		/*!
		 * ��ָ����ָ����
		 * \param [in] ����
		 * \param [in] ����
		 * \param [in] ��ģʽ
		 */
		int OpenTable(const CString& dbName, const CString& pTblName, EnTableMode enM);

		/*!
		 * �޸ı��¼ʱʹ��, ���ַ�ʽ����һ���򿪱�ĺ���Ч�ʸ�,����Ҫ������������
		 * \param [in] ����
		 * \param [in] ����
		 * \param [in] ����
		 * \param [in] ��ģʽ
		 * \return TRUE;FALSE
		 */
		int OpenTable(const CString& dbName, const CString& tableName,const CStringArray& colName,EnTableMode enM);

		//	@bref: ��ѯ�������ã����������ڴ�й¶
		bool CloseTable();
		//////////////////  end  �����    /////////////////////////////////

		////////////////  sql�ű�����  //////////////////////////
		/*!
		 *ִ��sql��¼��, ִ�������Ҫ�ر� eg:  ����ͨ��sql���
		 *			ֱ�Ӳ�ѯ��ǰ��ѯ�����м�¼, Ҳ����ָ��������¼
		 * \param [in] sqlScript sql�ű�
		 */
		int ExecutSqlAndReturn(const CString& sqlScript);

		/*!
		 * �ر�sql��¼��
		 */
		bool CloseSqlRecords();

		/*!
		 * ִ��ָ��sql�ű�
		 * \param [in] sqlScript �ű�
		 */
		bool ExecutSql(const CString& sqlScript);
		//////////////// end  sql�ű�����  //////////////////////////


		/////////////////////////////////////////////////////////////////////
		bool connectSvc();
		bool disconnectSvc();
		bool reconnectSvc();

		static bool SQLlogger(const CString strContent, const CString strFile = _T("./zwdb.err")); // ������־
	protected:
		sql::SQLString makeCnName() const;
		sql::SQLString getSqlString(const CString& strString) const;
		CString getErrorInfo(const sql::SQLException& er) const;

		bool InitWriteCache();		// ��ʼ������
		bool InitReadCache();	//��ʼ��������
		bool CloseReadCache();	//�رն�����

		bool CloseWriteCache();		// �رջ���
		bool openDb();

		
	protected:
		CString m_strTcpIp;  //IP��ַ
		int m_iPort;	//���ݿ�˿�
		CString m_strUesrName;	//�û���
		CString m_strPassWord;	//����
		CString m_dbType;
		CString m_stdDbName;	//���ӻ��л����ݿ��Ϊ��ǰʹ�õ����ݿ�����
		int m_nExcueCols;
		CStringArray m_fieldNames;
		CStringArray m_filedTypes;
	private:
		sql::Driver *m_pDriver;
		sql::Connection* m_pCon;
		sql::Statement* m_pState;	//OpoenTable��ExecutSqlAndReturn��ر�Ǯ����Ϊ��
		sql::ResultSet* m_pRes;		
		sql::PreparedStatement * m_pPreMst;
		EnTableMode m_enMode;				//��ǰģʽ
		sql::SQLString m_sqlScript;		//sql ��ʱ�ű�
		
	};
}

