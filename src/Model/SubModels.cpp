#include "../Model/SubModels.h"
#include "../Model/MixerSubModel.h"
#include "../Model/OrganSubModel.h"
#include "../Model/KeyboardSubModel.h"
#include "../Model/Model.h"

SubModels::SubModels(Model& model) : _model(model), _forcedMode(false)
{
}

SubModels::~SubModels()
{
    _subModels.clear();
}

void SubModels::Fill()
{
    _subModels.push_back(new MixerSubModel(*this));
    _subModels.push_back(new OrganSubModel(*this));
    _subModels.push_back(new KeyboardSubModel(*this, true));
    _subModels.push_back(new KeyboardSubModel(*this, false));
}

void SubModels::Init()
{
    for (auto subModel : _subModels)
    {
        subModel->Init();
    }
}

Model &SubModels::GetModel()
{
    return _model;
}

SubModel &SubModels::GetSubModel(ESubModelId id)
    {
    return *(_subModels.at((int) id));
}

bool SubModels::IsForcedMode()
{
    return _forcedMode;
}

void SubModels::SetForcedMode(bool forcedMode)
{
    _forcedMode = forcedMode;
}