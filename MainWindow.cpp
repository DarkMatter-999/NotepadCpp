#include "MainWindow.h"

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(wxID_NEW, MainWindow::OnNew)
EVT_MENU(wxID_OPEN, MainWindow::OnOpen)
EVT_MENU(wxID_SAVE, MainWindow::OnSave)
EVT_MENU(wxID_EXIT, MainWindow::OnExit)
EVT_MENU(wxID_HELP, MainWindow::OnHelp)
EVT_CLOSE(MainWindow::OnClose)
END_EVENT_TABLE()


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

    filemenu->AppendSeparator(); //Adds a separator looks nice XD

    wxMenuItem* quitItem = filemenu->Append(wxID_EXIT);

    Bind(wxEVT_CLOSE_WINDOW, &MainWindow::OnClose, this, quitItem->GetId());

    wxMenu *helpmenu = new wxMenu();
    helpmenu->Append(wxID_HELP, _("&About"));
    //Adds filemenu to the menubar
    menubar->Append(filemenu, _("&File"));
    menubar->Append(helpmenu, _("&Help"));

    SetMenuBar(menubar);

    const int SIZE = 5; //statusbar items size
    wxStatusBar *statusbar = CreateStatusBar(SIZE);

    statusbar->SetStatusText(_("Ln 1, Col 1"), 1);
    statusbar->SetStatusText(_("100%"), 2);
    statusbar->SetStatusText(_(""), 3);
    statusbar->SetStatusText(_("UTF-8"), 4);

    const int WIDTHS[SIZE] = {-10,-2,-1,-2,-2};

    statusbar->SetStatusWidths(SIZE, WIDTHS);

}

MainWindow::~MainWindow()
{
    //dtor
}

void MainWindow::OnNew(wxCommandEvent& event)
{
  wxMessageBox("OnNew Called");
}

void MainWindow::OnOpen(wxCommandEvent& event)
{
  wxMessageBox("OnOpen Called");
}

void MainWindow::OnSave(wxCommandEvent& event)
{
  wxMessageBox("OnSave Called");
}

void MainWindow::OnExit(wxCommandEvent& event)
{
  wxMessageBox("OnExit Called");
  bool veto = Close();
}

void MainWindow::OnClose(wxCloseEvent& event)
{
  if(event.CanVeto()) {

    int answer = wxMessageBox(_("Close??"), _("Can close"), wxYES_NO);

    if(answer != wxYES)
    {
      event.Veto();
      return;
    }
  }
  Destroy();
}

void MainWindow::OnHelp(wxCommandEvent& event)
{
  wxMessageBox("A project by DarkMatter999-dev");
}
