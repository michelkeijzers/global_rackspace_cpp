#include "Model.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"

Model::Model()
{
}

void Model::Init()
{
    _subModels.Init();
}

void Model::Fill()
{
    _subModels.Fill();
}

SubModel &Model::GetSubModelById(SubModels::ESubModelId id)
{
    return _subModels.GetSubModelById(id);
}
