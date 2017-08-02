#pragma once
#include <string>
#include <vector>
#ifdef _DEBUG
#include <exception>
#endif

#include "tchar.h"
#include "atlstr.h"
#ifdef _DEBUG
class CByteCode
#else
class  CByteCode
#endif
{
public:
	static int UTF_8ToUnicode(CString& sOut, char* szU8); // ��UTF-8ת����Unicode     
	static void UnicodeToUTF_8(std::string& pOut, CString& pText); //Unicode ת����UTF-8    
	static void ToUCS2(TCHAR* pcOut, int nOutLen, const char* kpcIn);
	static void ToUTF8(char* pcOut, int nOutLen, const TCHAR* kpcIn);
};
