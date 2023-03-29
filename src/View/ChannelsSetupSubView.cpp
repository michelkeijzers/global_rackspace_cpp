#include "ChannelsSetupSubView.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "Panes/ChannelsSetupPane.h"

ChannelsSetupSubView::ChannelsSetupSubView(Model &model, View &view) : SubView(model, view)
{
}

void ChannelsSetupSubView::Fill() // override
{
   MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));
   GetPanes().AddPane(new ChannelsSetupPane(GetView(), mixerSubModel, 0, 0, 1.0, 1.0));
   SubView::Fill();
}
