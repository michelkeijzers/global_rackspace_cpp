#pragma once

#include "SubModels.h"
#include "../View/Observable.h"

class Model : public Observable
{
  public:
    enum class ETimer
    {
        OneSecond
	 };

    Model();

	 void Fill();
    void Init();

	 void OnTimer(ETimer timer);

	 SubModel &GetSubModel(SubModels::ESubModelId id);

  private:

    SubModels _subModels;
};
