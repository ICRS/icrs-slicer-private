#ifndef __scanner_popup_hpp
#define __scanner_popup_hpp

#include "GUI_Utils.hpp"
#include <wx/button.h>
#include "format.hpp"

class ScannerDialog : public DPIDialog
{
    private:
    StateColor btn_bg_green(std::pair<wxColour, int>(wxColour(27, 136, 68), StateColor::Pressed), std::pair<wxColour, int>(wxColour(0, 150, 136), StateColor::Normal));
    StateColor btn_bg_blue(std::pair<wxColour, int>(wxColour(0, 40, 150), StateColor::Pressed), std::pair<wxColour, int>(wxColour(0, 150, 136), StateColor::Normal));

    public:
    ScannerDialog(Plater *plater /*= nullptr*/) : DPIDialog(static_cast<wxWindow *>(wxGetApp().mainframe), wxID_ANY, _L("Scan your card"), wxDefaultPosition, wxDefaultSize, wxCAPTION | wxCLOSE_BOX) 
    {
        // Bind(wxEVT_CLOSE_WINDOW, &ScannerDialog::on_cancel, this);

        // std::string icon_path = (boost::format("%1%/images/BambuStudioTitle.ico") % resources_dir()).str();

        // SetIcon(wxIcon(encode_path(icon_path.c_str()), wxBITMAP_TYPE_ICO));

    
        m_button_confirm = new Button(this, _L("Confirm"));    
        m_button_confirm->SetBackgroundColor(btn_bg_blue);
        m_button_confirm->SetBorderColor(wxColour(0, 150, 136));
        m_button_confirm->SetTextColor(wxColour(255, 255, 255));
        m_button_confirm->SetSize(wxSize(FromDIP(72), FromDIP(24)));
        m_button_confirm->SetMinSize(wxSize(FromDIP(72), FromDIP(24)));
        m_button_confirm->SetCornerRadius(FromDIP(12));

        m_button_confirm->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            this->confirm = true;
            EndModal(wxID_CANCEL);
        });

        SetBackgroundColour(*wxWHITE);
    }

    ~ScannerDialog() {}

    void open_scanner_modal() {
        bool confirm = false;
        this->ShowModal();
    }

    bool get_confirm() {
        return confirm;
    }

    protected:
    void on_dpi_changed(const wxRect &suggested_rect)
    {
        Fit();
        Refresh();
    }
    
    Button * m_button_confirm {nullptr};

    private:
    bool confirm = false;
};

#endif