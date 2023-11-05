#include "GUIApp.h"
#include "GUIFrame.h"


    bool GUIApp::OnInit()
    {
        GUIFrame* frame = new GUIFrame();
        frame->Show(true);
        return true;
    }

wxIMPLEMENT_APP(GUIApp);