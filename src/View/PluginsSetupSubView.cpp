#include "PluginsSetupSubView.h"
#include "../Model/OrganSubModel.h"
#include "../Model/Model.h"
#include "Panes/OrganSetupPane.h" 
	
PluginsSetupSubView::PluginsSetupSubView(Model &model, View &view) : SubView(model, view) {}

void PluginsSetupSubView::Fill() // override
{
   OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
   GetPanes().AddPane(new OrganSetupPane(GetView(), organSubModel, 0, 0, 100, 100));
   SubView::Fill();
}
