#pragma once

#include "SubModels.h"

class Model
{
  public:
    Model();

	 void Fill();
    void Init();

	 SubModel &GetSubModelById(SubModels::ESubModelId id);

  private:
    SubModels _subModels;

};
