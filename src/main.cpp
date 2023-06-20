#include <wx/wx.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ResultFrame : public wxFrame
{
    public:
    ResultFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300,200))
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        resultLabel = new wxStaticText(panel, wxID_ANY, "", wxPoint(10, 10), wxSize(280, 30), wxALIGN_CENTER);

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(resultLabel, 0, wxALL | wxALIGN_CENTER, 10);

        panel->SetSizerAndFit(sizer);
    }

    void SetResult(const wxString& hasil_by_Edge, const wxString& hasil_by_Angle, const wxString& pict_Edge, const wxString& pict_Angle)
    {
        wxPNGHandler* handler = new wxPNGHandler;
        wxImage::AddHandler(handler);
        wxStaticBitmap* imageEdge = new wxStaticBitmap(this, wxID_ANY, wxBitmap(pict_Edge, wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);
        wxStaticBitmap* imageAngle = new wxStaticBitmap(this, wxID_ANY, wxBitmap(pict_Angle, wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);
        wxStaticText* resultTriangle_by_Edge = new wxStaticText(this, wxID_ANY, "Berdasarkan panjang sisinya: ");
        wxStaticText* resultTriangle_by_Edge_Text = new wxStaticText(this, wxID_ANY, hasil_by_Edge);
        wxStaticText* resultTriangle_by_Angle = new wxStaticText(this, wxID_ANY, "Berdasarkan sudutnya: ");
        wxStaticText* resultTriangle_by_Angle_Text = new wxStaticText(this, wxID_ANY, hasil_by_Angle);

        wxBoxSizer* boxEdge = new wxBoxSizer(wxVERTICAL);
        boxEdge->Add(resultTriangle_by_Edge, 0, wxALL | wxALIGN_CENTER, 5);
        boxEdge->Add(imageEdge, 0, wxALL | wxALIGN_CENTER, 5);
        boxEdge->Add(resultTriangle_by_Edge_Text, 0, wxALL | wxALIGN_CENTER, 5);

        wxBoxSizer* boxAngle = new wxBoxSizer(wxVERTICAL);
        boxAngle->Add(resultTriangle_by_Angle, 0, wxALL | wxALIGN_CENTER, 5);
        boxAngle->Add(imageAngle, 0, wxALL | wxALIGN_CENTER, 5);
        boxAngle->Add(resultTriangle_by_Angle_Text, 0, wxALL | wxALIGN_CENTER, 5);

        wxBoxSizer* boxResult = new wxBoxSizer(wxHORIZONTAL);
        boxResult->Add(boxEdge, 0, wxALL | wxALIGN_CENTER, 5);
        boxResult->Add(boxAngle, 0, wxALL | wxALIGN_CENTER, 5);

        SetSizerAndFit(boxResult);
    }

    private:
    wxStaticText* resultLabel;
};

class MyPoint : public wxPanel
{
    public:
    MyPoint(wxWindow* parent):wxPanel(parent, wxID_ANY)
    {
        wxButton* button = new wxButton(this, wxID_ANY, "Check Type!");

        wxStaticText* point1 = new wxStaticText(this, wxID_ANY, "Input Position of Point 1 (x1, y1, z1): ");
        wxStaticText* point2 = new wxStaticText(this, wxID_ANY, "Input Position of Point 2 (x2, y2, z2): ");
        wxStaticText* point3 = new wxStaticText(this, wxID_ANY, "Input Position of Point 3 (x3, y3, z3): ");
        wxStaticText* nameProgram = new wxStaticText(this, wxID_ANY, "Check Type of Triangle Program", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxFont nameProgramBold(nameProgram->GetFont());
        nameProgramBold.SetPointSize(20);
        nameProgramBold.SetWeight(wxFONTWEIGHT_BOLD);
        nameProgram->SetFont(nameProgramBold);
        
        inputX1 = new wxTextCtrl(this, wxID_ANY);
        inputY1 = new wxTextCtrl(this, wxID_ANY);
        inputZ1 = new wxTextCtrl(this, wxID_ANY);
        inputX2 = new wxTextCtrl(this, wxID_ANY);
        inputY2 = new wxTextCtrl(this, wxID_ANY);
        inputZ2 = new wxTextCtrl(this, wxID_ANY);
        inputX3 = new wxTextCtrl(this, wxID_ANY);
        inputY3 = new wxTextCtrl(this, wxID_ANY);
        inputZ3 = new wxTextCtrl(this, wxID_ANY);
        button->Bind(wxEVT_BUTTON, &MyPoint::OnProceed, this);

        wxBoxSizer* nameProgramPos = new wxBoxSizer(wxHORIZONTAL);
        nameProgramPos->Add(nameProgram, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* pos1 = new wxBoxSizer(wxHORIZONTAL);
        pos1->Add(point1, wxSizerFlags().Center().Border(wxALL, 5));
        pos1->Add(inputX1, wxSizerFlags().Center().Border(wxALL, 5));
        pos1->Add(inputY1, wxSizerFlags().Center().Border(wxALL, 5));
        pos1->Add(inputZ1, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* pos2 = new wxBoxSizer(wxHORIZONTAL);
        pos2->Add(point2, wxSizerFlags().Center().Border(wxALL, 5));
        pos2->Add(inputX2, wxSizerFlags().Center().Border(wxALL, 5));
        pos2->Add(inputY2, wxSizerFlags().Center().Border(wxALL, 5));
        pos2->Add(inputZ2, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* pos3 = new wxBoxSizer(wxHORIZONTAL);
        pos3->Add(point3, wxSizerFlags().Center().Border(wxALL, 5));
        pos3->Add(inputX3, wxSizerFlags().Center().Border(wxALL, 5));
        pos3->Add(inputY3, wxSizerFlags().Center().Border(wxALL, 5));
        pos3->Add(inputZ3, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* buttonPos = new wxBoxSizer(wxHORIZONTAL);
        buttonPos->Add(button, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->AddStretchSpacer();
        mainSizer->Add(nameProgramPos, wxSizerFlags().Center());
        mainSizer->Add(pos1, wxSizerFlags().Center());
        mainSizer->Add(pos2, wxSizerFlags().Center());
        mainSizer->Add(pos3, wxSizerFlags().Center());
        mainSizer->Add(buttonPos, wxSizerFlags().Center());
        mainSizer->AddStretchSpacer();

        SetSizerAndFit(mainSizer);
    }

    void OnProceed(wxCommandEvent& event)
    {
        if (inputX1->GetValue().IsEmpty() || inputY1->GetValue().IsEmpty() || inputZ1->GetValue().IsEmpty())
        {
            wxMessageBox("Input Position of Point 1 is empty!", "ERROR!", wxICON_ERROR);
            return;
        }

        if (inputX2->GetValue().IsEmpty() || inputY2->GetValue().IsEmpty() || inputZ2->GetValue().IsEmpty())
        {
            wxMessageBox("Input Position of Point 2 is empty!", "ERROR!", wxICON_ERROR);
            return;
        }

        if (inputX3->GetValue().IsEmpty() || inputY3->GetValue().IsEmpty() || inputZ3->GetValue().IsEmpty())
        {
            wxMessageBox("Input Position of Point 3 is empty!", "ERROR!", wxICON_ERROR);
            return;
        }

        wxString inputValueX1 = inputX1->GetValue();
        wxString inputValueY1 = inputY1->GetValue();
        wxString inputValueZ1 = inputZ1->GetValue();

        wxString inputValueX2 = inputX2->GetValue();
        wxString inputValueY2 = inputY2->GetValue();
        wxString inputValueZ2 = inputZ2->GetValue();

        wxString inputValueX3 = inputX3->GetValue();
        wxString inputValueY3 = inputY3->GetValue();
        wxString inputValueZ3 = inputZ3->GetValue();

        double numX[3], numY[3], numZ[3];
        inputValueX1.ToDouble(&numX[0]);
        inputValueY1.ToDouble(&numY[0]);
        inputValueZ1.ToDouble(&numZ[0]);

        inputValueX2.ToDouble(&numX[1]);
        inputValueY2.ToDouble(&numY[1]);
        inputValueZ2.ToDouble(&numZ[1]);

        inputValueX3.ToDouble(&numX[2]);
        inputValueY3.ToDouble(&numY[2]);
        inputValueZ3.ToDouble(&numZ[2]);

        // Length of Each Edge
        double Edge1 = hypot(numX[1] - numX[0] , numY[1] - numY[0], numZ[1] - numZ[0]);
        double Edge2 = hypot(numX[2] - numX[1] , numY[2] - numY[1], numZ[2] - numZ[1]);
        double Edge3 = hypot(numX[2] - numX[0] , numY[2] - numY[0], numZ[2] - numZ[0]);

        // By Edge
        string hasil_by_Edge, pict_Edge;
        if ((Edge1 == Edge2) && (Edge2 == Edge3) && (Edge1 == Edge3))
        {
            hasil_by_Edge = "Segitiga Sama Sisi";
            pict_Edge = "samasisi.png";
        } else if ((Edge1 == Edge2) || (Edge2 == Edge3) || (Edge1 == Edge3))
        {
            hasil_by_Edge = "Segitiga Sama Kaki";
            pict_Edge = "samakaki.png";
        } else if ((Edge1 != Edge2) && (Edge2 != Edge3) || (Edge1 != Edge3))
        {
            hasil_by_Edge = "Segitiga Sembarang";
            pict_Edge = "sembarang.png";
        }

        // By Angle
        string hasil_by_Angle, pict_Angle;
        double cosA = (pow(Edge2, 2.0) + pow(Edge3, 2.0) - pow(Edge1, 2.0)) / (2.0*Edge2*Edge3);
        double cosB = (pow(Edge1, 2.0) + pow(Edge2, 2.0) - pow(Edge3, 2.0)) / (2.0*Edge1*Edge2);
        double cosC = (pow(Edge1, 2.0) + pow(Edge3, 2.0) - pow(Edge2, 2.0)) / (2.0*Edge1*Edge3);


        if ((cosA == 0) || (cosB == 0) || (cosC == 0))
        {
            hasil_by_Angle = "Segitiga Siku-Siku";
            pict_Angle = "siku.png";
        } else if ((cosA > 0) && (cosB > 0) && (cosC > 0))
        {
            hasil_by_Angle = "Segitiga Tumpul";
            pict_Angle = "tumpul.png";
        } else if ((cosA < 0) || (cosB < 0) || (cosC < 0))
        {
            hasil_by_Angle = "Segitiga Lancip";
            pict_Angle = "lancip.png";
        }

        int confirm = wxMessageBox("Do you want to proceed?", "Confirmation", wxICON_WARNING | wxYES_NO);
        if (confirm == wxYES)
        {
            wxString message = wxString::Format("Edge1: %.5f\nEdge2: %.5f\nEdge3: %.5f", Edge1, Edge2, Edge3);
            wxString type = wxString::Format("Edge: %s\nAngle: %s", hasil_by_Edge, hasil_by_Angle);
            wxMessageBox(message, "Edge Values", wxICON_INFORMATION);
            wxMessageBox(type, "Type Triangle", wxICON_INFORMATION);
            ShowResultFrame(hasil_by_Edge, hasil_by_Angle, pict_Edge, pict_Angle);

        } else
        {
            return;
        }
        event.Skip();

        inputX1->Clear();
        inputY1->Clear();
        inputZ1->Clear();
        inputX2->Clear();
        inputY2->Clear();
        inputZ2->Clear();
        inputX3->Clear();
        inputY3->Clear();
        inputZ3->Clear();
    }

    void ShowResultFrame(const wxString& hasil_by_Edge, const wxString& hasil_by_Angle, const wxString& pict_Edge, const wxString& pict_Angle)
    {
        ResultFrame* resultFrame = new ResultFrame("Result");
        resultFrame->SetResult(hasil_by_Edge, hasil_by_Angle, pict_Edge, pict_Angle);
        resultFrame->Centre();
        resultFrame->Show();
        hasil_by_Edge == "";
        hasil_by_Angle == "";
        pict_Edge == "";
        pict_Angle == "";
    };

    private:
    wxTextCtrl* inputX1;
    wxTextCtrl* inputY1;
    wxTextCtrl* inputZ1;
    wxTextCtrl* inputX2;
    wxTextCtrl* inputY2;
    wxTextCtrl* inputZ2;
    wxTextCtrl* inputX3;
    wxTextCtrl* inputY3;
    wxTextCtrl* inputZ3;
};

class MainFrame : public wxFrame
{
    public:
    MainFrame(const wxString& title):wxFrame(nullptr, wxID_ANY, title)
    {
        MyPoint* panel = new MyPoint(this);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(panel, wxSizerFlags(1).Expand());

        SetSizerAndFit(mainSizer);
        Centre();
    }
};

class App : public wxApp
{
    public:
    bool OnInit()
    {
        MainFrame* mainFrame = new MainFrame("GUI Aplikasi Cek Tipe Segitiga");
        // mainFrame->SetClientSize(800, 400);
        mainFrame->Show();

        return true;
    }
};

wxIMPLEMENT_APP(App);