#pragma once

#include <string>
#include "Pane.h"

class View;

class PrimaryKeyboardButtonsPane : public Pane
{
  public:
    const static std::string WIDGET_BUTTON_NAME;


	 PrimaryKeyboardButtonsPane(View* view);

	 void Init() override;

};