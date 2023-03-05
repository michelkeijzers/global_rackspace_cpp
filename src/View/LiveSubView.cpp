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

	 GetPanes().Fill();
}

void  LiveSubView::Init() // override
{
    // TODO Implement
}
