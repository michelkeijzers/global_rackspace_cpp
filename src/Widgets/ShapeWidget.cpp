#include "ShapeWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#include <memory>
#include <string>

ShapeWidget::ShapeWidget(std::shared_ptr<WidgetIds> ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : Widget(ids, id, isListenedTo), _left(0), _top(0), _width(100), _height(100), _red(0.0), _green(0.0), _blue(0.0),
      _alpha(0.0)
{
}

void ShapeWidget::SetBounds(int left, int top, int width, int height)
{
    Debug::LogMethodEntry(__FUNCTION__, "left = " + std::to_string(left) + ", top = " + std::to_string(top) +
                                            ", width = " + std::to_string(width) +
                                            ", height = " + std::to_string(height) + ")");

    Debug::Assert(left > 0, __FUNCTION__, "Illegal left bound");
    Debug::Assert(top > 0, __FUNCTION__, "Illegal top bound");
    Debug::Assert(width > 0, __FUNCTION__, "Illegal width bound");
    Debug::Assert(height > 0, __FUNCTION__, "Illegal height bound");

    _left = left;
    _top = top;
    _width = width;
    _height = height;
    // TODO: MvcFramework::GetGigPerformerApi()->setWidgetBounds(GetName(), _left, _top, _width, _height);

    Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetLeft()
{
    return _left;
}

void ShapeWidget::SetLeft(int left)
{
    Debug::LogMethodEntry(__FUNCTION__, "left = " + std::to_string(left) + ")");

    Debug::Assert(left > 0, __FUNCTION__, "Illegal left bound");

    _left = left;
    // TODO: MvcFramework::GetGigPerformerApi()->setWidgetBounds(GetName(), _left, _top, _width, _height);

    Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetTop()
{
    return _top;
}

void ShapeWidget::SetTop(int top)
{
    Debug::LogMethodEntry(__FUNCTION__, "top = " + std::to_string(top) + ")");

    Debug::Assert(top > 0, __FUNCTION__, "Illegal top bound");

    _top = top;
    // TODO: MvcFramework::GetGigPerformerApi()->setWidgetBounds(GetName(), _left, _top, _width, _height);

    Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetWidth()
{
    return _width;
}

void ShapeWidget::SetWidth(int width)
{
    Debug::LogMethodEntry(__FUNCTION__, "width = " + std::to_string(width) + ")");

    Debug::Assert(width > 0, __FUNCTION__, "Illegal width bound");

    _width = width;
    // TODO: MvcFramework::GetGigPerformerApi()->setWidgetBounds(GetName(), _left, _top, _width, _height);

    Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetHeight()
{
    return _height;
}

void ShapeWidget::SetHeight(int height)
{
    Debug::LogMethodEntry(__FUNCTION__, "height = " + std::to_string(height) + ")");

    Debug::Assert(height > 0, __FUNCTION__, "Illegal height bound");

    _height = height;
    // TODO: MvcFramework::GetGigPerformerApi()->setWidgetBounds(GetName(), _left, _top, _width, _height);

    Debug::LogMethodExit(__FUNCTION__);
}

void ShapeWidget::SetWidgetFillColor(double red, double green, double blue, double alpha)
{
    Debug::LogMethodEntry(__FUNCTION__, "red = " + std::to_string(red) + ", green = " + std::to_string(green) +
                                            ", blue = " + std::to_string(blue) + ", alpha = " + std::to_string(alpha) +
                                            ")");

    Debug::Assert(red >= 0.0, __FUNCTION__, "Red color too low");
    Debug::Assert(red <= 1.0, __FUNCTION__, "Red color too high");
    Debug::Assert(green >= 0.0, __FUNCTION__, "Green color too low");
    Debug::Assert(green <= 1.0, __FUNCTION__, "Green color too high");
    Debug::Assert(blue >= 0.0, __FUNCTION__, "Blue color too low");
    Debug::Assert(blue <= 1.0, __FUNCTION__, "Blue color too high");
    Debug::Assert(alpha >= 0.0, __FUNCTION__, "Alpha too low");
    Debug::Assert(alpha <= 1.0, __FUNCTION__, "Alpha color too high");

    _red = red;
    _green = green;
    _blue = blue;
    _alpha = alpha;
    MvcFramework::GetGigPerformerApi()->setWidgetFillColor(
        GetName(), MvcFramework::GetGigPerformerApi()->RGBAToColor(_red, _green, _blue, _alpha));

    Debug::LogMethodExit(__FUNCTION__);
}

double ShapeWidget::GetWidgetFillColorRed()
{
    return _red;
}

double ShapeWidget::GetWidgetFillColorGreen()
{
    return _green;
}

double ShapeWidget::GetWidgetFillColorBlue()
{
    return _blue;
}

double ShapeWidget::GetWidgetFillColorAlpha()
{
    return _alpha;
}
