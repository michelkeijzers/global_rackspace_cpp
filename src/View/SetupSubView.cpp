#include "SetupSubView.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Model/MixerSubModel.h"
#include "Panes/ChannelsSetupPane.h"

SetupSubView::SetupSubView(Model &model, View &view) : SubView(model, view)
{
}

void SetupSubView::Fill() // override
{
    OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
    MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));

	 AddPane(*new ChannelsSetupPane(GetView(), mixerSubModel));

    SubView::Fill();
}

void SetupSubView::Init() // override
{
	// No action required
}
