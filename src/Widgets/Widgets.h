#pragma once

#include <memory>
#include <vector>

class Widget;

class Widgets
{
  public:
    Widgets();

	 void AddWidget(std::shared_ptr<Widget> widget);
 
  private:
    std::vector<std::shared_ptr<Widget>> _widgets;
};
