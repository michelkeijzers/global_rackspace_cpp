#pragma once

#include "TextWidget.h"
#include "WidgetIds.h"
#include <string>

class ButtonWidget : public TextWidget
{
 public:
   ButtonWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo);

   void SetPressed(bool isPressed);
   bool IsPressed();

 private:
   double _isPressed;
};
