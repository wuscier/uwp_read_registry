#include "pch.h"
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_VALUE_NAME 16383


string TCHAR2STRING(TCHAR* str)
{
	std::string strstr;
	try
	{
		int iLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);

		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, str, -1, chRtn, iLen, NULL, NULL);

		strstr = chRtn;
	}
	catch (exception e)
	{
	}

	return strstr;
}
LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t) *(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);


	return wcstring;
}
bool IsRegistryKeyValueExisted(HKEY root, string subKey, string valueName) {
	LONG lResult;
	HKEY hKey;

	DWORD KeyCnt, NameCnt;

	bool existed = false;

	lResult = RegOpenKeyEx(root, stringToLPCWSTR(subKey), 0, KEY_READ, &hKey);

	if (lResult == ERROR_SUCCESS)
	{
		if (ERROR_SUCCESS == RegQueryInfoKey(hKey, NULL, NULL, 0, &KeyCnt, NULL, NULL, &NameCnt, NULL, NULL, NULL, NULL))
		{
			TCHAR szValueName[MAX_VALUE_NAME];
			DWORD NameSize = MAX_VALUE_NAME;
			DWORD retCode;

			for (DWORD dwIndex = 0; dwIndex < NameCnt; dwIndex++)
			{
				retCode = RegEnumValue(hKey, dwIndex, szValueName, &NameSize, 0, NULL, NULL, NULL);

				if (retCode == ERROR_SUCCESS)
				{
					string value = TCHAR2STRING(szValueName);
					if (value == valueName)
					{
						existed = true;
						break;
					}
				}
			}
		}
	}

	RegCloseKey(hKey);

	return existed;
}



int main()
{
	bool result = IsRegistryKeyValueExisted(HKEY_LOCAL_MACHINE ,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "SecurityHealth");
}
