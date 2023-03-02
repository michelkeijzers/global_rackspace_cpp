#pragma once

#include "WidgetIds.h"
#include <string>

class WidgetIds;
class Widget
{
  public:
    Widget(WidgetIds& widgetIds, WidgetIds::EWidgetId id, bool isListenedTo);
	 	 
    WidgetIds::EWidgetId GetId();
    std::string GetName();
    bool IsListenedTo();

  private:
    WidgetIds::EWidgetId _id;
    bool _isListenedTo;
    WidgetIds& _widgetIds;
};