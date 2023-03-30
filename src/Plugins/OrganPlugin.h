#pragma once

#include "../View/ChangedProperties.h"
#include "Plugin.h"
#include <string>

class View;
class OrganSubModel;

class OrganPlugin : public Plugin
{
 public:
   OrganPlugin(View &view, OrganSubModel &organSubModel, const std::string &name);

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

   void UpdateBypass();
   void UpdateDrawbarValue(int drawbarIndex);
   void UpdateRotatorSpeed();
   void UpdateDrive();
   void UpdateReverbAmount();

 private:
   OrganSubModel &_organSubModel;
};
