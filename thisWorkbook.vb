Private Sub Workbook_Open()
   frmStampDAQ.Show
   
   Application.OnTime TimeValue("17:00:00"), "Module3"
   
End Sub
