#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
//TODO #include "Panes/ChannelsSetupPane.h"
#include "PluginsSetupSubView.h"

PluginsSetupSubView::PluginsSetupSubView(Model &model, View &view) : SubView(model, view)
{
}

void PluginsSetupSubView::Fill() // override
{
    OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));

    //TODO AddPane(*new ChannelsSetupPane(GetView(), mixerSubModel));

    SubView::Fill();
}

void PluginsSetupSubView::Init() // override
{
    // No action required
}
