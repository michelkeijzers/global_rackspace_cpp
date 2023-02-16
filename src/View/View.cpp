#include "View.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"


View::View()
{
    _panes.push_back(new PrimaryKeyboardButtonsPane);
}