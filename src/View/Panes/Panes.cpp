#include "Panes.h"
#include "Pane.h"
#include "OrganPane.h"
#include "SlidersPane.h"
#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/Model.h"

Panes::Panes(Model &model, View &view) : _panes(), _model(model), _view(view)
{
}

Panes::~Panes()
{
    _panes.clear();
}

void Panes::Fill()
{
    _panes.push_back(new OrganPane(_view, (OrganSubModel&) _model.GetSubModel(SubModels::ESubModelId::Organ)));
    _panes.push_back(new SlidersPane(_view, (MixerSubModel&) _model.GetSubModel(SubModels::ESubModelId::Mixer)));

	 for (auto pane : _panes)
    {
        pane->Fill();
    }
	 //_panes.push_back(new PrimaryKeyboardButtonsPane(_view, _model.GetSubModel(SubModels::ESubModuleId::xxx)));
}

void Panes::Init()
{
    for (auto pane : _panes)
    {
        pane->Init();
    }
}
