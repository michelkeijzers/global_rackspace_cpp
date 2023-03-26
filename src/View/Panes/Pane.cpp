#include "Pane.h"
#include "../../Utilities/Debug.h"
#include "../../Utilities/DoubleUtilities.h"
#include "../../Widgets/Widget.h"
#include "../../Widgets/ShapeWidget.h"
#include "../View.h"

const int PANE_TITLE_HEIGHT_PERCENTAGE = 5; // Of view (screen height)

Pane::Pane(View &view, int leftPercentage, int topPercentage, int widthPercentage, int heightPercentage)
    : _view(view), _leftPercentage(leftPercentage), _topPercentage(topPercentage), _widthPercentage(widthPercentage),
      _heightPercentage(heightPercentage)
{
   Debug::Assert(leftPercentage >= 0, __FUNCTION__, "Left too low");
   Debug::Assert(leftPercentage <= 100, __FUNCTION__, "Left too high");
   Debug::Assert(topPercentage >= 0, __FUNCTION__, "Top too low");
   Debug::Assert(topPercentage <= 100, __FUNCTION__, "Top too high");
   Debug::Assert(widthPercentage >= 0, __FUNCTION__, "Width too low");
   Debug::Assert(widthPercentage <= 100, __FUNCTION__, "Width too high");
   Debug::Assert(heightPercentage >= 0, __FUNCTION__, "Height too low");
   Debug::Assert(heightPercentage <= 100, __FUNCTION__, "Height too high");
   Debug::Assert(leftPercentage + widthPercentage > 100, __FUNCTION__, "Left + Width too high");
   Debug::Assert(topPercentage + heightPercentage > 100, __FUNCTION__, "Top + Height too high");
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

void Pane::SetWidgetBounds(WidgetIds::EWidgetId widgetId, int widgetLeftPercentage, int widgetTopPercentage,
 int widgetWidthPercentage, int widgetHeightPercentage, int widgetMarginPercentage)
{
   int left = static_cast<int>(
    static_cast<double>(_leftPercentage + _widthPercentage * (widgetLeftPercentage + widgetMarginPercentage)) / 100.0 *
     _view.GetWidth() +
    0.5);
   int width =
    static_cast<int>(static_cast<double>(_widthPercentage * (widgetWidthPercentage - 2 * widgetMarginPercentage)) /
                      100.0 * _view.GetWidth() +
                     0.5);
   int top = static_cast<int>(
    static_cast<double>(_topPercentage + _heightPercentage * (widgetTopPercentage + widgetMarginPercentage)) / 100.0 *
     _view.GetHeight() +
    0.5);
   int height =
    static_cast<int>(static_cast<double>(_heightPercentage * (widgetHeightPercentage - 2 * widgetMarginPercentage)) /
                      100.0 * _view.GetHeight() +
                     0.5);
   ShapeWidget &widget = static_cast<ShapeWidget &>(GetWidgets().GetWidget(widgetId));
   widget.SetBounds(left, top, width, height);
}

int Pane::GetPaneTitleHeightPercentage() 
{
   return static_cast<int>((PANE_TITLE_HEIGHT_PERCENTAGE * 100.0) / _heightPercentage + 0.5);
}
