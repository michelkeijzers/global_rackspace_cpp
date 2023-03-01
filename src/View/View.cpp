#include <memory>
#include "View.h"
#include "../Widgets/Widgets.h"
#include "Panes/OrganPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "../Plugins/OrganPlugin.h"
#include "../Model/Model.h"

View::View(std::shared_ptr<Model> model)
{
    _panes.push_back(std::make_shared<OrganPane>(this, model->GetOrganSubModel()));
    _panes.push_back(std::make_shared<PrimaryKeyboardButtonsPane>(this, model->GetOrganSubModel()));

	 _plugins.push_back(std::make_shared<OrganPlugin>(this, model->GetOrganSubModel()));

	 _model = model;
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
