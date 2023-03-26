#pragma once

#include "Plugin.h"

class MixerSubModel;
class View;

class AudioToCcPlugin : public Plugin
{
 public:
   AudioToCcPlugin(View &view, MixerSubModel &mixerSubModel, bool master, int channelIndex, const std::string &name);
   void Init() override;
   void Update(ChangedProperties::EChangedProperty changedProperty) override;

 private:
   void UpdateBypass(int channelIndex);

   MixerSubModel &_mixerSubModel;
   bool _master;
   int _channelIndex;
};
