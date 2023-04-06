#pragma once

#include "../Plugins/Plugins.h"
#include "../Widgets/WidgetIds.h"
#include "SubViews.h"

class WidgetIds;
class Model;
class Plugin;

class View
{
 public:
   View(Model &model, int width, int height);
   void Fill();
   void Init();

   WidgetIds &GetWidgetIds();
   Model &GetModel();
   SubViews &GetSubViews();

   int GetWidth();
   int GetHeight();

 private:
   SubViews _subViews;
   Plugins _plugins;
   WidgetIds _widgetIds;
   Model &_model;

   int _width;
   int _height;
};
