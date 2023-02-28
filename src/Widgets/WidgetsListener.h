#pragma once

#include "Widgets.h"
#include <memory>
#include <string>
#include "WidgetIds.h"

class Controller;

class WidgetsListener
{
  public:
    WidgetsListener(std::shared_ptr<Controller> controller, WidgetIds& widgetIds);

    void OnWidgetValueChanged(const std::string &widgetName, double newValue);

  private:
    std::shared_ptr<Controller> _controller;
    WidgetIds& _widgetIds;

    void ProcessSlider(WidgetIds::EWidgetId widgetId, int sliderIndex, double newValue);
};
