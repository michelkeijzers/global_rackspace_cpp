#pragma once

#include <string>
#include "Plugin.h"
#include "../View/ChangedProperties.h"

class View;
class OrganSubModel;
class Controller;

class OrganPlugin : public Plugin
{
  public:
    OrganPlugin(View& view, OrganSubModel& organSubModel, const std::string& name);

	 void Update(ChangedProperties::EChangedProperty changedProperty) override;

	 void SetDrawbarValue(int drawbarIndex);
    void SetRotatorSpeed();
    void SetDrive();
    void SetReverbAmount();


	private:
    OrganSubModel &_organSubModel;
};
