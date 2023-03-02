#include "Plugins.h"
#include "../Model/Model.h"
#include "../Model/SubModels.h"
#include "OrganPlugin.h"
#include "Plugin.h"

Plugins::Plugins(Model &model, View &view) : _plugins(), _model(model), _view(view)
{
}

Plugins::~Plugins()
{
    _plugins.clear();
}

void Plugins::Fill()
{
    _plugins.push_back(new OrganPlugin(_view, (OrganSubModel &)_model.GetSubModel(SubModels::ESubModelId::Organ)));
}

void Plugins::Init()
{
}

Plugin &Plugins::GetPluginById(EPluginId id)
{
    return *(_plugins.at((int)id));
}
