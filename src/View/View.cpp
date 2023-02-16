#include "View.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"


View::View(gigperformer::sdk::GigPerformerAPI *gig_performer_api) : _widgets(gig_performer_api)
{
    _panes.push_back(new PrimaryKeyboardButtonsPane);
}