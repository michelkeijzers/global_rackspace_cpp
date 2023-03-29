#pragma once

#include "../ChangedProperties.h"
#include "Pane.h"
#include <string>

class OrganSubModel;
class View;

class OrganPane : public Pane
{
 public:
   static const int NR_OF_DRAWBAR_SLIDERS = 9;

   OrganPane(View &view, OrganSubModel &organSubModel, double leftPercentage, double topPercentage,
    double widthPercentage, double heightPercentage);

   void Fill() override;
   void Relayout() override;

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

   void ShowAllWidgets(bool show);

 private:
   OrganSubModel &_organSubModel;
};
