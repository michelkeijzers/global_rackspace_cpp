#pragma once

#include <vector>
#include "../Widgets/WidgetIds.h"
#include "../Widgets/Widgets.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/PrimaryKeyboardButtonsPane.h"
#include "../Plugins/OrganPlugin.h"

class Model;
class Pane;
class Plugin;

class View
{
  public:
    View(Model& model);

    void FillWidgets();
    void Init(); // TODO: Change to relayout

    WidgetIds& GetWidgetIds();

    Model& GetModel();

  private:
    std::vector<Pane *> _panes; // TODO: make separate Panes class
    std::vector<Plugin *> _plugins; // TODO: Make separate Plugins class

    WidgetIds _widgetIds;
    Model& _model;

	 OrganPane _organPane;
    PrimaryKeyboardButtonsPane _primaryKeyboardButtonsPane;

    OrganPlugin _organPlugin;
};
