#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MainWindow : public wxFrame
{
    public:
        MainWindow(
            wxWindow *parent,
            wxWindowID id,
            const wxString& title,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxSize(800,600),
            long style = wxDEFAULT_FRAME_STYLE,
            const wxString& name = wxASCII_STR(wxFrameNameStr));
        virtual ~MainWindow();
          //Creates a menubar
          wxMenuBar *menubar = new wxMenuBar();

          //Creates a menu
          wxMenu *filemenu = new wxMenu();

          //text area
          wxTextCtrl *textarea;

          //Declare event handlers

          void OnNew(wxCommandEvent& event);
          void OnOpen(wxCommandEvent& event);
          void OnSave(wxCommandEvent& event);
          void OnHelp(wxCommandEvent& event);
          void OnExit(wxCommandEvent& event);

          void OnClose(wxCloseEvent& event);

          DECLARE_EVENT_TABLE();

    protected:

    private:
};

#endif // MAINWINDOW_H
