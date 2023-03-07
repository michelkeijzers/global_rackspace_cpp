#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Model/MixerSubModel.h"
#include "Panes/ChannelsSetupPane.h"
#include "PluginsSetupSubView.h"

PluginsSetupSubView::PluginsSetupSubView(Model &model, View &view) : SubView(model, view)
{
}

void PluginsSetupSubView::Fill() // override
{
    MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));

    AddPane(*new ChannelsSetupPane(GetView(), mixerSubModel));

    SubView::Fill();
}

void PluginsSetupSubView::Init() // override
{
    // No action required
}
