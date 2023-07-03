# Описание сторонних компонентов и модулей SCADA

## Содержание

1. [EasyServer](#Компоненты-и-модули-EasyServer)
    - [Компоненты и модули MainForm](#Компоненты-и-модули-MainForm)
    - [Компоненты и модули SrvPropsDlg.dfm/pas](#Компоненты-и-модули-SrvPropsDlg.dfm/pas)
    - [Sender.pas](#Sender)
    - [ReporterConfigurationForm.dfm/pas](#ReporterConfigurationForm)
    - [AddPropsToReporterForm.dfm/pas](#AddPropsToReporterForm)
2. [Bugger](#Компоненты-и-модули-Bugger)
    - [Unit1.dfm/pas](#Unit1)
3. [DbEditorXML](#Компоненты-и-модули-DbEditorXML)
    - [uMain.dfm/pas](#uMain)  
4. [Services](#Компоненты-и-модули-Services)
    - [Bublog/bugserv.dll](#Bublog)  
    - [ClientPlog/ClientPropLog.dll](#ClientPlog)  
    - [ClientTlog/ClienTLog.dll](#ClientTlog)
    - [ConnectLog/ConnectLogSErvice.dll](#ConnectLog)
    - [MSUniServ/MSUniServ.dll](#MSUniServ)  
    - [Propserv/propserv.dll](#Propserv)  
    - [Common\MyUtils.pas](#Common)
5. [Monitor](#Компоненты-и-модули-Monitor)
    - [AboutMprDialog.pas](#AboutMprDialog)    
    - [AlarmConfigForm.pas](#AlarmConfigForm)
    - [ArchiveAlarmTableForm.pas](#ArchiveAlarmTableForm)
    - [ArhivForm.pas](#ArhivForm)  
    - [DateInputForm.pas](#DateInputForm)  
    - [Design_Form.pas](#Design_Form)
    - [DeviceInspectorForm.pas](#DeviceInspectorForm)
    - [ProjectImporter.pas](#ProjectImporter)
    - [PrjInsp_Form.pas](#PrjInsp_Form)
    - [ObjInspForm.pas](#ObjInspForm)  
    - [LabelLibraryDialog.pas](#LabelLibraryDialog)  
    - [PropertyDialog.pas](#PropertyDialog)
    - [receiver.pas](#receiver)
    - [Reflection_Workshop_0.pas](#Reflection_Workshop_0)  
    - [Reflection_Workshop_1.pas](#Reflection_Workshop_1)  
    - [ReffinspectorForm.pas](#ReffinspectorForm)
    - [RunTime_Form.pas](#RunTime_Form)
    - [uGaugeDlg.pas](#uGaugeDlg)
6. [Common](#Компоненты-и-модули-Common) 
    - [uSrvUtils2.pas](#uSrvUtils2)  
    - [SynEditForm.dfm/pas](#SynEditForm)
    - [RunExpr\Iner.pas](#RunExprIner)
    - [RunExpr\P_UTILS.pas](#RunExprP_UTILS)  
    - [RunExpr\P_Class.pas](#RunExprP_Class)  
    - [LabelLibraryUnit.pas](#LabelLibraryUnit)
    - [Prms_main.pas](#Prms_main)
    - [Maps_main.pas](#Maps_main)


## Компоненты и модули EasyServer

### Компоненты и модули MainForm

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
cxLocalizer|TcxLocalizer|DevExpress

Сторонние модули: cxLocalization, cxClasses.

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули SrvPropsDlg.dfm/pas 

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
SEPriority|TRxSpinEdit|RX Controls

Сторонние модули: RXSpin.

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули Sender.pas

Сторонних компонентов нет.

Сторонние модули: rxStrUtils.

Общие модули: 

[В содержание](#Содержание)

### Компоненты и модули ReporterConfigurationForm.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
ReportGridLevel1|TcxGridLevel|DevExpress
ReportGrid|TcxGrid|DevExpress
ReportGridTableView1|TcxGridTableView|DevExpress
NumberColumn|TcxGridColumn|DevExpress
ProjectNameColumn|TcxGridColumn|DevExpress
UnitNameColumn|TcxGridColumn|DevExpress
PropertyNameColumn|TcxGridColumn|DevExpress
DeltaTimeColumn|TcxGridColumn|DevExpress
DeltaColumn|TcxGridColumn|DevExpress
AlwaysWriteColumn|TcxGridColumn|DevExpress
ChannelIDColumn|TcxGridColumn|DevExpress
IsTagColumn|TcxGridColumn|DevExpress
cxStyleRepository|TcxStyleRepository|DevExpress
cxStyleReadOnlyColumn|TcxStyle|DevExpress
cxStyleReadWriteColumnHeader|TcxStyle|DevExpress

Сторонние модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxGridCustomTableView, cxGridTableView, cxGridCustomView, cxClasses, cxGridLevel, cxGrid.

[В содержание](#Содержание)

### Компоненты и модули AddPropsToReporterForm.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
cxGridLevel|TcxGridLevel|DevExpress
cxGrid|TcxGrid|DevExpress
cxGridTableView|TcxGridTableView|DevExpress
NumberColumn|TcxGridColumn|DevExpress
ProjectNameColumn|TcxGridColumn|DevExpress
nitNameColumn|TcxGridColumn|DevExpress
PropertyNameColumn|TcxGridColumn|DevExpress
AddColumn|TcxGridColumn|DevExpress
ChannelIDColumn|TcxGridColumn|DevExpress
IsTagColumn|TcxGridColumn|DevExpress
cxStyleRepository|TcxStyleRepository|DevExpress
cxStyleReadOnlyColumn|TcxStyle|DevExpress
cxStyleReadWriteColum|TcxStyle|DevExpress

Сторонние модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxGridCustomTableView, cxGridTableView, cxGridCustomView, cxClasses, cxGridLevel, cxGrid, cxNavigator.

[В содержание](#Содержание)

## Компоненты и модули Bugger

### Компоненты и модули Unit1.dfm/pas 

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
TAdsConnection|TAdsConnection|Advantage Database Components
TAdsQuery|TAdsQuery|Advantage Database Components

Сторонние модули: adsset, adstable, adscnnct, adsdata, adsfunc.

[В содержание](#Содержание)

## Компоненты и модули DbEditorXML

### Компоненты uMain.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|------------|
cxImageListForToolManagerSmall| TcxImageList|DevExpress
cxImageListForToolManagerLarge| TcxImageList|DevExpress
dxBarManager1| TdxBarManager|ExpressBars (DevExpress)
dxBarButton1| TdxBarButton|ExpressBars (DevExpress)
dxBarButton2| TdxBarButton|ExpressBars (DevExpress)
dxBarButton3| TdxBarButton|ExpressBars (DevExpress)
dxBarButton4| TdxBarButton|ExpressBars (DevExpress)
dxBarManager1Bar1| TdxBar|ExpressBars (DevExpress)
dxBarButton5| TdxBarButton|ExpressBars (DevExpress)
dxBarButton6| TdxBarButton|ExpressBars (DevExpress)
dxBarButton7| TdxBarButton|ExpressBars (DevExpress)
FormPlacement1| TFormPlacement|RX Tools

Сторонние модули:  dxBar, cxGraphics, cxClasses, rxPlacemnt , dxSkinsCore ;

Общие модули: BrowserFrom (..\OPC UA\Browser), uCaseDevice, uInit (..\wago_dsx.scr), uSrvUtils2 (..\Common.scr),uload_descr (..\wago_dsx.scr);

[В содержание](#Содержание)

## Компоненты и модули Services

### Компоненты и модули Bublog/bugserv.dll

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
BugConnection|TAdsConnection|Advantage
BugLog|TAdsTable|Advantage
AdsQuery|TAdsQuery|Advantage

Сторонние модули: AdsTable, AdsCnnct, AdsSet.

Общие модули: ..\Common\myutils.pas, ..\Common\ServMessages.pas.

[В содержание](#Содержание)

### Компоненты и модули ClientPlog/ClientPropLog.dll

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
AdsConnection|TAdsConnection|Advantage
ClientPLog|TAdsTable|Advantage
AdsQuery|TAdsQuery|Advantage

Сторонние модули: AdsTable, AdsCnnct, AdsSet.

Общие модули: ..\Common\myutils.pas, ..\Common\ServMessages.pas.

[В содержание](#Содержание)

### Компоненты и модули ClientTlog/ClienTLog.dll

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
AdsConnection|TAdsConnection|Advantage
ClientTLog|TAdsTable|Advantage
AdsQuery|TAdsQuery|Advantage

Сторонние модули: AdsTable, AdsCnnct, AdsSet.

Общие модули: ..\Common\myutils.pas, ..\Common\ServMessages.pas.

[В содержание](#Содержание)

### Компоненты и модули ConnectLog/ConnectLogSErvice.dll

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
AdsConnection|TAdsConnection|Advantage
ConnectLog|TAdsTable|Advantage
AdsQuery|TAdsQuery|Advantage

Сторонние модули: AdsTable, AdsCnnct, AdsSet.

Общие модули: Services.src\Common\myutils.pas, Services.src\Common\ServMessages.pas.

[В содержание](#Содержание)

### Компоненты и модули MSUniServ/MSUniServ.dll

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
FDPhysPgDriverLink|TFDPhysMSSQLDriverLink|Special class

Сторонние модули: FireDAC.Phys.MSSQL.

Общие модули: ..\Common\ServMessages.pas.

[В содержание](#Содержание)

### Компоненты и модули Propserv/propserv.dll

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
_StatTable|TAdsTable|Advantage
_Taglog|TAdsTable|Advantage
_Proplog|TAdsTable|Advantage
_tmpTable|TAdsTable|Advantage
_prevTaglog|TAdsTable|Advantage
_AdsQuery|TAdsQuery|Advantage
_AdsConnection|TAdsConnection|Advantage

Сторонние модули: AdsTable, AdsCnnct, AdsSet, ace.

Общие модули: ..\Common\MyUtils.pas, ..\Common\ServMessages.pas.

[В содержание](#Содержание)

### Компоненты и модули Common\MyUtils.pas

Сторонних компонентов нет.

Сторонние модули: AdsTable, AdsCnnct, AdsSet.

Общие модули: нет.

[В содержание](#Содержание)

## Компоненты и модули Monitor

### Компоненты AboutMprDialog.pas

Сторонних компонентов нет.

Сторонние модули: RxGIF

Общие модули: 

[В содержание](#Содержание)

### Компоненты AlarmConfigForm.pas

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|------------|
cxGridAlarms | TcxGrid | DevExpress
cxGridAlarmsTableView | TcxGridTableView | DevExpress
cxGridColumnAlarmNumber | TcxGridColumn | DevExpress
cxGridColumnAlarmEnabled | TcxGridColumn | DevExpress
cxGridColumnDescription | TcxGridColumn | DevExpress
cxGridColumnGroup | TcxGridColumn | DevExpress
cxGridColumnAlarmType | TcxGridColumn | DevExpress

Сторонние модули: cxStyles, cxCustomData, cxGraphics, cxFilter, cxData,cxDataStorage, cxEdit, cxGridLevel, cxClasses, cxControls, cxGridCustomView, cxGridCustomTableView, cxGridTableView, cxGrid, cxLookAndFeels,cxLookAndFeelPainters;

Общие модули: Project_main (..\Common.src), PropertyList (..\Common.src), Maps_main (..\Common.src), Alarms(..\Common.src), EditString(..\Common.src); 

[В содержание](#Содержание)

### Компоненты ArchiveAlarmTableForm.pas

Сторонних компонентов нет.

Сторонние модули: dxPSPrVwRibbon;

Общие модули: Reflection_Workshop_1;

[В содержание](#Содержание)

### Компоненты ArhivForm.pas

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|------------|
deStart|   TDateEdit| RX components
deFinish|  TDateEdit| RX components
ePeriod|   TRxSpinEdit| RX components

Сторонние модули: rxToolEdit, TeeProcs, TeEngine, Chart, Series, RXSpin;

Общие модули: PropertyList (..\Common.src), Project_main, Units_main (..\Common.src), Maps_main (..\Common.src);

[В содержание](#Содержание)

### Компоненты DateInputForm.pas

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|------------|
|cxDateNavigator1| TcxDateNavigator| DevExpress|

Сторонние модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, cxStyles, cxSchedulerStorage, cxSchedulerCustomControls, cxSchedulerDateNavigator, cxContainer, cxDateNavigator;

Общие модули:

[В содержание](#Содержание)

### Компоненты DeviceInspectorForm.pas

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|------------|
cxGridLevel | TcxGridLevel | DevExpress
cxGrid | TcxGrid | DevExpress
cxGridTableView | TcxGridTableView | DevExpress
cxGridColumnPropNumber | TcxGridColumn | DevExpress
cxGridColumnPropName | TcxGridColumn | DevExpress
cxGridColumnPropDescription | TcxGridColumn | DevExpress
cxGridColumnPropValue | TcxGridColumn | DevExpress
cxGridColumnPropDimension | TcxGridColumn | DevExpress

Сторонние модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxGridCustomTableView, cxGridTableView, cxGridCustomView, cxClasses, cxGridLevel, cxGrid, StdCtrls, cxEditRepositoryItems;

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули ProjectImporter.pas

Сторонних компонентов нет.

Сторонние модули: OXmlDOMVendor.

Общие модули: ..\Common.src\Project_main.pas, ..\Common.src\uSrvUtils2.pas, ..\Common.src\Units_main.pas, ..\Common.src\PropertyList.pas, ..\Common.src\Maps_main.pas.

[В содержание](#Содержание)

### Компоненты и модули PrjInsp_Form.dfm/pas

Расширение: dfm/pas.

Сторонних компонентов нет.

Сторонние модули: OXmlDOMVendor.

Общие модули: ChenSel.dfm/pas, ..\Common.src\uSrvUtils2.pas, ..\Common.src\Units_main.pas, ..\Common.src\Maps_main.pas.

[В содержание](#Содержание)

### Компоненты и модули ObjInspForm.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
lstObjView|TcxTreeList|DevExpress
tlstColumnPropsName|TcxTreeListColumn|DevExpress
tlstColumnPropsValue|TcxTreeListColumn|DevExpress
cxEditRepository|TcxEditRepository|DevExpress
erDate|TcxEditRepositoryDateItem|DevExpress
erButton|TcxEditRepositoryButtonItem|DevExpress
erComboBox|TcxEditRepositoryComboBoxItem|DevExpress
cxStyleRepository|TcxStyleRepository|DevExpress
cxStyleEven|TcxStyle|DevExpress
cxStyleOdd|TcxStyle|DevExpress

Сторонние модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxCustomData, cxStyles, cxTL, cxTLdxBarBuiltInMenu, cxInplaceContainer, cxTextEdit, cxEdit, cxEditRepositoryItems, cxClasses, cxButtonEdit.

Общие модули: ..\Common.src\PropertyList.pas, ChenSel.dfm/pas, ..\Common.src\MessageList.pas, EditPropForm.dfm/pas, MapViewForm.dfm/pas, LayerInspForm.dfm/pas RunTime_Form.dfm/pas  

[В содержание](#Содержание)

### Компоненты и модули LabelLibraryDialog.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
cxGridLabelLibraryLevel|TcxGridLevel|DevExpress
cxGridLabelLibrary|TcxGrid|DevExpress
cxGridLabelLibraryTableView|TcxGridTableView|DevExpress

Сторонние модули: cxStyles, cxCustomData, cxGraphics, cxFilter, cxData, cxDataStorage, cxEdit, cxLabel, cxGridCustomTableView, cxGridTableView, cxControls, cxGridCustomView, cxClasses, cxGridLevel, cxGrid, cxTextEdit, cxBlobEdit, cxLookAndFeels, cxLookAndFeelPainters, cxNavigator.

Общие модули: нет.

[В содержание](#Содержание)

### Компоненты и модули PropertyDialog.dfm/pas

Расширение: dfm/pas.

Сторонних компонентов нет.

Сторонние модули: RXSwitch.

Общие модули: ..\Common.src\Units_main.pas, ..\Common.src\RecipeList.pas, ..\Common.src\Project_main.pas, ..\Common.src\RunExpr\P_UTILS.PAS, ..\Common.src\MessageList.pas, ..\Common.src\PropertyList.pas, ..\Common.src\RunExpr\Iner.pas, ..\Common.src\SynEditForm.pas, ChenSel.dfm/pas, ReadWriteDialog.dfm/pas, ..\Common.src\InitiatorList.pas, RunTime_Form.dfm/pas, AddInitiatorForm.pas, ..\Common.src\App_Utils.pas, ..\AnimationForm.pas

[В содержание](#Содержание)

### Компоненты и модули receiver.pas

Нестандартных компонентов нет.

Сторонние модули: rxStrUtils

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули Reflection_Workshop_0.pas

Нестандартных компонентов нет.

Сторонние модули: cxGridCustomView, cxCustomData

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули Reflection_Workshop_1.pas

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
EditRepositoryButtonItem|TcxEditRepositoryButtonItem|DevExpress
Grid|TcxGrid|DevExpress
ObjectNameColumn|TcxGridColumn|DevExpress
PropertyDescriptionColumn|TcxGridColumn|DevExpress
PropertyNameColumn|TcxGridColumn|DevExpress
PropertyValueColumn|TcxGridColumn|DevExpress
RecordNumberColumn|TcxGridColumn|DevExpress
Style|TcxStyle|DevExpress
TableView|TcxGridTableView|DevExpress
AcceptTimeColumn|TcxGridColumn|DevExpress
BeginTimeColumn|TcxGridColumn|DevExpress
DescriptionColumn|TcxGridColumn|DevExpress
DriverIDColumn|TcxGridColumn|DevExpress
EndTimeColumn|TcxGridColumn|DevExpress
GroupColumn|TcxGridColumn|DevExpress
MachineColumn|TcxGridColumn|DevExpress
ObjectAlarmNumberColumn|TcxGridColumn|DevExpress
ObjectNumberColumn|TcxGridColumn|DevExpress
ObjectTypeColumn|TcxGridColumn|DevExpress
PriorityColumn|TcxGridColumn|DevExpress
StateColumn|TcxGridColumn|DevExpress
StyleConfirm|TcxStyle|DevExpress
StyleNotConfirm|TcxStyle|DevExpress
SuppressColumn|TcxGridColumn|DevExpress
TableView|TcxGridTableView|DevExpress
TypeColumn|TcxGridColumn|DevExpress
UserColumn|TcxGridColumn|DevExpress
Grid|TcxGrid|DevExpress

Сторонние модули: cxGrid, cxGridTableView, cxStyles, cxGridCustomTableView, cxEdit,cxEditRepositoryItems, RunTime_Form, App_utils, uVirtual, Messages, Alarms, dxCore, cxGridCustomView, cxCustomData, cxDataStorage

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули ReffinspectorForm.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
ReflectionInspector|TcxRTTIInspector|DevExpress

Сторонние модули: cxStyles, cxGraphics, cxEdit, cxControls, cxInplaceContainer, cxVGrid, cxOI

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули RunTime_Form.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
cxLocalizer|TcxLocalizer|DevExpress

Сторонние модули: cxLocalization, cxClasses

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули uGaugeDlg.dfm/pas

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
seMinValue|TRxSpinEdit|RXComponents
seMaxValue|TRxSpinEdit|RXComponents
seMinMinLimit|TRxSpinEdit|RXComponents
seMinLimit|TRxSpinEdit|RXComponents
seMaxMaxLimit|TRxSpinEdit|RXComponents
seMaxLimit|TRxSpinEdit|RXComponents

Сторонние модули: RXSpin

Общие модули:

[В содержание](#Содержание)

## Компоненты и модули Common

### Компоненты и модули uSrvUtils2.pas 

Нестандартных компонентов нет.

Нестандартнаы модули: OXmlDOMVendor

Общие модули:

[В содержание](#Содержание)

### Компоненты и модули SynEditForm.dfm/pas 

Расширение: dfm/pas.

Компоненты: 
|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
SyntAnalyzerCode|TSyntAnalyzer|SynEditorComponents
SMCode|TSyntaxMemo|SynEditorComponents
SyntKeyMapping|TSyntKeyMapping|SynEditorComponents
AcPopup|TAutoCompletePopup|SynEditorComponents
ACStyles|TSyntStyles|SynEditorComponents
SMAutoReplace|TSyntAutoReplace|SynEditorComponents
TemplatePopup|TTemplatePopup|SynEditorComponents
SyntFindDialog|TSyntFindDialog|SynEditorComponents
SyntReplaceDialog|TSyntReplaceDialog|SynEditorComponents
SyntaxTreeView|TSyntaxTreeView|SynEditorComponents
ecSelCharPopup1|TecSelCharPopup|SynEditorComponents

Нестандартнаы модули: ecSyntMemo, ecSyntAnal, ecPopupCtrl, ecKeyMap, ecAutoReplace, ecSyntDlg, ecSyntTree

[В содержание](#Содержание)

### Компоненты и модули RunExpr\Iner.pas 

Нестандартных компонентов нет.

Нестандартыне модули: rxvclutils, vclutils, rxstrutils.

Общие модули: P_UTILS.PAS.

[В содержание](#Содержание)

### Компоненты и модули RunExpr\P_UTILS.PAS 

Нестандартных компонентов нет.

Нестандартыне модули: rxvclutils, vclutils, rxGrids, rxSplit.

Общие модули: нет.

[В содержание](#Содержание)

### Компоненты и модули RunExpr\P_Class.pas 

Нестандартных компонентов нет.

Нестандартыне модули: AdsTable, adsdata, adsfunc, adsset,adscnnct, AppFace,p_utils.

Общие модули: P_UTILS.PAS, AppFace.pas.

[В содержание](#Содержание)

### Компоненты и модули LabelLibraryUnit.pas 

Нестандартных компонентов нет.

Нестандартыне модули: OXmlDOMVendor.

Общие модули: Project_main.pas, RunExpr\P_UTILS.PAS, RunExpr\Iner.pas.

[В содержание](#Содержание)

### Компоненты и модули Prms_main.pas 

Нестандартных компонентов нет.

Нестандартыне модули: OXmlDOMVendor.

Общие модули: нет.

[В содержание](#Содержание)

### Компоненты и модули Maps_main.pas 

Нестандартных компонентов нет.

Нестандартыне модули: cxOI, cxButtonEdit.

Общие модули: Units_main.pas, PropertyList.pas, Project_main.pas, RunExpr\P_UTILS.PAS, RunExpr\Iner.pas, ..\Monitor.src\Reflection_Workshop_0.pas, ..\Monitor.src\ObjInspForm.pas,
..\Monitor.src\RunTime_Form.pas, ..\Monitor.src\MapViewForm.pas, SynEditForm.pas, ..\Monitor.src\uAddProps.pas, App_Utils.pas, Alarms.pas, ..\Monitor.src\Reflection_Workshop.pas,
..\Monitor.src\Reflection_Workshop_1.pas.

[В содержание](#Содержание)
