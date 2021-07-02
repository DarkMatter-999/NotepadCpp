#include "MainWindow.h"

MainWindow::MainWindow(wxWindow *parent,
wxWindowID id,
const wxString& title,
const wxPoint& pos,
const wxSize& size,
long style,
const wxString& name)
: wxFrame(parent, id, title, pos, size, style, name)
{
    //Creates a menubar
    wxMenuBar *menubar = new wxMenuBar();

    //Creates a menu
    wxMenu *filemenu = new wxMenu();

    //Create menu entries
    filemenu->Append(wxID_NEW);
    filemenu->Append(wxID_OPEN);
    filemenu->Append(wxID_SAVE);
    filemenu->Append(wxID_EXIT);

    //Adds filemenu to the menubar
    menubar->Append(filemenu, _("&File"));

    SetMenuBar(menubar);

}

MainWindow::~MainWindow()
{
    //dtor
}
