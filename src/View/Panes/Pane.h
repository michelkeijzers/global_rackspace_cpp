#pragma once

#include <memory>
#include <string>
#include <vector>

class View;

class Pane
{
  public:
    Pane(View *view);

    virtual void Init() = 0;

    void AddWidgetName(std::string widgetName);

    std::string GetWidgetNameByIndex(uint8_t index);

  private:
    std::vector<std::string> _widgetNames;

    View *_view;
};