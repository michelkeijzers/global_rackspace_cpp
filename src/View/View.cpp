#include "View.h"
#include "../Model/Model.h"
#include "../Plugins/OrganPlugin.h"
#include "../Widgets/Widgets.h"
#include "Panes/OrganPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"

View::View(Model &model)
    : _model(model), _organPane(*this, model.GetOrganSubModel()),
      _primaryKeyboardButtonsPane(*this, model.GetOrganSubModel()), _organPlugin(*this, model.GetOrganSubModel())
{
    _panes.AddPane(_organPane);
    _panes.AddPane(_primaryKeyboardButtonsPane);
    _plugins.AddPlugin(_organPlugin);
}

void View::FillWidgets()
{
}

void View::Init()
{
    _panes.Init();
    //TODO: Check if needed _plugins.Init();
}

Model &View::GetModel()
{
    return _model;
}

WidgetIds &View::GetWidgetIds()
{
    return _widgetIds;
}
