#include <iostream>
#include <vector>

#include "Widgets.h"

#include "../Utilities/Debug.h"


Widgets::Widgets(gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
{
    std::vector<std::string> widgetNames;

    _gigPerformerApi = gigPerformerApi;
    _gigPerformerApi->getWidgetList(widgetNames, true); // Use global rackspace

    for (std::string widgetName : widgetNames)
    {
        _widgetNames.push_back(widgetName);
    }
}


void Widgets::SetValue(std::string widgetName, double value)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", show = " + std::to_string(value));
    AssertIfWidgetDoesNotExist(widgetName);
    // _gig_performer_api->setWidgetValue(widgetName, value);

    Debug::LogMethodExit(__FUNCTION__);
}


void Widgets::ShowWidget(std::string widgetName, bool show)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", show = " + std::to_string(show));
    AssertIfWidgetDoesNotExist(widgetName);

    //_gigPerformerApi->SetWidgetHideOnPresentation(widgetName, !show);
    _gigPerformerApi->setWidgetCaption(widgetName, std::to_string(show));
    Debug::LogMethodExit(__FUNCTION__);
}


void Widgets::AssertIfWidgetDoesNotExist(std::string widgetName)
{
    if (!_gigPerformerApi->widgetExists(widgetName))
    {
        Debug::Assert(false, "Widgets::SetValue", "Widget not found: " + widgetName);
    }
}
