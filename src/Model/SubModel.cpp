#include "SubModel.h"
#include "Model.h"

SubModel::SubModel(Model &model) : _model(model)
{
}

void SubModel::Init() // override
{
}

Model &SubModel::GetModel()
{
   return _model;
}

bool SubModel::IsForcedMode()
{
   return _model.IsForcedMode();
}
