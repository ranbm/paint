
// ranPaintDlg.h : header file
//
#include <vector>
#include <stack>
#include <afxcolordialog.h>
#include "toDo.h"
#pragma once


// CranPaintDlg dialog
class CranPaintDlg : public CDialogEx
{
// Construction
public:
	CranPaintDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANPAINT_DIALOG };
#endif
	bool isPressed; 
	bool toPaint;
	bool transper;
	CPoint startP; 
	CPoint endP;
	RECT r;
	int nextFig;
	COLORREF curColor;
	COLORREF pColor;
	CTypedPtrArray<CObArray, Figure2D*> Figures;
	stack<toDo*>undoes; 
	stack<toDo*>redoes;
	bool del;
	int counter = 0;
	int penT, penS;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();

	
	afx_msg void OnBnClickedOk();
	
	CComboBox m_comboBoxCtrl;
	CString m_strTextCtrl;

	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedMfccolorbutton1();
	CMFCColorButton colorS;
	afx_msg void OnBnClickedMfccolorbutton2();
	CMFCColorButton Pcol;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedCheck3();
};
