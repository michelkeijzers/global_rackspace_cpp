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

void Widgets::SetWidgetLabelText(std::string widgetName, std::string labelText)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", labelText = " + labelText);
    AssertIfWidgetDoesNotExist(widgetName);

    _gigPerformerApi->setWidgetCaption(widgetName, labelText);
    Debug::LogMethodExit(__FUNCTION__);
}

void Widgets::SetWidgetFillColor(std::string widgetName, double red, double green, double blue, double alpha)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", red = " + std::to_string(red) +
                                            ", green = " + std::to_string(green) + ", blue = " + std::to_string(blue) +
                                            ", alpha = " + std::to_string(alpha));
    AssertIfWidgetDoesNotExist(widgetName);

    _gigPerformerApi->setWidgetFillColor(widgetName, _gigPerformerApi->RGBAToColor(red, green, blue, alpha));

    Debug::LogMethodExit(__FUNCTION__);
}

void Widgets::AssertIfWidgetDoesNotExist(std::string widgetName)
{
    if (!_gigPerformerApi->widgetExists(widgetName))
    {
        Debug::Assert(false, "Widgets::SetValue", "Widget not found: " + widgetName);
    }
}
