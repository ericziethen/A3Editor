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
#include <wx/textctrl.h>
#include <wx/spinbutt.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/listctrl.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogAssociation : public wxDialog
{
public:
    DialogAssociation(wxWindow* parent, Toolset* const tools, const std::string selectedCountry, wxWindowID id = wxID_ANY, const wxString& title = _("Verband"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogAssociation();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnTextNameNationalTrainer(wxCommandEvent& event);
    void OnTextFirstnameNationalTrainer(wxCommandEvent& event);
    void OnChangeReputation(wxListEvent& event);
    void OnDayNationalTrainer(wxSpinEvent& event);
    void OnMonthNationalTrainer(wxSpinEvent& event);
    void OnYearNationalTrainer(wxSpinEvent& event);
    void OnCompetence(wxSpinEvent& event);

    void OnTextNamePresident(wxCommandEvent& event);
    void OnTextFirstnamePresident(wxCommandEvent& event);
    void OnDayPresident(wxSpinEvent& event);
    void OnMonthPresident(wxSpinEvent& event);
    void OnYearPresident(wxSpinEvent& event);

    void OnTextAssociation(wxCommandEvent& event);

protected:
    wxStaticText* m_staticText41;
    wxTextCtrl* m_textNameNationalTrainer;
    wxStaticText* m_staticText45;
    wxTextCtrl* m_textFirstnameNationalTrainer;
    wxStaticText* m_staticText49;
    wxStaticText* m_staticTextDayNationalTrainer;
    wxSpinButton* m_spinButtonDayNationalTrainer;
    wxStaticText* m_staticTextMonthNationalTrainer;
    wxSpinButton* m_spinButtonMonthNationalTrainer;
    wxStaticText* m_staticTextYearNationalTrainer;
    wxSpinButton* m_spinButtonYearNationalTrainer;
    wxStaticText* m_staticText99;
    wxStaticText* m_staticTextCompetence;
    wxSpinButton* m_spinButtonCompetence;
    wxStaticText* m_staticTextAgeNationalTrainer;
    wxStaticText* m_staticText65;
    wxChoice* m_choiceReputation;
    wxStaticText* m_staticText71;
    wxTextCtrl* m_textNamePresident;
    wxStaticText* m_staticText75;
    wxTextCtrl* m_textFirstnamePresident;
    wxStaticText* m_staticText79;
    wxStaticText* m_staticTextDayPresident;
    wxSpinButton* m_spinButtonDayPresident;
    wxStaticText* m_staticTextMonthPresident;
    wxSpinButton* m_spinButtonMonthPresident;
    wxStaticText* m_staticTextYearPresident;
    wxSpinButton* m_spinButtonYearPresident;
    wxPanel* m_panel97;
    wxStaticText* m_staticTextAgePresident;
    wxStaticText* m_staticText35;
    wxTextCtrl* m_textAssociation;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    void updateBirthdayNationalTrainer();
    void updateBirthdayPresident();

    Toolset* tools = nullptr;
    std::string selectedCountry;
    Core::Trainer nationalTrainer;
    Core::Person president;
    std::shared_ptr<Core::Country> country = nullptr;
};

