#pragma once

#include "../../Widgets/Widgets.h"
#include "../IObserver.h"
#include <string>

class View;

class Pane : public IObserver
{
 public:
   Pane(
    View &view, int leftPercentage, int topPercentage, int widthPercentage, int heightPercentage);

   virtual void Fill() = 0;
   virtual void Relayout() = 0;
   virtual void Init();
   void ShowAllWidgets(bool show = true);

 protected:
   Widgets &GetWidgets();
   View &GetView();

	void SetWidgetBounds(WidgetIds::EWidgetId widgetId, int widgetLeftPercentage, int widgetTopPercentage,
    int widgetWidthPercentage, int widgetHeightPercentage, int widgetMarginPercentage);
	int GetPaneTitleHeightPercentage();

 private:
   Widgets _widgets;
   View &_view;

   int _leftPercentage;
   int _topPercentage;
   int _widthPercentage;
   int _heightPercentage;
};
