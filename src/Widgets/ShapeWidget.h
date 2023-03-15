#pragma once

#include "Widget.h"

class ShapeWidget : public Widget
{
  public:
    ShapeWidget(WidgetIds& widgetIds, WidgetIds::EWidgetId widgetId, bool isListenedTo);

    void SetBounds(int left, int top, int width, int height);
    int GetLeft();
    void SetLeft(int left);
    int GetTop();
    void SetTop(int top);
    int GetWidth();
    void SetWidth(int width);
    int GetHeight();
    void SetHeight(int height);

    void SetWidgetOutlineColor(double red, double green, double blue, double alpha);
    double GetWidgetOutlineColorRed();
    double GetWidgetOutlineColorGreen();
    double GetWidgetOutlineColorBlue();
    double GetWidgetOutlineColorAlpha();

    void SetWidgetFillColor(double red, double green, double blue, double alpha);
    double GetWidgetFillColorRed();
    double GetWidgetFillColorGreen();
    double GetWidgetFillColorBlue();
    double GetWidgetFillColorAlpha();

	 void SetWidgetTextColor(double red, double green, double blue, double alpha);
    double GetWidgetTextColorRed();
    double GetWidgetTextColorGreen();
    double GetWidgetTextColorBlue();
    double GetWidgetTextColorAlpha();

	 void SetWidgetOutlineThickness(int thickness);
    int GetWidgetOutlineThickness();

  private:
    void AssertColors(double red, double green, double blue, double alpha);

    int _left;
    int _top;
    int _width;
    int _height;

    double _redOutlineColor;
    double _greenOutlineColor;
    double _blueOutlineColor;
    double _alphaOutlineColor;

    double _redFillColor;
    double _greenFillColor;
    double _blueFillColor;
    double _alphaFillColor;

    double _redTextColor;
    double _greenTextColor;
    double _blueTextColor;
    double _alphaTextColor;

	 int _outlineThickness;
};