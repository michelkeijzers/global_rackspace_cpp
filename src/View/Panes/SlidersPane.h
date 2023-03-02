#pragma once

#include "Pane.h"
#include <string>

class MixerSubModel;
class View;

class SlidersPane : public Pane
{
  public:
    static const int NR_OF_SLIDERS = 9;

    SlidersPane(View &view, MixerSubModel &mixerSubModel);

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

    void Init() override;
    void Fill() override;

  private:
    MixerSubModel &_mixerSubModel;
};
