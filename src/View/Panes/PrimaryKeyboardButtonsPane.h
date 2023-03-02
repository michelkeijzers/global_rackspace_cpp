#pragma once

#include <string>
#include "Pane.h"
#include "../ChangedProperties.h"

class View;
class OrganSubModel;

class PrimaryKeyboardButtonsPane : public Pane
{
  public:
    const static std::string WIDGET_BUTTON_NAME;

    PrimaryKeyboardButtonsPane(View& view, OrganSubModel& organSubModel);

    void Init() override;

	 void Update(ChangedProperties::EChangedProperty changedProperty) override;
};
