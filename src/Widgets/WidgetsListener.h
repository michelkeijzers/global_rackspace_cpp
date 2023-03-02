#pragma once

#include "Widgets.h"
#include <string>
#include "WidgetIds.h"

class Controller;

class WidgetsListener
{
  public:
    WidgetsListener(Controller& controller, WidgetIds& widgetIds);

    void OnWidgetValueChanged(const std::string &widgetName, double newValue);

  private:
    Controller& _controller;
    WidgetIds& _widgetIds;

    void ProcessSlider(WidgetIds::EWidgetId widgetId, int sliderIndex, double newValue);
};
