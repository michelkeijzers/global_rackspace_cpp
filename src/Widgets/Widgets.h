#pragma once

#include <memory>
#include <map>
#include "WidgetIds.h"

class Widget;

class Widgets
{
  public:
    Widgets();

	 void AddWidget(WidgetIds::EWidgetId id, std::shared_ptr<Widget> widget);
	 Widget &GetWidgetById(WidgetIds::EWidgetId id);

  private:
    std::map<WidgetIds::EWidgetId, std::shared_ptr<Widget>> _widgets;
};
