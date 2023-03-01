#pragma once

#include "../Widgets/WidgetIds.h"
#include "../Widgets/Widgets.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/PrimaryKeyboardButtonsPane.h"
#include "../Plugins/OrganPlugin.h"
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
    std::vector<Pane *> _panes; // TODO: make separate Panes class

    std::vector<Plugin *> _plugins; // TODO: Make separate Plugins class

    WidgetIds _widgetIds;
    std::shared_ptr<Model> _model;


	 OrganPane _organPane;
    PrimaryKeyboardButtonsPane _primaryKeyboardButtonsPane;

    OrganPlugin _organPlugin;
};
