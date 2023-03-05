#pragma once

#include "SubView.h"

class Model;
class View;

class SetupSubView : public SubView
{
  public:
    SetupSubView(Model &model, View &view);

  protected:
    void Fill() override;
    void Init() override;
};