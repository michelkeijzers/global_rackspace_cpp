#pragma once

#include "Organ.h"

class Model
{
  public:
    Model();

	 Organ *GetOrgan();

  private:
	 Organ _organ;
};