#include "Plugins.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Model/SubModels.h"
#include "AudioMixerPlugin.h"
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
    _plugins.push_back(
        new OrganPlugin(_view, (OrganSubModel &)_model.GetSubModelById(SubModels::ESubModelId::Organ), "OrganPlugin"));
    _plugins.push_back(new AudioMixerPlugin(_view,
                                            (MixerSubModel &)_model.GetSubModelById(SubModels::ESubModelId::Mixer),
                                            true, "AudioMixerChannels1To16"));
    _plugins.push_back(new AudioMixerPlugin(_view,
                                            (MixerSubModel &)_model.GetSubModelById(SubModels::ESubModelId::Mixer),
                                            false, "AudioMixerChannels17To23"));
}

void Plugins::Init()
{
    for (auto plugin : _plugins)
    {
        plugin->Init();
    }
}

Plugin &Plugins::GetPluginById(EPluginId id)
{
    return *(_plugins.at((int)id));
}
