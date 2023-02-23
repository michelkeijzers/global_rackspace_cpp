#pragma once

#include <memory>
#include <string>
#include <vector>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

class Widgets
{
  public:
    enum class EWidgetId
    {
        Drawbar1,
        Drawbar2,
        Drawbar3,
        Drawbar4,
        Drawbar5,
        Drawbar6,
        Drawbar7,
        Drawbar8,
        Drawbar9,
        OrganRotatorSpeedTextLabel,
        PrimaryKeyboardButton1,
        PrimaryKeyboardButton2,
        PrimaryKeyboardButton3,
        PrimaryKeyboardButton4,
        PrimaryKeyboardButton5,
        PrimaryKeyboardButton6,
        PrimaryKeyboardButton7,
        PrimaryKeyboardButton8,
        PrimaryKeyboardButton9,
        Slider1,
        Slider2,
        Slider3,
        Slider4,
        Slider5,
        Slider6,
        Slider7,
        Slider8,
        Slider9,
        LastWidget
    };

    Widgets(gigperformer::sdk::GigPerformerAPI *gigPerformerApi);

    void SetWidgetValue(EWidgetId widgetId, double value);
    void ShowWidget(EWidgetId widgetId, bool show);
    void SetWidgetLabelText(EWidgetId widgetId, std::string labelText);
    void SetWidgetFillColor(EWidgetId widgetId, double red, double green, double blue, double alpha);

    static std::string GetWidgetName(EWidgetId widgetId);
    static EWidgetId GetWidgetId(std::string widgetName);

  private:
    void AssertIfWidgetDoesNotExist(std::string widgetName);

    std::vector<std::string> _widgetNames;

    gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};