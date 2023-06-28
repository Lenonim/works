 <h1 align = "center">Описание нестандартных компонентов и модулей SCADA</h1> 

##  Содержание 

1. [EasyServer](#EasyServer)
    - [MainForm.dfm/pas](#MainForm)
    - [SrvPropsDlg.dfm/pas](#SrvPropsDlg)
    - [Sender.pas](#Sender)
    - [ReporterConfigurationForm.dfm/pas](#ReporterConfigurationForm)
    - [AddPropsToReporterForm.dfm/pas](#AddPropsToReporterForm)
2. [Bugger](#Bugger)
    - [Unit1.dfm/pas](#Unit1)
3. [DbEditorXML](#DbEditorXML)
    - [uMain.dfm/pas](#uMain)  
    - [uCaseSubType.dfm/pas](#uCaseSubType)  
    - [uCaseDrv.dfm/pas](#uCaseDrv)
    - [PortPar.dfm/pas](#PortPar)
4. [Services](#Services)
    - [Bublog/bugserv.dll](#Bublog)  
    - [ClientPlog/ClientPropLog.dll](#ClientPlog)  
    - [ClientTlog/ClienTLog.dll](#ClientTlog)
    - [ConnectLog/ConnectLogSErvice.dll](#ConnectLog)
    - [MSUniServ/MSUniServ.dll](#MSUniServ)  
    - [Propserv/propserv.dll](#Propserv)  
    - [Common\MyUtils.pas](#Common)

## <a id="EasyServer"> Компоненты и модули EasyServer </a>

### <a id="MainForm"> Компоненты и модули MainForm.dfm/pas </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
cxLocalizer|TcxLocalizer|DevExpress

Нестандартные модули: cxLocalization, cxClasses.

Связующие модули:

### <a id="SrvPropsDlg">  Компоненты и модули SrvPropsDlg.dfm/pas  </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
SEPriority|TRxSpinEdit|RX Controls

Нестандартные модули: RXSpin.

### <a id="Sender"> Компоненты и модули Sender.pas </a>

Нестандартные модули: rxStrUtils.

Связующие модули:

### <a id="ReporterConfigurationForm"> Компоненты и модули ReporterConfigurationForm.dfm/pas </a>

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

Нестандартнаы модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, cxCustomData, cxFilter*, cxData, cxDataStorage, cxEdit, cxGridCustomTableView, cxGridTableView, cxGridCustomView, cxClasses, cxGridLevel, cxGrid.

Связующие модули:

### <a id="AddPropsToReporterForm"> Компоненты и модули AddPropsToReporterForm.dfm/pas </a>

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

Нестандартые модули: cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxGridCustomTableView, cxGridTableView, cxGridCustomView, cxClasses, cxGridLevel, cxGrid, cxNavigator.

Связующие модули:

## <a id="Bugger"> Компоненты и модули Bugger </a>

### <a id="Unit1"> Компоненты и модули Unit1.dfm/pas  </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
TAdsConnection|TAdsConnection|Advantage Database Components
TAdsQuery|TAdsQuery|Advantage Database Components

Нестандартные модули: adsset, adstable, adscnnct, adsdata, adsfunc.

## <a id="DbEditorXML"> Компоненты и модули DbEditorXML </a>

### <a id="uMain.pas"> Компоненты uMain.dfm/pas </a>

|Имя компонента|Тип компонента|Tool palette|
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

Нестандартные модули:  dxBar, cxGraphics, cxClasses, rxPlacemnt , dxSkinsCore ;

Связующие модули: BrowserFrom (..\OPC UA\Browser), uCaseDevice, uInit (..\wago_dsx.scr), uSrvUtils2 (..\Common.scr),uload_descr (..\wago_dsx.scr);

### <a id="uCaseSubType"> Компоненты uCaseSubType.dfm/pas </a>

Связующие модули: uSrvUtils2 (..\Common.scr);

### <a id="uCaseDrv"> Компоненты uCaseDrv.dfm/pas </a>

Связующие модули: uSrvUtils2 (..\Common.scr);


### <a id="PortPar"> Компоненты PortPar.dfm/pas </a>

Связующие модули: commint (..\Common.scr), UsrvUtils2 (..\Common.scr).

## <a id="Services"> Компоненты и модули Services </a>

### <a id="Bublog"> Компоненты и модули Bublog/bugserv.dll </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
BugConnection|TAdsConnection|
BugLog|TAdsTable|
AdsQuery|TAdsQuery|

Нестандартные модули: AdsTable, AdsCnnct, AdsSet.

Связующие модули: Services.src\Common\myutils.pas, Services.src\Common\ServMessages.pas.

### <a id="ClientPlog">  Компоненты и модули ClientPlog/ClientPropLog.dll </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
AdsConnection|TAdsConnection|
ClientPLog|TAdsTable|
AdsQuery|TAdsQuery|

Нестандартные модули: AdsTable, AdsCnnct, AdsSet.

Связующие модули: Services.src\Common\myutils.pas, Services.src\Common\ServMessages.pas.

### <a id="ClientTlog"> Компоненты и модули ClientTlog/ClienTLog.dll </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
AdsConnection|TAdsConnection|
ClientTLog|TAdsTable|
AdsQuery|TAdsQuery|

Нестандартные модули: AdsTable, AdsCnnct, AdsSet.

Связующие модули: Services.src\Common\myutils.pas, Services.src\Common\ServMessages.pas.

### <a id="ConnectLog"> Компоненты и модули ConnectLog/ConnectLogSErvice.dll </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
AdsConnection|TAdsConnection|
ConnectLog|TAdsTable|
AdsQuery|TAdsQuery|

Нестандартные модули: AdsTable, AdsCnnct, AdsSet.

Связующие модули: Services.src\Common\myutils.pas, Services.src\Common\ServMessages.pas.

### <a id="MSUniServ"> Компоненты и модули MSUniServ/MSUniServ.dll </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
FDPhysPgDriverLink|TFDPhysMSSQLDriverLink|Special class

Нестандартные модули: FireDAC.Phys.MSSQL.

Связующие модули: Services.src\Common\ServMessages.pas.

### <a id="Propserv"> Компоненты и модули Propserv/propserv.dll </a>

|Имя компонента|Тип компонента|Tool|
|--------------|--------------|----|
_StatTable|TAdsTable|
_Taglog|TAdsTable|
_Proplog|TAdsTable|
_tmpTable|TAdsTable|
_prevTaglog|TAdsTable|
_AdsQuery|TAdsQuery|
_AdsConnection|TAdsConnection|

Нестандартные модули: AdsTable, AdsCnnct, AdsSet, ace.

Связывающие модули: Services.src\Common\MyUtils.pas, Services.src\Common\ServMessages.pas.

### <a id="Common"> Компоненты и модули Common\MyUtils.pas </a>
Нестандартных компонентов нет.

Нестандартные модули: AdsTable, AdsCnnct, AdsSet.

Связывающие моудли: нет.