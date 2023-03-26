#include "Panes.h"
#include "../../Model/Model.h"
#include "../../Model/OrganSubModel.h"
#include "../../Model/SubModel.h"
#include "OrganPane.h"
#include "Pane.h"
#include "PrimaryKeyboardButtonsPane.h"
#include "SlidersPane.h"

Panes::Panes(Model &model, View &view)
    : _panes(), _model(model), _view(view)
{
}

Panes::~Panes() { _panes.clear(); }

void Panes::AddPane(Pane *pane) 
{
	_panes.push_back(pane); 
}

void Panes::Fill()
{
   for (auto pane : _panes)
   {
      pane->Fill();
      pane->Relayout();
   }
}

void Panes::Init()
{
   for (auto pane : _panes)
   {
      pane->Init();
   }
}
