
// ranPaintDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ranPaint.h"
#include "ranPaintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CranPaintDlg dialog



CranPaintDlg::CranPaintDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANPAINT_DIALOG, pParent)
	
	, m_strTextCtrl(_T(""))
{
	nextFig = 1;
	isPressed = false;
	curColor = RGB(0, 0, 0);  
	penT = 0;
	penS = 1;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CranPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_COMBO4, m_comboBoxCtrl);
	DDX_CBString(pDX, IDC_COMBO4, m_strTextCtrl);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, colorS);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, Pcol);
}

BEGIN_MESSAGE_MAP(CranPaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CranPaintDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CranPaintDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CranPaintDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CranPaintDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CranPaintDlg::OnBnClickedRadio5)

	ON_BN_CLICKED(IDOK, &CranPaintDlg::OnBnClickedOk)
	
	
	ON_CBN_SELCHANGE(IDC_COMBO4, &CranPaintDlg::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CranPaintDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CranPaintDlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDC_BUTTON2, &CranPaintDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CranPaintDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CranPaintDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON3, &CranPaintDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CranPaintDlg message handlers

BOOL CranPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	

	r.left = 10;
	r.top = 10;
	r.right = 1000;
	r.bottom =400;
	m_comboBoxCtrl.AddString(L"thin");
	m_comboBoxCtrl.AddString(L"normal");
	m_comboBoxCtrl.AddString(L"bold");
	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CranPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CranPaintDlg::OnPaint()
{
	CPaintDC dc(this);
	for (int i = 0; i < Figures.GetSize(); ++i)
		if (Figures[i]->toPaint==true)
			Figures[i]->Draw(&dc);

	
	CBrush brush(RGB(0,0,255));
	CPen pen(PS_SOLID, 1, RGB(0, 0,255));
	CBrush* old = dc.SelectObject(&brush);
	dc.SelectObject(old);
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CranPaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CranPaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	isPressed = true;
	
	Figure2D* Fig = 0;
	switch (nextFig) // create the shape the user pressed
	{
		case 1: Fig = new Segment(); break;
		case 2: Fig = new Rectangle1(); break;
		case 3: Fig = new Square(); break;
		case 4: Fig = new Ellipse1(); break;
		case 5: Fig = new Circle(); break;
	}
	
	Fig->toPaint = true;
	if (transper)
	{
		Fig->setBg(RGB(238,238,238));
	}
	else
	{
		Fig->setBg(curColor);
	}
	Fig->setPenT(penT);
	Fig->setPenS(penS);
	Fig->setP(pColor);
	Fig->setStartP(point);
	Fig->setEndP(point);
	Figures.Add(Fig);
	toDo* a = new toDo(Figures, Fig);
	undoes.push(a);
	CDialogEx::OnLButtonDown(nFlags, point);
}
void CranPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isPressed = false;
	CDialogEx::OnLButtonUp(nFlags, point);
	
}
void CranPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CPaintDC dc(this);
	if (isPressed) {
		Figures[Figures.GetSize() - 1]->setEndP(point);
		InvalidateRect(&r);
	}
	
	CDialogEx::OnMouseMove(nFlags, point);
	
}
void CranPaintDlg::OnBnClickedRadio1()
{
	UpdateData(true);
	nextFig = 1;//Segment
}
void CranPaintDlg::OnBnClickedRadio2()
{
	nextFig = 2;//Rectangle
}


void CranPaintDlg::OnBnClickedRadio3()
{
	nextFig = 3;//Square
}


void CranPaintDlg::OnBnClickedRadio4()
{
	nextFig = 4;//Ellipse
}


void CranPaintDlg::OnBnClickedRadio5()
{
	nextFig = 5;//Circle
}



void CranPaintDlg::OnBnClickedOk()
{	
	CFile theFile;
	theFile.Open(_T("C:\\Users\\ran\\Desktop\\myFile.arc"), CFile::modeWrite | CFile::modeCreate); // write to or create a new one
	CArchive archive(&theFile, CArchive::store);
	Figures.Serialize(archive);
	archive.Close();
	theFile.Close();
	InvalidateRect(&r);
}




void CranPaintDlg::OnRButtonDown(UINT nFlags, CPoint point)
{ // Filling a color into a shape
		for (int i = Figures.GetSize() - 1; i >= 0; i--)
		{
			if (Figures[i]->isInside(point))
			{
				Figures[i]->setP(pColor);
				Figures[i]->setBg(curColor);
				Invalidate();
				break;
			}

		}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CranPaintDlg::OnCbnSelchangeCombo4()
{

		// TODO: Add your control notification handler code here
		int choose = m_comboBoxCtrl.GetCurSel();

		switch (choose)
		{
		case 0:
		{
			penS = 3;
			break;
		}
		case 1:
		{
			penS = 2;
			break;
		}
		case 2:
		{
			penS = 1;
		}
		}
	}







void CranPaintDlg::OnBnClickedMfccolorbutton1()
{
	curColor = colorS.GetColor();
}


void CranPaintDlg::OnBnClickedMfccolorbutton2()
{
	pColor = Pcol.GetColor();
}


void CranPaintDlg::OnBnClickedButton2()//undo
{
	bool used = false;
	for (int i = Figures.GetSize() - 1; i >= 0; i--)
	{
		if (!undoes.empty())
		{
			if (Figures[i] == undoes.top()->Fig && !used)
			{
				
				Figures[i]->toPaint = false;
				redoes.emplace((undoes.top()));
				used = true;
				undoes.pop();
				
			}
			
		}

	}
	

	InvalidateRect(&r);
}


void CranPaintDlg::OnBnClickedButton1()//redo
{
	if (!redoes.empty())
	{
		toDo* a = redoes.top();
		for (int i = 0; i <= Figures.GetSize() - 1; i++)
		{
			if (a->Fig == Figures[i])
			{
				Figures[i]->toPaint = true;
				undoes.emplace((redoes.top()));
				redoes.pop();


			}
		}

		
	}
	InvalidateRect(&r);
}


void CranPaintDlg::OnBnClickedCheck1()
{
	if (transper == true)
		transper = false;
	else
		transper = true;
}


void CranPaintDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CFile theFile;
	theFile.Open(_T("C:\\Users\\ran\\Desktop\\myFile.arc"), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);
	Figures.Serialize(archive);
	archive.Close();
	theFile.Close();
	InvalidateRect(&r);
}



