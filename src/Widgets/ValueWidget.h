#pragma once

#include "TextWidget.h"
#include "WidgetIds.h"
#include <memory>
#include <string>

class ValueWidget : public TextWidget
{
  public:
    ValueWidget(std::shared_ptr<WidgetIds> ids, WidgetIds::EWidgetId id, bool isListenedTo);

    void SetValue(double value);
    double GetValue();

  private:
    double _value;
};