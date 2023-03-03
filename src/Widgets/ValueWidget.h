#pragma once

#include "TextWidget.h"
#include "WidgetIds.h"
#include <string>

class ValueWidget : public TextWidget
{
  public:
    ValueWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo);

    void SetValue(double value);
    double GetValue();

    static bool IsButtonPressed(double value);

  private:
    double _value;
};