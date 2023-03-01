#pragma once

#include <memory>
#include <string>
#include "Pane.h"
#include "../ChangedProperties.h"

class OrganSubModel;
class View;

class OrganPane : public Pane
{
  public:
    OrganPane(View *view, std::shared_ptr<OrganSubModel> organSubModel);

	 void Init() override;

	 	 void Update(ChangedProperties::EChangedProperty changedProperty) override;
};
