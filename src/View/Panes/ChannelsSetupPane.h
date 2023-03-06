#pragma once

#include "../ChangedProperties.h"
#include "Pane.h"
#include <string>

class MixerSubModel;
class View;

class ChannelsSetupPane : public Pane
{
  public:
    ChannelsSetupPane(View &view, MixerSubModel &mixerSubModel);

    void Init() override;

    void Fill() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

  private:
    MixerSubModel &_mixerSubModel;
};
