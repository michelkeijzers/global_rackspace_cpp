#include "Model.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"
#include "../Utilities/DoubleUtilities.h"

Model::Model()
{
    DoubleUtilities::SetMaximumEqualityDifference(1 / 127.0);
}

void Model::Fill()
{
    _subModels.Fill();
}

void Model::Init()
{
    _subModels.Init();
}

SubModel &Model::GetSubModel(SubModels::ESubModelId id)
{
    return _subModels.GetSubModel(id);
}
