#pragma once

#include <streambuf>
#include <memory>
#include <wx/wx.h>

class CustomOutputStreamBuffer : public std::streambuf
{
public:
    CustomOutputStreamBuffer(wxTextCtrl* textCtrl);

protected:
    virtual int overflow(int c) override;

private:
    wxTextCtrl* textCtrl_;
};
