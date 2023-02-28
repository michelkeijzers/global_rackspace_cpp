#pragma once

#include <memory>
#include <string>
#include "Pane.h"

class View;
class OrganSubModel;

class PrimaryKeyboardButtonsPane : public Pane
{
  public:
    const static std::string WIDGET_BUTTON_NAME;

    PrimaryKeyboardButtonsPane(View *view, std::shared_ptr<OrganSubModel> organSubModel);

    void Init() override;

	 void Update(const std::string &changedProperty) override;
};
