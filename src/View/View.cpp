#include "View.h"
#include "../Model/Model.h"
#include "../Plugins/Plugins.h"
#include "SubViews.h"

View::View(Model &model) : _model(model), _subViews(model, *this), _plugins(model, *this) {}

void View::Fill()
{
   _widgetIds.Fill();
   _subViews.Fill();
   _plugins.Fill();
}

void View::Init()
{
   _subViews.Init();
   _plugins.Init();
}

Model &View::GetModel() { return _model; }

WidgetIds &View::GetWidgetIds() { return _widgetIds; }
