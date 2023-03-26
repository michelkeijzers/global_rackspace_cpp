#pragma once

#include "../ChangedProperties.h"
#include "Pane.h"
#include <string>

class OrganSubModel;
class View;

class OrganSetupPane : public Pane
{
 public:
   OrganSetupPane(View &view, OrganSubModel &organSubModel);

   void Fill() override;
   void Relayout() override;

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

 private:
   OrganSubModel &_organSubModel;
};
