#pragma once

#include <string>
#include "../Utilities/IObserver.h"

class View;

class Plugin : public IObserver
{
  public:
    Plugin(std::string name, View *view);

    std::string GetName();

  protected:
    View *GetView();

  private:
    std::string _name;

    View *_view;
};
