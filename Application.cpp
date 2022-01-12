#include "Application.h"
#include "VPrincipal.h"
#include <wx/image.h>
#include "VPrincipal.h"

IMPLEMENT_APP(mxApplication)

bool mxApplication::OnInit() {
	
	wxInitAllImageHandlers(); // required to properly show custom images/icons
	
	VPrincipal *v = new VPrincipal(NULL); // create (load in memory) the main window
	v->Show(); // make the main window visible
	
	return true; // initialization finished ok
	
}

