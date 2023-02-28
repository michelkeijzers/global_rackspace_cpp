#pragma once

#include <memory>
#include <string>
#include "Plugin.h"

class OrganSubModel;
class Controller;

class OrganPlugin : public Plugin
{
  public:
    OrganPlugin(View *view, std::shared_ptr<OrganSubModel> organSubModel);

	 void Update(const std::string &changedProperty) override;

	 void SetDrawbarValue(int drawbarIndex, double newValue);
    void SetRotatorSpeedFast(bool fast);
};
