#pragma once

#include "Plugin.h"
#include <vector>

class MixerSubModel;
class View;

class GainAndBalanceControlPlugin : public Plugin
{
  public:
    GainAndBalanceControlPlugin(View &view, MixerSubModel &mixerSubModel, const std::string &name);

    void Init() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

  private:
    MixerSubModel &_mixerSubModel;
};
