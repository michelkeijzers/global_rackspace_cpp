
#ifdef _CONSOLE
   #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerFunctions.h"
#else
   #include "gigperformer/sdk/GigPerformerFunctions.h"
#endif

#include <vector>
#include "../Utilities/Debug.h"
#include "Widgets.h"
#include "Widget.h"

Widgets::Widgets()
{
    std::vector<std::string> widgetNames;
    getWidgetList(widgetNames, true); // Use global rackspace

	 for (std::string widgetName : widgetNames) 
		 {
         _widgets.push_back(new Widget(widgetName));
	 }
}


Widgets::~Widgets()
{
    for (auto widget : _widgets)
    {
        delete widget;
	 }
}


Widget* Widgets::GetWidgetByName(std::string name)
{
    for (auto &widget : _widgets)
    {
        if (widget->GetName() == name)
        {
            return widget;
        }
    }

	 Debug::Assert(false, __FUNCTION__, "Widget not found");
    return nullptr;
}