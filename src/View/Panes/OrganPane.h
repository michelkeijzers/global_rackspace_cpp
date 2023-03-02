#pragma once

#include <string>
#include "Pane.h"
#include "../ChangedProperties.h"

class OrganSubModel;
class View;

class OrganPane : public Pane
{
  public:
    static const int NR_OF_DRAWBAR_SLIDERS = 9;

    OrganPane(View &view, OrganSubModel &organSubModel);

    void Init() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;
};
