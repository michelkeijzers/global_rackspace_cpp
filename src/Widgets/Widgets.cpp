#include "Widgets.h"
#include "../Utilities/Debug.h"
#include "Widget.h"
#include <iostream>
#include <vector>

Widgets::Widgets(gigperformer::sdk::GigPerformerAPI *gig_performer_api)
{
    std::vector<std::string> widgetNames;

    _gig_performer_api = gig_performer_api;
    _gig_performer_api->getWidgetList(widgetNames, true); // Use global rackspace

    for (std::string widgetName : widgetNames)
    {
        _widgetNames.push_back(widgetName);
    }
}

/*
Widget* Widgets::GetWidgetByName(std::string name)
{
    for (auto &widget : _widgets)
    {
        if (widget->GetName() == name)
        {
            return widget.get();
        }
    }

     Debug::Assert(false, __FUNCTION__, "Widget not found");
    return nullptr;
}
*/

void Widgets::SetValue(std::string widgetName, double value)
{
    AssertIfWidgetDoesNotExist(widgetName);

    //	 _gig_performer_api->setWidgetValue(widgetName, value);

    std::cout << "Widgets::SetValue: widgetName = " << widgetName << ", value = " << std::to_string(value) << "\n";
}

void Widgets::ShowWidget(std::string widgetName, bool show)
{
    //    AssertIfWidgetDoesNotExist(widgetName);

    //_gig_performer_api->SetWidgetHideOnPresentation(widgetName, !show);
    std::cout << "Widgets::ShowWidget: widgetName = " << widgetName << ", show = " << std::to_string(show) << "\n";
}

void Widgets::AssertIfWidgetDoesNotExist(std::string widgetName)
{
    if (!_gig_performer_api->widgetExists(widgetName))
    {
        Debug::Assert(false, "Widgets::SetValue", "Widget not found: " + widgetName);
    }
}
