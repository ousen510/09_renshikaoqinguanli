; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUserEdit
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Person.h"

ClassCount=14
Class1=CPersonApp
Class2=CPersonDlg
Class3=CAboutDlg

ResourceCount=15
Resource1=IDD_DLGDEPT
Resource2=IDR_MAINFRAME
Resource3=IDD_DLGPASS
Resource4=IDD_DLGDEPTEDIT
Class4=CLoginDialog
Resource5=IDD_DLGPERSON
Class5=CUserManage
Resource6=IDD_DLGCHECKEDIT
Class6=CUserEdit
Resource7=IDD_ABOUTBOX
Class7=CPassWordEdit
Resource8=IDR_MAINMENU
Class8=CDeptManage
Resource9=IDD_DLGUSER
Class9=CDeptEdit
Resource10=IDD_DLGCHECK
Class10=CPersonManage
Resource11=IDD_DLGLOGIN
Class11=CPersonEdit
Resource12=IDD_PERSON_DIALOG
Class12=CCheckManage
Resource13=IDD_DLGCHECKSUM
Class13=CCheckEdit
Resource14=IDD_DLGPERSONEDIT
Class14=CCheckSum
Resource15=IDD_DLGUSEREDIT

[CLS:CPersonApp]
Type=0
HeaderFile=Person.h
ImplementationFile=Person.cpp
Filter=N

[CLS:CPersonDlg]
Type=0
HeaderFile=PersonDlg.h
ImplementationFile=PersonDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUCHECKSUM

[CLS:CAboutDlg]
Type=0
HeaderFile=PersonDlg.h
ImplementationFile=PersonDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PERSON_DIALOG]
Type=1
Class=CPersonDlg
ControlCount=0

[MNU:IDR_MAINMENU]
Type=1
Class=?
Command1=ID_MENUUSER
Command2=ID_MENUPASSWORD
Command3=ID_MENUEXIT
Command4=ID_MENUDEPT
Command5=ID_MENUPERSON
Command6=ID_MENUCHECK
Command7=ID_MENUCHECKSUM
CommandCount=7

[DLG:IDD_DLGLOGIN]
Type=1
Class=CLoginDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMUSERLIST,combobox,1344340226
Control6=IDC_EDITPASSWORD,edit,1350631584

[CLS:CLoginDialog]
Type=0
HeaderFile=LoginDialog.h
ImplementationFile=LoginDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDialog

[DLG:IDD_DLGUSER]
Type=1
Class=CUserManage
ControlCount=5
Control1=IDC_EDIT,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LISTGRID,SysListView32,1350631437
Control4=IDC_APPEND,button,1342242816
Control5=IDC_DELETE,button,1342242816

[CLS:CUserManage]
Type=0
HeaderFile=UserManage.h
ImplementationFile=UserManage.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_DELETE
VirtualFilter=dWC

[DLG:IDD_DLGUSEREDIT]
Type=1
Class=CUserEdit
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDITUSERNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDITPASSWORD,edit,1350631584

[CLS:CUserEdit]
Type=0
HeaderFile=UserEdit.h
ImplementationFile=UserEdit.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CUserEdit

[DLG:IDD_DLGPASS]
Type=1
Class=CPassWordEdit
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDITPASS,edit,1350631584

[CLS:CPassWordEdit]
Type=0
HeaderFile=PassWordEdit.h
ImplementationFile=PassWordEdit.cpp
BaseClass=CDialog
Filter=D
LastObject=CPassWordEdit
VirtualFilter=dWC

[DLG:IDD_DLGDEPT]
Type=1
Class=CDeptManage
ControlCount=6
Control1=IDC_APPEND,button,1342242816
Control2=IDCANCEL,button,1342242817
Control3=IDC_EDIT,button,1342242816
Control4=IDC_DELETE,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_TREEDEPT,SysTreeView32,1350631431

[CLS:CDeptManage]
Type=0
HeaderFile=DeptManage.h
ImplementationFile=DeptManage.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TREEDEPT
VirtualFilter=dWC

[DLG:IDD_DLGDEPTEDIT]
Type=1
Class=CDeptEdit
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDITDEPTNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDITDEPTMEMO,edit,1352728580
Control7=IDC_CHECKROOT,button,1342242819

[CLS:CDeptEdit]
Type=0
HeaderFile=DeptEdit.h
ImplementationFile=DeptEdit.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDeptEdit

[DLG:IDD_DLGPERSON]
Type=1
Class=CPersonManage
ControlCount=8
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_TREEDEPT,SysTreeView32,1350631463
Control5=IDC_LISTPERSON,SysListView32,1350631429
Control6=IDC_EDIT,button,1342242816
Control7=IDC_APPEND,button,1342242816
Control8=IDC_DELETE,button,1342242816

[CLS:CPersonManage]
Type=0
HeaderFile=PersonManage.h
ImplementationFile=PersonManage.cpp
BaseClass=CDialog
Filter=D
LastObject=CPersonManage
VirtualFilter=dWC

[DLG:IDD_DLGPERSONEDIT]
Type=1
Class=CPersonEdit
ControlCount=39
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342177284
Control5=IDC_EID,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_ENAME,edit,1350631552
Control24=IDC_ENATIONALITY,edit,1350631552
Control25=IDC_CMARITAL,combobox,1344340226
Control26=IDC_ECULTURE,edit,1350631552
Control27=IDC_EFARTY,edit,1350631552
Control28=IDC_DBIRTH,SysDateTimePick32,1342242848
Control29=IDC_DHIRE,SysDateTimePick32,1342242848
Control30=IDC_CSEX,combobox,1344340226
Control31=IDC_ECARD,edit,1350631552
Control32=IDC_EOFFICE,edit,1350631552
Control33=IDC_EMOBILE,edit,1350631552
Control34=IDC_CDEPT,combobox,1344340226
Control35=IDC_EDUTY,edit,1350631552
Control36=IDC_EFAMILY,edit,1350631552
Control37=IDC_EFILES,edit,1350631552
Control38=IDC_EHUKOU,edit,1350631552
Control39=IDC_EMEMO,edit,1352728580

[CLS:CPersonEdit]
Type=0
HeaderFile=PersonEdit.h
ImplementationFile=PersonEdit.cpp
BaseClass=CDialog
Filter=D
LastObject=CPersonEdit
VirtualFilter=dWC

[DLG:IDD_DLGCHECK]
Type=1
Class=CCheckManage
ControlCount=13
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_CHECK1,button,1342242819
Control4=IDC_COMBOYY,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBOMM,combobox,1344340227
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMBOEMP,combobox,1344340227
Control10=IDC_LIST1,SysListView32,1350631425
Control11=IDC_APPEND,button,1342242816
Control12=IDC_EDIT,button,1342242816
Control13=IDC_DELETE,button,1342242816

[CLS:CCheckManage]
Type=0
HeaderFile=CheckManage.h
ImplementationFile=CheckManage.cpp
BaseClass=CDialog
Filter=D
LastObject=CCheckManage
VirtualFilter=dWC

[DLG:IDD_DLGCHECKEDIT]
Type=1
Class=CCheckEdit
ControlCount=22
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EMEMO,edit,1352728580
Control14=IDC_COMNAME,combobox,1344340226
Control15=IDC_DATETCHECK,SysDateTimePick32,1342242848
Control16=IDC_TIMEONDUTY,SysDateTimePick32,1342242857
Control17=IDC_TIMEOFFDUTY,SysDateTimePick32,1342242857
Control18=IDC_TIMEON,SysDateTimePick32,1342242857
Control19=IDC_TIMEOFF,SysDateTimePick32,1342242857
Control20=IDC_COMLEAVE,combobox,1344340226
Control21=IDC_TIMEONLEAVE,SysDateTimePick32,1342242857
Control22=IDC_TIMEOFFLEAVE,SysDateTimePick32,1342242857

[CLS:CCheckEdit]
Type=0
HeaderFile=CheckEdit.h
ImplementationFile=CheckEdit.cpp
BaseClass=CDialog
Filter=D
LastObject=CCheckEdit
VirtualFilter=dWC

[DLG:IDD_DLGCHECKSUM]
Type=1
Class=CCheckSum
ControlCount=8
Control1=IDC_LISTEMP,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CYY,combobox,1344340227
Control6=IDC_CMM,combobox,1344340227
Control7=IDC_CEMP,combobox,1344340227
Control8=IDCANCEL,button,1342242816

[CLS:CCheckSum]
Type=0
HeaderFile=CheckSum.h
ImplementationFile=CheckSum.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CMM
VirtualFilter=dWC

