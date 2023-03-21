#include "Pane.h"
#include "../../Utilities/Debug.h"

Pane::Pane(View& view) : _view(view)
{
}

void Pane::Init()
{
	// No actions needed (widgets do not need to init.
}

View& Pane::GetView()
{
    return _view;
}

Widgets& Pane::GetWidgets()
{
    return _widgets;
}

int Widgets::Size()
{
    return static_cast<int>(_widgets.size());
}