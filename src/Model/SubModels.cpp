#include "../Model/SubModels.h"
#include "../Model/MixerSubModel.h"
#include "../Model/OrganSubModel.h"
#include "../Model/Model.h"

SubModels::SubModels() : _forcedMode(false)
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
}

void SubModels::Init()
{
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