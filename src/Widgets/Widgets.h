#pragma once

#include <vector>
#include <string>

#include "Widget.h"

class Widgets
{
  public:
    Widget* GetWidgetByName(std::string name);

  private:
    Widgets();
    ~Widgets();

    std::vector<Widget*> _widgets;
};