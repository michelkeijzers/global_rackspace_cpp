#pragma once

#include <string>

class SubModels;

class SubModel
{
  public:
    SubModel(SubModels &subModels);
    virtual const std::string GetDebugName() = 0;

    virtual void Init();

  protected:
    bool IsForcedMode();

	 SubModels &GetSubModels();

  private:
    SubModels &_subModels;
};
