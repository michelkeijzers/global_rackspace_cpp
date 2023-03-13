#pragma once

#include "Widgets.h"
#include <string>
#include "WidgetIds.h"

//#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED
//#include "../../../global_rackspace_cpp2/build/windows-native/_deps/juce-src/modules/juce_core/juce_core.h"
//#include "../../../global_rackspace_cpp2/build/windows-native/_deps/juce-src/modules/juce_events/timers/juce_Timer.h"

#include <juce_core/juce_core.h>
#include <juce_events/timers/juce_Timer.h>

class Controller;

class WidgetsListener : public juce::Timer
{
  public:
    WidgetsListener(Controller& controller, WidgetIds& widgetIds);
    ~WidgetsListener();

    void OnWidgetValueChanged(const std::string &widgetName, double newValue);

  private:
    Controller& _controller;
    WidgetIds& _widgetIds;

    void ProcessSlider(int sliderIndex, double newValue);

	 void timerCallback() override;
};
