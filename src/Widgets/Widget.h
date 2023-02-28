#pragma once

#include "WidgetIds.h"
#include <memory>
#include <string>

class Widget
{
  public:
    Widget(std::shared_ptr<WidgetIds> widgetIds, WidgetIds::EWidgetId id, bool isListenedTo);
	 	 
    WidgetIds::EWidgetId GetId();
    std::string GetName();
    bool IsListenedTo();

  private:
    WidgetIds::EWidgetId _id;
    bool _isListenedTo;
    std::shared_ptr<WidgetIds> _widgetIds;
};