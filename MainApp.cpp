#include "MainApp.h"
#include "MainWindow.h"
#include "id.h"

IMPLEMENT_APP(MainApp);

MainApp::MainApp()
{
    //ctor
}

MainApp::~MainApp()
{
    //dtor
}

bool MainApp::OnInit()
{
  if(!wxApp::OnInit())
    return false;

  //Create a window frame in the app
  MainWindow *main = new MainWindow(nullptr, window::id::MAINWINDOW, _("NotepadC++"));
  main->Show();
  return true;
}
