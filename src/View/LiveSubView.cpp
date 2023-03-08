#include "LiveSubView.h"
#include "Panes/OrganPane.h"
#include "Panes/SlidersPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
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

    AddPane(*new OrganPane(GetView(), organSubModel));
    AddPane(*new SlidersPane(GetView(), (MixerSubModel &)GetModel().GetSubModel(SubModels::ESubModelId::Mixer),
                             (OrganSubModel &)GetModel().GetSubModel(SubModels::ESubModelId::Organ)));
    AddPane(*new PrimaryKeyboardButtonsPane(GetView(), organSubModel));

	 SubView::Fill(); // TODO: Move this function to Add Panes, 
	 // instead of fill, so this call can be removed., AddPanes will be a function called
	 // from the baseclass Fill
}

