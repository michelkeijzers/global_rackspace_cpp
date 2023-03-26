#pragma once

#include "../Plugins/Plugins.h"
#include "../Widgets/WidgetIds.h"
#include "SubViews.h"

class WidgetIds;
class Model;
class Pane;
class Plugin;

class View
{
 public:
   View(Model &model);

   void Fill();
   void Init();

   WidgetIds &GetWidgetIds();

   Model &GetModel();

 private:
   SubViews _subViews;
   Plugins _plugins;

   WidgetIds _widgetIds;
   Model &_model;
};
