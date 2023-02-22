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
        PrimaryKeyboardButton1,
        PrimaryKeyboardButton2,
        PrimaryKeyboardButton3,
        PrimaryKeyboardButton4,
        PrimaryKeyboardButton5,
        PrimaryKeyboardButton6,
        PrimaryKeyboardButton7,
        PrimaryKeyboardButton8,
        PrimaryKeyboardButton9,
		  PrimaryKeyboardSlider1,
        PrimaryKeyboardSlider2,
        PrimaryKeyboardSlider3,
        PrimaryKeyboardSlider4,
        PrimaryKeyboardSlider5,
        PrimaryKeyboardSlider6,
        PrimaryKeyboardSlider7,
        PrimaryKeyboardSlider8,
        PrimaryKeyboardSlider9,
		  LastWidget
    };

    Widgets(gigperformer::sdk::GigPerformerAPI *gigPerformerApi);

    void SetValue(std::string widgetName, double value);
    void ShowWidget(std::string widgetName, bool show);
    void SetWidgetLabelText(std::string widgetName, std::string labelText);
    void SetWidgetFillColor(std::string widgetName, double red, double green, double blue, double alpha);

    static std::string GetWidgetName(EWidgetId widgetId);
    static EWidgetId GetWidgetId(std::string widgetName);

  private:
    void AssertIfWidgetDoesNotExist(std::string widgetName);

    std::vector<std::string> _widgetNames;

    gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};