#include <memory>
#include "View.h"
#include "../Widgets/Widgets.h"
#include "Panes/OrganPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "../Plugins/OrganPlugin.h"
#include "../Model/Model.h"

View::View(std::shared_ptr<Model> model)
    : _model(model),
  _organPane(this, model->GetOrganSubModel()),
    _primaryKeyboardButtonsPane(this, model->GetOrganSubModel()), 
	_organPlugin(this, model->GetOrganSubModel())
{
    _panes.push_back(&_organPane);
     _panes.push_back(&_primaryKeyboardButtonsPane);
    _plugins.push_back(&_organPlugin);
}

std::shared_ptr<Model> View::GetModel()
{
    return _model;
}

void View::FillWidgets()
{
}

void View::Init()
{
    for (auto &pane : _panes)
    {
        pane->Init();
    }
}

WidgetIds &View::GetWidgetIds()
{
    return _widgetIds;
}
