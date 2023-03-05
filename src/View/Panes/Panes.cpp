#include "Panes.h"
#include "../../Model/Model.h"
#include "../../Model/SubModel.h"
#include "../../Model/OrganSubModel.h"
#include "OrganPane.h"
#include "Pane.h"
#include "PrimaryKeyboardButtonsPane.h"
#include "SlidersPane.h"

Panes::Panes(Model &model, View &view) : _panes(), _model(model), _view(view)
{
}

Panes::~Panes()
{
    _panes.clear();
}

void Panes::Fill()
{
   
	OrganSubModel &organSubModel = static_cast<OrganSubModel &>(_model.GetSubModel(SubModels::ESubModelId::Organ));
    _panes.push_back(new OrganPane(_view, organSubModel));
    _panes.push_back(new SlidersPane(_view, (MixerSubModel &)_model.GetSubModel(SubModels::ESubModelId::Mixer),
		 (OrganSubModel &)_model.GetSubModel(SubModels::ESubModelId::Organ)));
    _panes.push_back(new PrimaryKeyboardButtonsPane(_view, organSubModel));

    for (auto pane : _panes)
    {
        pane->Fill();
    }
}

void Panes::Init()
{
    for (auto pane : _panes)
    {
        pane->Init();
    }
}
