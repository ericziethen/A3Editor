#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/button.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogEuropeanWorldChampionshipEdit : public wxDialog
{
public:
    DialogEuropeanWorldChampionshipEdit(wxWindow* parent, Toolset* const tools, Core::EMWM& emwm, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogEuropeanWorldChampionshipEdit();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

protected:
    wxStaticText* m_staticText;
    wxChoice* m_choiceCountry;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
    Core::EMWM& m_emwm;
    std::vector<std::string> m_countryList;
    int m_selectedCountry = 0;
};

