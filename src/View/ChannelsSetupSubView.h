#pragma once

#include "SubView.h"

class Model;
class View;

class ChannelsSetupSubView : public SubView
{
  public:
    ChannelsSetupSubView(Model &model, View &view);

  protected:
    void Fill() override;
    void Init() override;
};