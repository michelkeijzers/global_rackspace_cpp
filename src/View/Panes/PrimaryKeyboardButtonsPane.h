#pragma once

#include <string>
#include "Pane.h"
#include "../ChangedProperties.h"

class View;
class OrganSubModel;

class PrimaryKeyboardButtonsPane : public Pane
{
  public:
    const static int NR_OF_BUTTONS = 9 + 4;
    const static std::string WIDGET_BUTTON_NAME;

    PrimaryKeyboardButtonsPane(View& view, OrganSubModel& organSubModel);

    void Init() override;

	 void Update(ChangedProperties::EChangedProperty changedProperty) override;
};
