#pragma once

#include <map>
#include "WidgetIds.h"

class Widget;

class Widgets
{
  public:
    Widgets();
    ~Widgets();

	 void AddWidget(WidgetIds::EWidgetId id, Widget* widget);
    Widget &GetWidget(WidgetIds::EWidgetId id, int offset = 0);
     std::vector<WidgetIds::EWidgetId> GetWidgetIds();
    int Size();
	 
  private:
    std::map<WidgetIds::EWidgetId, Widget*> _widgets;
};
