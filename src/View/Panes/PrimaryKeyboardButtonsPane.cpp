#include "PrimaryKeyboardButtonsPane.h"
#include "Pane.h"


/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";


PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View *view) : Pane(view)
{
    for (int buttonIndex = 0; buttonIndex < (int) EButton::LAST_BUTTON; buttonIndex++)
    {
       // AddWidgetName(WIDGET_BUTTON_NAME + std::to_string(buttonIndex + 1));
    }
}


std::string PrimaryKeyboardButtonsPane::GetButtonWidget(PrimaryKeyboardButtonsPane::EButton button)
{
   return "" ; // return GetWidgetNameByIndex((int) button);
}


void PrimaryKeyboardButtonsPane::Init() /* override */
{
	// No init actions needed for now
}