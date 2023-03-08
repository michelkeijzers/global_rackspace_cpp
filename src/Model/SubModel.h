#pragma once

class SubModels;

class SubModel
{
  public:
    SubModel(SubModels &subModels);

   virtual void Init();

  protected:
    bool IsForcedMode();

  private:
    SubModels &_subModels;
};
