#pragma once

#include "SubView.h"

class Model;
class View;

class PluginsSetupSubView : public SubView
{
  public:
    PluginsSetupSubView(Model &model, View &view);

  protected:
    void Fill() override;
    void Init() override;
};