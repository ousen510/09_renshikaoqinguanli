// stdafx.cpp : source file that includes just the standard includes
//	Person.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"


CString g_UserName;
void SetUserName(CString name)
{
	g_UserName = name;
}

CString GetUserName()
{
	return g_UserName;
}