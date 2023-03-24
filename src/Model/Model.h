#pragma once

#include "../View/Observable.h"
#include "SubModels.h"

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

    bool LoadSong();
    bool WriteSong();

  private:
    SubModels _subModels;
};
