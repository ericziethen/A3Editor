#include "DialogPlayersearch.h"


DialogPlayersearch::DialogPlayersearch(wxWindow* parent, 
    Toolset* const tools, 
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer61 = new wxFlexGridSizer(4, 1, 0, 0);
    flexGridSizer61->SetFlexibleDirection(wxBOTH);
    flexGridSizer61->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer61, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer62 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer62->SetFlexibleDirection(wxBOTH);
    flexGridSizer62->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer62->AddGrowableCol(1);

    flexGridSizer61->Add(flexGridSizer62, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer23 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("selection")), wxVERTICAL);

    flexGridSizer62->Add(staticBoxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioSearchPerson = new wxRadioButton(this, wxID_ANY, tools->translate("searchPerson"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioSearchPerson->SetValue(true);

    staticBoxSizer23->Add(m_radioSearchPerson, 0, wxALL, WXC_FROM_DIP(5));

    m_radioCheckData = new wxRadioButton(this, wxID_ANY, tools->translate("checkData"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioCheckData->SetValue(false);

    staticBoxSizer23->Add(m_radioCheckData, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonStart = new wxButton(this, wxID_ANY, tools->translate("start"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, 30)), 0);

    staticBoxSizer23->Add(m_buttonStart, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("person")), wxVERTICAL);

    flexGridSizer62->Add(staticBoxSizer25, 2, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticFirstname = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer25->Add(m_staticFirstname, 0, wxALL, WXC_FROM_DIP(0));

    m_textFirstname = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstname->SetHint(wxT(""));
#endif

    staticBoxSizer25->Add(m_textFirstname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticLastname = new wxStaticText(this, wxID_ANY, tools->translate("lastname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer25->Add(m_staticLastname, 0, wxALL, WXC_FROM_DIP(0));

    m_textLastname = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textLastname->SetHint(wxT(""));
#endif

    staticBoxSizer25->Add(m_textLastname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("searchedSoFar")), wxVERTICAL);

    flexGridSizer61->Add(staticBoxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_gaugeProgress = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxGA_HORIZONTAL);
    m_gaugeProgress->SetValue(0);

    staticBoxSizer27->Add(m_gaugeProgress, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticProgressText = new wxStaticText(this, wxID_ANY, tools->translate("createList"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer27->Add(m_staticProgressText, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer33 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("entriesFound")), wxVERTICAL);

    flexGridSizer61->Add(staticBoxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listSearchResult = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);

    staticBoxSizer33->Add(m_listSearchResult, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer61->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonCancel = new wxButton(this, wxID_ANY, tools->translate("buttonLeaving"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonCancel, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("DialogPlayersearch"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    }
    else {
        CentreOnScreen(wxBOTH);
    }
/*#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    }
    else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif*/
    // connect events
    // button events
    this->Connect(m_buttonCancel->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnCancel), NULL, this);
    this->Connect(m_buttonStart->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnStart), NULL, this);
}

DialogPlayersearch::~DialogPlayersearch()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonCancel->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnCancel), NULL, this);
    this->Disconnect(m_buttonStart->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnStart), NULL, this);
}

void DialogPlayersearch::OnCancel(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogPlayersearch::OnStart(wxCommandEvent& event)
{
    if (m_radioSearchPerson->GetValue())
    {
        searchPerson();
    }
    else if (m_radioCheckData->GetValue())
    {
        checkData();
    }
}

void DialogPlayersearch::searchPerson()
{
    std::vector<std::wstring> result;
    std::string firstname = std::string(m_textFirstname->GetValue().c_str());
    std::string lastname = std::string(m_textLastname->GetValue().c_str());

    // search for player
    auto playerIds = tools->getPlayerIds();
    for (auto playerId : playerIds)
    {
        auto player = tools->getPlayerById(playerId);
        if (firstname.empty() || player->getFirstname() == firstname)
        {
            if (lastname.empty() || player->getLastname() == lastname)
            {
                if (!(player->getFirstname().empty() && player->getLastname().empty()))
                {
                    result.push_back(tools->translate("player") + L", " + 
                                     tools->positionToString(player->getMainPosition()) + L" " + std::to_wstring(player->getSkill()) + L", " + 
                                     tools->stringTowstring(player->getFirstname()) + L" " + tools->stringTowstring(player->getLastname()));
                }
            }
        }
    }

    // search for trainer

    // search for manager


    if (result.empty())
    {
        wxMessageBox(tools->translate("noPlayerFound"), wxT("EDITOR"), wxYES_NO | wxICON_INFORMATION, this);
    }
    else
    {
        m_listSearchResult->Hide();
        m_listSearchResult->ClearAll();

        m_listSearchResult->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 300);

        long index = 0;
        for (auto item : result)
        {
            long result = m_listSearchResult->InsertItem(index, wxString::Format("Item %d", index));
            m_listSearchResult->SetItem(result, 0,item);
            m_listSearchResult->SetItemData(result, index);

            index++;
        }

        m_listSearchResult->Show();
    }
}

void DialogPlayersearch::checkData()
{
    
}