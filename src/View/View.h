#pragma once

#include <memory>
#include <vector>
#include "../Widgets/Widgets.h"
#include "../Widgets/WidgetIds.h"

class Model;
class Pane;
class Plugin;

class View
{
  public:
    View(std::shared_ptr<Model> model);

    void FillWidgets();
    void Init(); // TODO: Change to relayout

	 WidgetIds& GetWidgetIds();

  private:
    std::vector<std::shared_ptr<Pane>> _panes; //TODO: make separate Panes class

	 std::vector<std::shared_ptr<Plugin>> _plugins; //TODO: Make separate Plugins class

	 WidgetIds _widgetIds;
};
