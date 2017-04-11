' retrieved macro from: https://www.rondebruin.nl/win/s1/outlook/amail7.htm

Option Explicit
Sub SaveSend_Embedded_Chart()
'Working in 2000-2016
'For Tips see: http://www.rondebruin.nl/win/winmail/Outlook/tips.htm
    Dim OutApp As Object
    Dim OutMail As Object
    Dim Fname As String

    Set OutApp = CreateObject("Outlook.Application")
    Set OutMail = OutApp.CreateItem(0)

    'File path/name of the gif file
    Fname = Environ$("temp") & "\MoistureTemperature.gif"

    'Save Chart named "Chart 1" as gif file
    'If you hold down the CTRL key when you select the chart
    'in 2000-2013 you see the name in the Name box(formula bar)
    ActiveWorkbook.Worksheets("Simple Data with Plots").ChartObjects("Chart 1").Chart.Export _
            Filename:=Fname, FilterName:="GIF"

    On Error Resume Next
    With OutMail
        .To = "ericjmgraham@gmail.com"
        .cc = ""
        .BCC = ""
        .Subject = "Daily Moisture and Temperature"
        .Body = "Attached is the daily chart of the moisture and temperature readings."
        .Attachments.Add Fname
        .Send   'or use .Display
    End With
    On Error GoTo 0

    'Delete the gif file
    Kill Fname

    Set OutMail = Nothing
    Set OutApp = Nothing
End Sub
