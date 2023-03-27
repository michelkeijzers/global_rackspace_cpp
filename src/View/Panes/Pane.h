#pragma once

#include "../../Widgets/Widgets.h"
#include "../IObserver.h"
#include <string>

class View;

class Pane : public IObserver
{
 public:
   Pane(View &view, double leftPercentage, double topPercentage, double widthPercentage, double heightPercentage);

   virtual void Fill() = 0;
   virtual void Relayout() = 0;
   virtual void Init();
   void ShowAllWidgets(bool show = true);

 protected:
   Widgets &GetWidgets();
   View &GetView();

	void SetWidgetBounds(WidgetIds::EWidgetId widgetId, double widgetLeftPercentage, double widgetTopPercentage,
    double widgetWidthPercentage, double widgetHeightPercentage, double widgetMarginPercentage);
   double GetPaneTitleHeightPercentage();

 private:
   Widgets _widgets;
   View &_view;

   double _leftPercentage;
   double _topPercentage;
   double _widthPercentage;
   double _heightPercentage;
};
