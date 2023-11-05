#include "CustomOutputStreamBuffer.h"

CustomOutputStreamBuffer::CustomOutputStreamBuffer(wxTextCtrl* textCtrl)
    : textCtrl_(textCtrl)
{
}

int CustomOutputStreamBuffer::overflow(int c)
{
    if (c == '\n')
    {
        textCtrl_->AppendText(wxString("\n"));
    }
    else
    {
        textCtrl_->AppendText(wxString(static_cast<wxChar>(c)));
    }
    return c;
}
