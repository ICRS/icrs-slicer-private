#ifndef __scanner_popup_hpp
#define __scanner_popup_hpp

#include "GUI_Utils.hpp"

class ScannerDialog : public DPIDialog
{
    public:
    ScannerDialog(Plater *plater /*= nullptr*/) : DPIDialog(static_cast<wxWindow *>(wxGetApp().mainframe), wxID_ANY, _L("Modifying the device name"), wxDefaultPosition, wxDefaultSize, wxCAPTION | wxCLOSE_BOX) 
    {
        // Bind(wxEVT_CLOSE_WINDOW, &ScannerDialog::on_cancel, this);

        // std::string icon_path = (boost::format("%1%/images/BambuStudioTitle.ico") % resources_dir()).str();

        // SetIcon(wxIcon(encode_path(icon_path.c_str()), wxBITMAP_TYPE_ICO));

        SetBackgroundColour(*wxWHITE);
    }

    ~ScannerDialog() {}

    protected:
    void on_dpi_changed(const wxRect &suggested_rect)
    {
        Fit();
        Refresh();
    }

};

#endif