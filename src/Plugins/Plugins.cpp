#include "Plugins.h"
#include "../Model/KeyboardSubModel.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Model/SubModels.h"
#include "AudioMixerPlugin.h"
#include "AudioToCcPlugin.h"
#include "ExpressionAudioMixerPlugin.h"
#include "GainAndBalanceControlPlugin.h"
#include "KeyboardPlugin.h"
#include "OrganPlugin.h"
#include "Plugin.h"

Plugins::Plugins(Model &model, View &view) : _plugins(), _model(model), _view(view)
{
}

Plugins::~Plugins()
{
   _plugins.clear();
}

void Plugins::Fill()
{
   _plugins.push_back(new OrganPlugin(
    _view, static_cast<OrganSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Organ)), "OrganPlugin"));
   _plugins.push_back(new AudioMixerPlugin(_view,
    static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)), true, "AudioMixerChannels1To16"));
   _plugins.push_back(
    new AudioMixerPlugin(_view, static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)), false,
     "AudioMixerChannels17To24"));
   _plugins.push_back(new GainAndBalanceControlPlugin(_view,
    static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)),
    "GainAndBalanceControlMainVolume"));

   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      _plugins.push_back(
       new AudioToCcPlugin(_view, static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)),
        false, channelIndex, "AudioToCcChannel" + std::to_string(channelIndex + 1)));
   }

   _plugins.push_back(
    new AudioToCcPlugin(_view, static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)), true,
     -1, "AudioToCcChannelMaster"));

   _plugins.push_back(new KeyboardPlugin(_view,
    static_cast<KeyboardSubModel &>(_model.GetSubModel(SubModels::ESubModelId::PrimaryKeyboard)), "PrimaryKeyboard"));
   _plugins.push_back(new KeyboardPlugin(_view,
    static_cast<KeyboardSubModel &>(_model.GetSubModel(SubModels::ESubModelId::SecondaryKeyboard)),
    "SecondaryKeyboard"));

   _plugins.push_back(new ExpressionAudioMixerPlugin(_view,
    static_cast<KeyboardSubModel &>(_model.GetSubModel(SubModels::ESubModelId::PrimaryKeyboard)),
    static_cast<KeyboardSubModel &>(_model.GetSubModel(SubModels::ESubModelId::SecondaryKeyboard)),
    static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)), true,
    "ExpressionAudioMixerChannels1To16"));
   _plugins.push_back(new ExpressionAudioMixerPlugin(_view,
    static_cast<KeyboardSubModel &>(_model.GetSubModel(SubModels::ESubModelId::PrimaryKeyboard)),
    static_cast<KeyboardSubModel &>(_model.GetSubModel(SubModels::ESubModelId::SecondaryKeyboard)),
    static_cast<MixerSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Mixer)), false,
    "ExpressionAudioMixerChannels17o24"));
}

void Plugins::Init()
{
   for (auto plugin : _plugins)
   {
      plugin->Init();
   }
}

Plugin &Plugins::GetPlugin(EPluginId id)
{
   return *(_plugins.at(static_cast<int>(id)));
}
