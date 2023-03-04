#pragma once

#include "SubModels.h"

class Model
{
  public:
    Model();

	 void Fill();
    void Init();

	 SubModel &GetSubModel(SubModels::ESubModelId id);

  private:
    SubModels _subModels;

};
