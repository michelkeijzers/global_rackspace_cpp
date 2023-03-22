#pragma once

#include <string>
#include "../ChangedProperties.h"
#include "Pane.h"
#include "../../Model/KeyboardSubModel.h"

class KeyboardModel;
class View;

class FootBoardPane : public Pane
{
  public:
    FootBoardPane(View &view, KeyboardSubModel &primaryKeyboardSubModel, KeyboardSubModel &secondaryKeyboardSubModel);

	 void Fill() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;
    void UpdateFootPedal(WidgetIds::EWidgetId widgetId, int volume);

  private:
    KeyboardSubModel &_primaryKeyboardSubModel;
    KeyboardSubModel &_secondaryKeyboardSubModel;
};
