#pragma once

#include <memory>
#include <string>
#include "Plugin.h"
#include "../View/View.h"

class OrganSubModel;
class Controller;

class OrganPlugin : public Plugin
{
  public:
    OrganPlugin(View *view, std::shared_ptr<OrganSubModel> organSubModel);

	 void Update(View::EChangedProperty changedProperty) override;

	 void SetDrawbarValue(int drawbarIndex, double newValue);
    void SetRotatorSpeedFast(bool fast);
};
