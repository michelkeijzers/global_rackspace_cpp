#pragma once

#include "TextWidget.h"
#include "WidgetIds.h"
#include <string>

class ButtonWidget : public UpdateOrganRotatorSpeed
{
 public:
   ButtonWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo);

   void SetPressed(bool isPressed);
   bool IsPressed();

   static bool IsPressed(double value);

 private:
   double _isPressed;
};
