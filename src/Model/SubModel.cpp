#include "SubModel.h"
#include "SubModels.h"

SubModel::SubModel(SubModels &subModels) : _subModels(subModels)
{
}

void SubModel::Init()
{
}

bool SubModel::IsForcedMode()
{
    return _subModels.IsForcedMode();
}

SubModels& SubModel::GetSubModels()
{
    return _subModels;
}