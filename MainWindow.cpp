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
    //Sets the icon
    this->SetIcon(icon);
    
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

    this->textarea = new wxTextCtrl(this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);

}

MainWindow::~MainWindow()
{
    //wxWidgets will take care of it
}

void MainWindow::OnNew(wxCommandEvent& event)
{
  //xMessageBox("OnNew Called");
  this->textarea->Clear();

}

void MainWindow::OnOpen(wxCommandEvent& event)
{
  //wxMessageBox("OnOpen Called");
  wxFileDialog *openFile = new wxFileDialog(this, _("Open File~"), _(""), _(""), _("Text Files (*.txt)|*.txt|All Files (*)|*"), wxFD_OPEN);
  int response = openFile->ShowModal();

  if (response == wxID_OK)
  {
    this->textarea->LoadFile(openFile->GetPath());
  }
}

void MainWindow::OnSave(wxCommandEvent& event)
{
  //wxMessageBox("OnSave Called");
  wxFileDialog *saveFile = new wxFileDialog(this, _("Save File~"), _(""), _(""), _("Text Files (*.txt)|*.txt|All Files (*)|*"), wxFD_SAVE);

  int response = saveFile->ShowModal();
  if (response == wxID_OK)
  {
    this->textarea->SaveFile(saveFile->GetPath());
  }
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
