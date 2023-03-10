#include "LiveSubView.h"
#include "Panes/OrganPane.h"
#include "Panes/SlidersPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "Panes/ChannelsSetupPane.h"
#include "Panes/OrganSetupPane.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Model/MixerSubModel.h"
#include "Panes/Panes.h"

LiveSubView::LiveSubView(Model &model, View &view) : SubView(model, view)
{
}

void LiveSubView::Fill() // override
{
    OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
    MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));

    AddPane(*new OrganPane(GetView(), organSubModel));
    AddPane(*new SlidersPane(GetView(), mixerSubModel, organSubModel));
    AddPane(*new PrimaryKeyboardButtonsPane(GetView(), organSubModel));

	 AddPane(*new ChannelsSetupPane(GetView(), mixerSubModel));
	 AddPane(*new OrganSetupPane(GetView(), organSubModel));

	 SubView::Fill(); // TODO: Move this function to Add Panes, 
	 // instead of fill, so this call can be removed., AddPanes will be a function called
	 // from the baseclass Fill
}
