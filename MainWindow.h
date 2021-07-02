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
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE,
            const wxString& name = wxASCII_STR(wxFrameNameStr));
        virtual ~MainWindow();

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
