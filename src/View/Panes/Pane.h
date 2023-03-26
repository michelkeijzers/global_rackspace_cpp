#pragma once

#include "../../Widgets/Widgets.h"
#include "../IObserver.h"
#include <string>

class View;

class Pane : public IObserver
{
 public:
   Pane(View &view);

   virtual void Fill() = 0;
   virtual void Init();
   void ShowAllWidgets(bool show = true);

 protected:
   Widgets &GetWidgets();
   View &GetView();

 private:
   Widgets _widgets;
   View &_view;
};
