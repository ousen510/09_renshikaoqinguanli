// ADO.h: interface for the CADO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADO_H__EE0962C4_DC53_489D_981F_B112A39F9C1B__INCLUDED_)
#define AFX_ADO_H__EE0962C4_DC53_489D_981F_B112A39F9C1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#import "C:\Program Files\Common Files\System\ado\msado15.dll"  no_namespace rename("EOF","adoEOF")

 
class CADOConnection
{
private:
	static void InitADO();
	static void UnInitADO();
protected:
	_ConnectionPtr m_Connection;
public:
	BOOL IsOpen();
	_ConnectionPtr GetConnection();
	CString GetSQLConStr(CString IP,CString DBName);
	BOOL Open(CString ConStr);
	CADOConnection();
	virtual ~CADOConnection();

};

class CADODataSet
{
protected:
	_RecordsetPtr m_DataSet;
	CADOConnection *m_Connection;
public:
	BOOL Open(CString SQLStr,int LockType);
	void Delete();
	int GetRecordNo();
	void move(int nIndex);
	void Save();
	void SetFieldValue(CString FieldName,_variant_t Value);
	void AddNew();
	BOOL Next();
	FieldsPtr GetFields();
	int GetRecordCount();
	void SetConnection(CADOConnection *pCon);
	BOOL Open(CString SQLStr);

	CADODataSet();
	virtual ~CADODataSet();
private:
	BOOL IsOpen();
};


CADOConnection * GetConnection();
#endif // !defined(AFX_ADO_H__EE0962C4_DC53_489D_981F_B112A39F9C1B__INCLUDED_)
