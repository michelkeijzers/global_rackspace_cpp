#pragma once

#include "../../Widgets/Widgets.h"
#include "../IObserver.h"
#include <string>

class View;

class Pane : public IObserver
{
 public:
   Pane(View &view, int left, int top, int width, int height);

   virtual void Fill() = 0;
   virtual void Relayout() = 0;
   virtual void Init();
   void ShowAllWidgets(bool show = true);

 protected:
   Widgets &GetWidgets();
   View &GetView();

 private:
   Widgets _widgets;
   View &_view;

   int _left;
   int _top;
   int _width;
   int _height;
};
