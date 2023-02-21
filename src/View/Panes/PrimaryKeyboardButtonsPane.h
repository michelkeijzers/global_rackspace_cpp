#pragma once

#include <string>
#include "Pane.h"

class View;

class PrimaryKeyboardButtonsPane : public Pane
{
  public:
    const static std::string WIDGET_BUTTON_NAME;

    enum class EButton
    {
        BUTTON_1 = 0,
        BUTTON_2 = 1,
        BUTTON_3 = 2,
        BUTTON_4 = 3,
        BUTTON_5 = 4,
        BUTTON_6 = 5,
        BUTTON_7 = 6,
        BUTTON_8 = 7,
        BUTTON_9 = 8,
		  LAST_BUTTON
    };

	 PrimaryKeyboardButtonsPane(View* view);

	 void Init() override;

    std::string GetButtonWidget(EButton button);
};