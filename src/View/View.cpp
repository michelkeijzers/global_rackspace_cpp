#include "View.h"
#include "../Model/Model.h"
#include "../Plugins/OrganPlugin.h"
#include "../Widgets/Widgets.h"
#include "Panes/OrganPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"

View::View(Model &model) : _model(model), _panes(model, *this), _plugins(model, *this)
{
}

void View::Fill()
{
    _widgetIds.Fill();
    _panes.Fill();
    _plugins.Fill();
}

void View::Init()
{

}

Model &View::GetModel()
{
    return _model;
}

WidgetIds &View::GetWidgetIds()
{
    return _widgetIds;
}
