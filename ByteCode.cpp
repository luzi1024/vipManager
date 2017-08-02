//��ʵ��
#include "stdafx.h"
#include "ByteCode.h"
//#include <vld.h>
#ifdef NDEBUG
#include "windows.h"
#endif
using namespace std;

/*! 
 * �ú������ڽ�utf8����תΪUnicode��ʽ! 
 * Ŀǰ�ú�������ֵΪ��ת����unicode����ռ�õ�wchar_t�ĸ������мǲ�����char�ĸ����� �� 
 * \param [out] sOut   ת������������ָ�� 
 * \param [in] szU8   Դ���������ָ�� 
 * \return int ת�������Ŀ�Ĵ��еĳ��ȣ�ת��ʧ���򷵻�-1 
 */
int CByteCode::UTF_8ToUnicode(CString& sOut, char* szU8)
{
	//UTF8 to Unicode 


	//Ԥת�����õ�����ռ�Ĵ�С 
	int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);

	//����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ� 
	wchar_t* wszString = new wchar_t[wcsLen + 1];

	//ת�� 
	::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);

	//������'\0' 
	wszString[wcsLen] = '\0';
	sOut = wszString;
	delete[]wszString;

	return wcsLen;
}

void CByteCode::UnicodeToUTF_8(std::string& pOut, CString& pText)
{
	// unicode to UTF8 
	wchar_t* wszString = pText.GetBuffer();
	pText.ReleaseBuffer();
	int u8Len = ::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);

	char* szU8 = new char[u8Len + 1];
	::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), szU8, u8Len, NULL, NULL);
	szU8[u8Len] = '\0';
	pOut = szU8;

	delete[] szU8;
}

// Convert a C string in UTF-8 format to UCS-2 format.
void CByteCode::ToUCS2(TCHAR* pcOut, int nOutLen, const char* kpcIn)
{
	MultiByteToWideChar(CP_UTF8, 0, kpcIn, -1, pcOut, nOutLen);
}

// Convert a UCS-2 string to C string in UTF-8 format.
void CByteCode::ToUTF8(char* pcOut, int nOutLen, const TCHAR* kpcIn)
{
	WideCharToMultiByte(CP_UTF8, 0, kpcIn, -1, pcOut, nOutLen, 0, 0);
}
