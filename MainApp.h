#ifndef MAINAPP_H
#define MAINAPP_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class MainApp : public wxApp
{
    public:
        MainApp();
        bool OnInit();
        virtual ~MainApp();

    protected:

    private:
};


#endif // MAINAPP_H


DECLARE_APP(MainApp);
