#include "stdafx.h"
#include "DataType.h"

namespace DataType
{
	USER_DATA::USER_DATA()
	{
		_paID			= std::make_pair(_T("ID"), _T(""));
		_paName			= std::make_pair(_T("NAME"), _T(""));
		_paRegtime		= std::make_pair(_T("REGTIME"), _T(""));
		_paPhone1		= std::make_pair(_T("PHONE1"), _T(""));
		_paPhone2		= std::make_pair(_T("PHONE2"), _T(""));
		_paType			= std::make_pair(_T("CARDTYPE"), _T(""));
		_paScore		= std::make_pair(_T("SCORE"), _T("0,"));
		_paBalanceCount	= std::make_pair(_T("BALANCE_COUNT"), _T("0"));
		_paBalanceMoney	= std::make_pair(_T("BALANCE_MONEY"), _T("0.00"));
		_paBabyName		= std::make_pair(_T("BABYNAME"), _T(""));
		_paBabySex		= std::make_pair(_T("BABYSEX"), _T(""));
		_paBabyAge		= std::make_pair(_T("BABYAGE"), _T(""));
		_paRemark		= std::make_pair(_T("REMARK"), _T(""));
	}

	CString USER_DATA::_getdb_key() const
	{
		CString str;
		str += (_T("`") + _paID.first + _T("`,"));
		str += (_T("`") + _paName.first + _T("`,"));
		str += (_T("`") + _paRegtime.first + _T("`,"));
		str += (_T("`") + _paPhone1.first + _T("`,"));
		str += (_T("`") + _paPhone2.first + _T("`,"));
		str += (_T("`") + _paType.first + _T("`,"));
		str += (_T("`") + _paScore.first + _T("`,"));
		str += (_T("`") + _paBalanceCount.first + _T("`,"));
		str += (_T("`") + _paBalanceMoney.first + _T("`,"));
		str += (_T("`") + _paBabyName.first + _T("`,"));
		str += (_T("`") + _paBabySex.first + _T("`,"));
		str += (_T("`") + _paBabyAge.first + _T("`,"));
		str += (_T("`") + _paRemark.first + _T("`"));
		return str;
	}

	CString USER_DATA::_getdb_val() const
	{
		CString str;
		str += (_T("'") + _paID.second + _T("',"));
		str += (_T("'") + _paName.second + _T("',"));
		str += (_T("'") + _paRegtime.second + _T("',"));
		str += (_T("'") + _paPhone1.second + _T("',"));
		str += (_T("'") + _paPhone2.second + _T("',"));
		str += (_T("'") + _paType.second + _T("',"));
		str += (_T("'") + _paScore.second + _T("',"));
		str += (_T("'") + _paBalanceCount.second + _T("',"));
		str += (_T("'") + _paBalanceMoney.second + _T("',"));
		str += (_T("'") + _paBabyName.second + _T("',"));
		str += (_T("'") + _paBabySex.second + _T("',"));
		str += (_T("'") + _paBabyAge.second + _T("',"));
		str += (_T("'") + _paRemark.second + _T("'"));
		return str;
	}

}