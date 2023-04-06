#include "View.h"
#include "../Model/Model.h"
#include "../Plugins/Plugins.h"
#include "SubViews.h"

View::View(Model &model, int width, int height)
    : _model(model), _subViews(model, *this), _plugins(model, *this), _width(width), _height(height)
{
}

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

Model &View::GetModel()
{
   return _model;
}

SubViews& View::GetSubViews()
{
   return _subViews;
}

WidgetIds &View::GetWidgetIds()
{
   return _widgetIds;
}

int View::GetWidth()
{
   return _width;
}
int View::GetHeight()
{
   return _height;
}
