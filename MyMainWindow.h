#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H
#include "wxfbWindows.h"

class MyMainWindow:public FBMainWindow {
protected:
	void ElegirBusqueda( wxCommandEvent& event ) ;
	void EnterBuscar( wxCommandEvent& event ) ;
	void ClickAgregarProveedor( wxCommandEvent& event ) ;
	void ClickBuscar( wxCommandEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickModificar( wxCommandEvent& event ) ;
	void ClickVender( wxCommandEvent& event ) ;

public:
	MyMainWindow(wxWindow *parent=NULL);
	void OnButtonClose(wxCommandEvent &evt);
};

#endif
