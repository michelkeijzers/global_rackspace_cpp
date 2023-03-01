#pragma once

#include "../Widgets/WidgetIds.h"
#include "../Widgets/Widgets.h"
#include <memory>
#include <vector>

class Model;
class Pane;
class Plugin;

class View
{
  public:
    View(std::shared_ptr<Model> model);

    void FillWidgets();
    void Init(); // TODO: Change to relayout

    WidgetIds &GetWidgetIds();

    std::shared_ptr<Model> GetModel();

  private:
    std::vector<std::shared_ptr<Pane>> _panes; // TODO: make separate Panes class

    std::vector<std::shared_ptr<Plugin>> _plugins; // TODO: Make separate Plugins class

    WidgetIds _widgetIds;
    std::shared_ptr<Model> _model;

  public:
    enum class EChangedProperty
    {
        Drawbar1,
        Drawbar2,
        Drawbar3,
        Drawbar4,
        Drawbar5,
        Drawbar6,
        Drawbar7,
        Drawbar8,
        Drawbar9
    };
};
