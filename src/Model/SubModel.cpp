#include "SubModel.h"
#include "SubModels.h"

SubModel::SubModel(SubModels &subModels) : _subModels(subModels)
{
}


bool SubModel::IsForcedMode()
{
    return _subModels.IsForcedMode();
}