'retrieved macro from: http://www.ozgrid.com/Excel/run-macro-on-time.htm

Option Explicit
Public dTime As Date
Dim lNum As Long

Sub RunOnTime()
    dTime = Now + TimeSerial(17, 0, 0)		'setting the macro to run at 17:00 everyday
    Application.OnTime dTime, "RunOnTime"
    
    lNum = lNum + 1
    If lNum = 3 Then
        Run "CancelOnTime"
    Else
        MsgBox lNum
    End If
    
End Sub

Sub CancelOnTime()
    Application.OnTime dTime, "RunOnTime", , False
    
End Sub

