#pragma once

#include "Widgets.h"
#include <memory>
#include <string>

class Controller;

class WidgetsListener
{
  public:
    WidgetsListener(std::shared_ptr<Controller> controller);

    void OnWidgetValueChanged(const std::string &widgetName, double newValue);

    void SetListeners();

  private:
    std::shared_ptr<Controller> _controller;

    void ProcessSlider(Widgets::EWidgetId widgetId, int sliderIndex, double newValue);
};
