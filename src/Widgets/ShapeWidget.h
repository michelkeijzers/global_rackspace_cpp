#pragma once

#include "Widget.h"
#include <memory>

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

    void SetWidgetFillColor(double red, double green, double blue, double alpha);
    double GetWidgetFillColorRed();
    double GetWidgetFillColorGreen();
    double GetWidgetFillColorBlue();
    double GetWidgetFillColorAlpha();

  private:
    int _left;
    int _top;
    int _width;
    int _height;

    double _red;
    double _green;
    double _blue;
    double _alpha;
};