#pragma once

#include "../Plugins/OrganPlugin.h"
#include "../Plugins/Plugins.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/Panes.h"
#include "../View/Panes/PrimaryKeyboardButtonsPane.h"
#include "../Widgets/WidgetIds.h"
#include "../Widgets/Widgets.h"

class Model;
class Pane;
class Plugin;

class View
{
  public:
    View(Model &model);

    void FillWidgets();
    void Init(); // TODO: Change to relayout

    WidgetIds &GetWidgetIds();

    Model &GetModel();

  private:
    Panes _panes;
    Plugins _plugins;

    WidgetIds _widgetIds;
    Model &_model;

    OrganPane _organPane;
    PrimaryKeyboardButtonsPane _primaryKeyboardButtonsPane;

    OrganPlugin _organPlugin;
};
