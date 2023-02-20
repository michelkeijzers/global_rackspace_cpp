#pragma once

#include <memory>
#include <string>
#include <vector>

class Pane
{
  public:
    Pane();

	 void AddWidgetName(std::string widgetName);

	 std::string GetWidgetNameByIndex(uint8_t index);

	private:
    std::vector<std::string> _widgetNames;
};