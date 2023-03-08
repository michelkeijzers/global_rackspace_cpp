#include "ChannelsSetupSubView.h"
#include "../Model/Model.h"
#include "../Model/MixerSubModel.h"
#include "Panes/ChannelsSetupPane.h"

ChannelsSetupSubView::ChannelsSetupSubView(Model &model, View &view) : SubView(model, view)
{
}

void ChannelsSetupSubView::Fill() // override
{
    MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));

	 AddPane(*new ChannelsSetupPane(GetView(), mixerSubModel));

	 SubView::Fill();
}
