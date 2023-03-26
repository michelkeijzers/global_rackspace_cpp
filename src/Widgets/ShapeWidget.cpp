#include "ShapeWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#include <string>

ShapeWidget::ShapeWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : Widget(ids, id, isListenedTo), _left(0), _top(0), _width(100), _height(100), _redOutlineColor(0.0),
      _greenOutlineColor(0.0), _blueOutlineColor(0.0), _alphaOutlineColor(0.0), _redFillColor(0.0),
      _greenFillColor(0.0), _blueFillColor(0.0), _alphaFillColor(0.0), _redTextColor(0.0), _greenTextColor(0.0),
      _blueTextColor(0.0), _alphaTextColor(0.0), _outlineThickness(1)
{
}

void ShapeWidget::SetBounds(int left, int top, int width, int height)
{
   Debug::Log("c0");
   Debug::LogMethodEntry(__FUNCTION__, "left = " + std::to_string(left) + ", top = " + std::to_string(top) +
                                        ", width = " + std::to_string(width) + ", height = " + std::to_string(height) +
                                        ")");
   Debug::Assert(left > 0, __FUNCTION__, "Illegal left bound");
   Debug::Assert(top > 0, __FUNCTION__, "Illegal top bound");
   Debug::Assert(width > 0, __FUNCTION__, "Illegal width bound");
   Debug::Assert(height > 0, __FUNCTION__, "Illegal height bound");
   _left = left;
   _top = top;
   _width = width;
   _height = height;
   MvcFramework::GetGigPerformerApi().setWidgetBounds(GetName(), _left, _top, _width, _height);
   Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetLeft() { return _left; }

void ShapeWidget::SetLeft(int left)
{
   Debug::LogMethodEntry(__FUNCTION__, "left = " + std::to_string(left) + ")");
   Debug::Assert(left > 0, __FUNCTION__, "Illegal left bound");
   _left = left;
   MvcFramework::GetGigPerformerApi().setWidgetBounds(GetName(), _left, _top, _width, _height);
   Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetTop() { return _top; }

void ShapeWidget::SetTop(int top)
{
   Debug::LogMethodEntry(__FUNCTION__, "top = " + std::to_string(top) + ")");
   Debug::Assert(top > 0, __FUNCTION__, "Illegal top bound");
   _top = top;
   MvcFramework::GetGigPerformerApi().setWidgetBounds(GetName(), _left, _top, _width, _height);
   Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetWidth() { return _width; }

void ShapeWidget::SetWidth(int width)
{
   Debug::LogMethodEntry(__FUNCTION__, "width = " + std::to_string(width) + ")");
   Debug::Assert(width > 0, __FUNCTION__, "Illegal width bound");
   _width = width;
   MvcFramework::GetGigPerformerApi().setWidgetBounds(GetName(), _left, _top, _width, _height);
   Debug::LogMethodExit(__FUNCTION__);
}

int ShapeWidget::GetHeight() { return _height; }

void ShapeWidget::SetHeight(int height)
{
   Debug::LogMethodEntry(__FUNCTION__, "height = " + std::to_string(height) + ")");
   Debug::Assert(height > 0, __FUNCTION__, "Illegal height bound");
   _height = height;
   MvcFramework::GetGigPerformerApi().setWidgetBounds(GetName(), _left, _top, _width, _height);
   Debug::LogMethodExit(__FUNCTION__);
}

void ShapeWidget::SetWidgetOutlineColor(double red, double green, double blue, double alpha)
{
   Debug::LogMethodEntry(__FUNCTION__, "red = " + std::to_string(red) + ", green = " + std::to_string(green) +
                                        ", blue = " + std::to_string(blue) + ", alpha = " + std::to_string(alpha) +
                                        ")");
   AssertColors(red, green, blue, alpha);
   _redOutlineColor = red;
   _greenOutlineColor = green;
   _blueOutlineColor = blue;
   _alphaOutlineColor = alpha;
   MvcFramework::GetGigPerformerApi().setWidgetOutlineColor(
    GetName(), MvcFramework::GetGigPerformerApi().RGBAToColor(
                _redOutlineColor, _greenOutlineColor, _blueOutlineColor, _alphaOutlineColor));
   Debug::LogMethodExit(__FUNCTION__);
}

double ShapeWidget::GetWidgetOutlineColorRed() { return _redOutlineColor; }

double ShapeWidget::GetWidgetOutlineColorGreen() { return _greenOutlineColor; }

double ShapeWidget::GetWidgetOutlineColorBlue() { return _blueOutlineColor; }

double ShapeWidget::GetWidgetOutlineColorAlpha() { return _alphaOutlineColor; }

void ShapeWidget::SetWidgetFillColor(double red, double green, double blue, double alpha)
{
   Debug::LogMethodEntry(__FUNCTION__, "red = " + std::to_string(red) + ", green = " + std::to_string(green) +
                                        ", blue = " + std::to_string(blue) + ", alpha = " + std::to_string(alpha) +
                                        ")");
   AssertColors(red, green, blue, alpha);
   _redFillColor = red;
   _greenFillColor = green;
   _blueFillColor = blue;
   _alphaFillColor = alpha;
   MvcFramework::GetGigPerformerApi().setWidgetFillColor(GetName(),
    MvcFramework::GetGigPerformerApi().RGBAToColor(_redFillColor, _greenFillColor, _blueFillColor, _alphaFillColor));
   Debug::LogMethodExit(__FUNCTION__);
}

double ShapeWidget::GetWidgetFillColorRed() { return _redFillColor; }

double ShapeWidget::GetWidgetFillColorGreen() { return _greenFillColor; }

double ShapeWidget::GetWidgetFillColorBlue() { return _blueFillColor; }

double ShapeWidget::GetWidgetFillColorAlpha() { return _alphaFillColor; }

void ShapeWidget::SetWidgetTextColor(double red, double green, double blue, double alpha)
{
   Debug::LogMethodEntry(__FUNCTION__, "red = " + std::to_string(red) + ", green = " + std::to_string(green) +
                                        ", blue = " + std::to_string(blue) + ", alpha = " + std::to_string(alpha) +
                                        ")");
   AssertColors(red, green, blue, alpha);
   _redTextColor = red;
   _greenTextColor = green;
   _blueTextColor = blue;
   _alphaTextColor = alpha;
   Debug::NotImplemented(__FUNCTION__);
   // Not implemented by GP
   // MvcFramework::GetGigPerformerApi().setWidgetTextColor(
   //    GetName(), MvcFramework::GetGigPerformerApi().RGBAToColor(_redTextColor, _greenTextColor, _blueTextColor,
   //                                                             _alphaTextColor));

   Debug::LogMethodExit(__FUNCTION__);
}

double ShapeWidget::GetWidgetTextColorRed() { return _redTextColor; }

double ShapeWidget::GetWidgetTextColorGreen() { return _greenTextColor; }

double ShapeWidget::GetWidgetTextColorBlue() { return _blueTextColor; }

double ShapeWidget::GetWidgetTextColorAlpha() { return _alphaTextColor; }

void ShapeWidget::SetWidgetOutlineThickness(int thickness)
{
   _outlineThickness = thickness;
   MvcFramework::GetGigPerformerApi().setWidgetOutlineThickness(GetName(), _outlineThickness);
}

int ShapeWidget::GetWidgetOutlineThickness() { return _outlineThickness; }

void ShapeWidget::AssertColors(double red, double green, double blue, double alpha)
{
   Debug::Assert(red >= 0.0, __FUNCTION__, "Red color too low");
   Debug::Assert(red <= 1.0, __FUNCTION__, "Red color too high");
   Debug::Assert(green >= 0.0, __FUNCTION__, "Green color too low");
   Debug::Assert(green <= 1.0, __FUNCTION__, "Green color too high");
   Debug::Assert(blue >= 0.0, __FUNCTION__, "Blue color too low");
   Debug::Assert(blue <= 1.0, __FUNCTION__, "Blue color too high");
   Debug::Assert(alpha >= 0.0, __FUNCTION__, "Alpha too low");
   Debug::Assert(alpha <= 1.0, __FUNCTION__, "Alpha color too high");
}
