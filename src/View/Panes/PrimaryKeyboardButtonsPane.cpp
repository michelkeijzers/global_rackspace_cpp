#include "PrimaryKeyboardButtonsPane.h"

#include "../../Widgets/Widget.h"

/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";

PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane()
{
    for (int buttonIndex = 0; buttonIndex < (int) EButton::LAST_BUTTON; buttonIndex++)
    {
        AddWidget(WIDGET_BUTTON_NAME + std::to_string(buttonIndex + 1));
    }
}

Widget* PrimaryKeyboardButtonsPane::GetButtonWidget(PrimaryKeyboardButtonsPane::EButton button)
{
    return GetWidgetByIndex((int) button);
}