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
	 Widget &GetWidgetById(WidgetIds::EWidgetId id);

  private:
    std::map<WidgetIds::EWidgetId, Widget*> _widgets;
};
