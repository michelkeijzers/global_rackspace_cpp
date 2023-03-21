#pragma once

#include "../View/ChangedProperties.h"
#include "Plugin.h"
#include <string>

class View;
class KeyboardSubModel;
class Controller;

class KeyboardPlugin : public Plugin
{
  public:
    KeyboardPlugin(View &view, KeyboardSubModel &organSubModel, const std::string &name);

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

  private:
    KeyboardSubModel &_keyboardSubModel;
};
