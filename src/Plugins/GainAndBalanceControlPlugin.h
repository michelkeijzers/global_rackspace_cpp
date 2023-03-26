#pragma once

#include "Plugin.h"

class MixerSubModel;
class View;

class GainAndBalanceControlPlugin : public Plugin
{
 public:
   GainAndBalanceControlPlugin(View &view, MixerSubModel &mixerSubModel, const std::string &name);

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

 private:
   MixerSubModel &_mixerSubModel;
};
