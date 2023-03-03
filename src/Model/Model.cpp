#include "Model.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"
#include "../Utilities/DoubleUtilities.h"

Model::Model()
{
    DoubleUtilities::SetMaximumEqualityDifference(0.01);
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
