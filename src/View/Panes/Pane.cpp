#include "Pane.h"
#include "../../Utilities/Debug.h"
#include "../../Widgets/Widget.h"

Pane::Pane(View& view) : _view(view)
{
}

void Pane::Init()
{
	// No actions needed (widgets do not need to init.
}

void Pane::ShowAllWidgets(bool show /* = true */)
{
      for (auto &widgetId : GetWidgets().GetWidgetIds())
      {
         auto &widget = GetWidgets().GetWidget(widgetId);
         widget.Show(show);
      }
}

View &Pane::GetView()
   {
    return _view;
}

Widgets& Pane::GetWidgets()
{
    return _widgets;
}

int Widgets::Size()
{
    return static_cast<int>(_widgets.size());
}
