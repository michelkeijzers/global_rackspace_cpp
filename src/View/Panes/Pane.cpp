#include "Pane.h"
#include "../../Utilities/Debug.h"
#include "../../Widgets/Widget.h"

Pane::Pane(View &view, int left, int top, int width, int height)
    : _view(view), _left(left), _top(top), _width(width), _height(height)
{
   Debug::Assert(left >= 0, __FUNCTION__, "Left too low");
   Debug::Assert(top >= 0, __FUNCTION__, "Top too low");
   Debug::Assert(width >= 0, __FUNCTION__, "Width too low");
   Debug::Assert(height >= 0, __FUNCTION__, "Height too low");
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

View &Pane::GetView() { return _view; }

Widgets &Pane::GetWidgets() { return _widgets; }

int Widgets::Size() { return static_cast<int>(_widgets.size()); }

