//#include "src/LibMain.h"
#include "Windows.h"

HWND hwndFound;


int main()
{
    //  LibraryHandle handle;

	 auto hwnd = FindWindow(nullptr, "Rackspace : image");
    return 1;
}