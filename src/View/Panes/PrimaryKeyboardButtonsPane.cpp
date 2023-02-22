#include "PrimaryKeyboardButtonsPane.h"
#include "Pane.h"


/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";


PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View *view) : Pane(view)
{
}


void PrimaryKeyboardButtonsPane::Init() /* override */
{
	// No init actions needed for now
}