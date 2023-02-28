#pragma once

#include <memory>
#include <string>
#include "Pane.h"

class OrganSubModel;
class View;

class OrganPane : public Pane
{
  public:
    OrganPane(View *view, std::shared_ptr<OrganSubModel> organSubModel);

	 void Init() override;

	 	 void Update(const std::string &changedProperty) override;
};
