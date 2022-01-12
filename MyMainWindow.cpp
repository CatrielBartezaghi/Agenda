#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(wxWindow *parent) : FBMainWindow(parent) {
  
}

void MyMainWindow::OnButtonClose( wxCommandEvent& event ) { 
	Close();
}

void MyMainWindow::ClickBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::DobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void MyMainWindow::ClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void MyMainWindow::ClickAgregar( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::ClickModificar( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::ClickVender( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::EnterBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::ClickAgregarProveedor( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::ElegirBusqueda( wxCommandEvent& event )  {
	event.Skip();
}

