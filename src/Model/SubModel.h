#pragma once

class SubModels;

class SubModel
{
  public:
    SubModel(SubModels &subModels);

   virtual void Init();

  protected:
    bool IsForcedMode();

	 SubModels &GetSubModels();

  private:
    SubModels &_subModels;
};
