#include "PluginsSetupSubView.h"
#include "../Model/OrganSubModel.h"
#include "../Model/Model.h"
#include "Panes/OrganSetupPane.h" 
	
PluginsSetupSubView::PluginsSetupSubView(Model &model, View &view) : SubView(model, view) {}

void PluginsSetupSubView::Fill() // override
{
   OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
	AddPane(*new OrganSetupPane(GetView(), organSubModel));
   SubView::Fill();
}
