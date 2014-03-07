#include "main.h"
#include "AppDelegate.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    EGLView eglView;

    /// set the screen aspect ratio to be iPhone 5/5S
    /// the actual sizes on these machines is 640*1136, but it is too big 
    /// for windows simulation
    eglView.init("Fish Shot",480,480*1.775);
    return Application::getInstance()->run();
}
