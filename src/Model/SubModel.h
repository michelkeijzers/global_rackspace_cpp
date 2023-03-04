#pragma once

class SubModels;

class SubModel
{
  public:
    SubModel(SubModels &subModels);

    virtual void Init() = 0;

  protected:
    bool IsForcedMode();

  private:
    SubModels &_subModels;
};
