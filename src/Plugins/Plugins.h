#pragma once

#include <vector>

class Plugin;

class Plugins
{
  public:
    Plugins();
    ~Plugins();

    void AddPlugin(Plugin& plugin);

  private:
    std::vector<Plugin *> _plugins;
};
