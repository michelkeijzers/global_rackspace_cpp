#pragma once

#include "WidgetIds.h"
#include "Widgets.h"
#include <string>

class Controller;

class WidgetsListener
{
 public:
   WidgetsListener(Controller &controller, WidgetIds &widgetIds);

   void OnWidgetValueChanged(const std::string &widgetName, double newValue);

 private:
   Controller &_controller;
   WidgetIds &_widgetIds;

   void ProcessSlider(int sliderIndex, double newValue);
};
