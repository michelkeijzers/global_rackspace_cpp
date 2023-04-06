#pragma once

#include "WidgetIds.h"
#include "Widgets.h"
#include <juce_core/juce_core.h>
#include <juce_core/time/juce_Time.h>
#include <string>

class Controller;
class Widgets;
class WidgetIds;

class WidgetsListener
{
 public:
   WidgetsListener(Controller &controller, WidgetIds &widgetIds);

   void OnWidgetValueChanged(const std::string &widgetName, double newValue);

 private:
   void ProcessSlider(int sliderIndex, double newValue);

   /// \brief Returns true when pressed and not in bouncing mode (last press long enough ago).
   bool IsPressed(double value);

   Controller &_controller;
   WidgetIds &_widgetIds;
   juce::Time _lastButtonPressTime;
};
