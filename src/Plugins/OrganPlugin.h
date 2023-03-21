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

    void UpdateBypass();
     void UpdateDrawbarValue(int drawbarIndex);
    void UpdateRotatorSpeed();
    void UpdateDrive();
    void UpdateReverbAmount();

	private:
    OrganSubModel &_organSubModel;
};
