#pragma once

#include <string>
#include <vector>
#include "../../Widgets/Widget.h"

class Pane
{
  public:
    Pane();

	 void AddWidget(std::string widgetName);

	 Widget* GetWidgetByIndex(uint8_t index);

	private:
    std::vector<Widget*> _widgets;
};