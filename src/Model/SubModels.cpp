#include "../Model/SubModels.h"
#include "../Model/MixerSubModel.h"
#include "../Model/OrganSubModel.h"
#include "../Model/Model.h"

SubModels::SubModels()
{
}

SubModels::~SubModels()
{
    _subModels.clear();
}

void SubModels::Fill()
{
    _subModels.push_back(new MixerSubModel());
    _subModels.push_back(new OrganSubModel());
}

void SubModels::Init()
{
}

SubModel &SubModels::GetSubModelById(ESubModelId id)
{
    return *(_subModels.at((int) id));
}
