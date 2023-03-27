#include "Pane.h"
#include "../../Utilities/Debug.h"
#include "../../Utilities/DoubleUtilities.h"
#include "../../Widgets/ShapeWidget.h"
#include "../../Widgets/Widget.h"
#include "../View.h"

const double PANE_TITLE_HEIGHT_PERCENTAGE = 0.05; // Of view (screen height)

Pane::Pane(View &view, double leftPercentage, double topPercentage, double widthPercentage, double heightPercentage)
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
   Debug::Assert(leftPercentage + widthPercentage <= 100, __FUNCTION__, "Left + Width too high");
   Debug::Assert(topPercentage + heightPercentage <= 100, __FUNCTION__, "Top + Height too high");
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

void Pane::SetWidgetBounds(WidgetIds::EWidgetId widgetId, double widgetLeftPercentage, double widgetTopPercentage,
 double widgetWidthPercentage, double widgetHeightPercentage, double widgetMarginPercentage)
{
   int left = static_cast<int>(
    (_leftPercentage + _widthPercentage * (widgetLeftPercentage + widgetMarginPercentage)) * _view.GetWidth() + 0.5);
   int width = static_cast<int>(
    (_widthPercentage * (widgetWidthPercentage - 2 * widgetMarginPercentage)) * _view.GetWidth() + 0.5);
   int top = static_cast<int>((
    _topPercentage + _heightPercentage * (widgetTopPercentage + widgetMarginPercentage)) * _view.GetHeight() + 0.5);
   int height = static_cast<int>(
    (_heightPercentage * (widgetHeightPercentage - 2 * widgetMarginPercentage)) * _view.GetHeight() + 0.5);
   ShapeWidget &widget = static_cast<ShapeWidget &>(GetWidgets().GetWidget(widgetId));
   widget.SetBounds(left, top, width, height);
}

double Pane::GetPaneTitleHeightPercentage()
{
   return PANE_TITLE_HEIGHT_PERCENTAGE / _heightPercentage;
}
