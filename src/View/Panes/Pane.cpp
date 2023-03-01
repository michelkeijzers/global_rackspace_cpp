#include "Pane.h"
#include "../../Utilities/Debug.h"
#include <memory>

Pane::Pane(View *view) : _view(view)
{
}

View *Pane::GetView()
{
    return _view;
}

Widgets *Pane::GetWidgets()
{
    return &_widgets;
}