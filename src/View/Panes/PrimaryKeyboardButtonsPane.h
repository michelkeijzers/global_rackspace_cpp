#pragma once

#include "../ChangedProperties.h"
#include "Pane.h"
#include <string>

class View;
class OrganSubModel;

class PrimaryKeyboardButtonsPane : public Pane
{
 public:
   const static int NR_OF_BUTTONS = 9 + 4;
   const static std::string WIDGET_BUTTON_NAME;

   PrimaryKeyboardButtonsPane(View &view, OrganSubModel &organSubModel);

   void Fill() override;
   void Relayout() override;

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

 private:
   OrganSubModel &_organSubModel;
};
