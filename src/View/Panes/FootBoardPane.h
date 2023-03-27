#pragma once

#include "../../Model/KeyboardSubModel.h"
#include "../ChangedProperties.h"
#include "Pane.h"
#include <string>

class KeyboardModel;
class View;

class FootBoardPane : public Pane
{
 public:
   FootBoardPane(View &view, KeyboardSubModel &primaryKeyboardSubModel, KeyboardSubModel &secondaryKeyboardSubModel,
    double leftPercentage, double topPercentage, double widthPercentage, double heightPercentage);

   void Fill() override;
   void Relayout() override;

   void Update(ChangedProperties::EChangedProperty changedProperty) override;
   void UpdateFootPedal(WidgetIds::EWidgetId widgetId, double volume);

 private:
   KeyboardSubModel &_primaryKeyboardSubModel;
   KeyboardSubModel &_secondaryKeyboardSubModel;
};
