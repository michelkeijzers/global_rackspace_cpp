#pragma once

#include <vector>

class SubModel;
class Model;
class View;

class SubModels
{
  public:
    enum class ESubModelId
    {
		 Mixer,
        Organ
    };

    SubModels();
    ~SubModels();

    void Fill();
    void Init();

    SubModel &GetSubModelById(ESubModelId id);

  private:
    std::vector<SubModel *> _subModels;
};
