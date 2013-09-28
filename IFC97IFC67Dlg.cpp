// IFC97IFC67Dlg.cpp : implementation file
//

//************************************************************
//     作    者：                                            *
//              长沙优易软件开发有限公司(UESoft Corp.) 邝祝芳*
//     文件名称：                                            * 
//                                                           *
//     完成时间：                                            *
//                2005年5月                                  *
//************************************************************
 
#include "stdafx.h"
#include "IFC97IFC67.h"
#include "IFC97IFC67Dlg.h"
#include "UEwasp.h"
#include "HtmlHelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIFC97IFC67Dlg dialog

CIFC97IFC67Dlg::CIFC97IFC67Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIFC97IFC67Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIFC97IFC67Dlg)
	m_X = 0.0;
	m_V = 0.0;
	m_T = 0.0;
	m_S = 0.0;
	m_P = 0.0;
	m_H = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIFC97IFC67Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIFC97IFC67Dlg)	
	DDX_Control(pDX, IDC_OUT_List, m_ResultList);
	DDX_Control(pDX, IDC_CHX, m_CHX);
	DDX_Control(pDX, IDC_CHV, m_CHV);
	DDX_Control(pDX, IDC_CHT, m_CHT);
	DDX_Control(pDX, IDC_CHS, m_CHS);
	DDX_Control(pDX, IDC_CHP, m_CHP);
	DDX_Control(pDX, IDC_CHH, m_CHH);
	DDX_Control(pDX, IDC_EdX, m_EDX);
	DDX_Control(pDX, IDC_EdV, m_EDV);
	DDX_Control(pDX, IDC_EdT, m_EDT);
	DDX_Control(pDX, IDC_EdS, m_EDS);
	DDX_Control(pDX, IDC_EdP, m_EDP);
	DDX_Control(pDX, IDC_EdH, m_EDH);
	DDX_Text(pDX, IDC_EdX, m_X);
	DDX_Text(pDX, IDC_EdV, m_V);
	DDX_Text(pDX, IDC_EdT, m_T);
	DDX_Text(pDX, IDC_EdS, m_S);
	DDX_Text(pDX, IDC_EdP, m_P);
	DDX_Text(pDX, IDC_EdH, m_H);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIFC97IFC67Dlg, CDialog)
	//{{AFX_MSG_MAP(CIFC97IFC67Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Compute, OnCompute)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_CHP, OnChp)
	ON_BN_CLICKED(IDC_CHH, OnChh)
	ON_BN_CLICKED(IDC_CHS, OnChs)
	ON_BN_CLICKED(IDC_CHT, OnCht)
	ON_BN_CLICKED(IDC_CHV, OnChv)
	ON_BN_CLICKED(IDC_CHX, OnChx)
	ON_BN_CLICKED(IDC_ClearResult, OnClearResult)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_COMMAND(IDR_COPY, OnCopy)
	ON_COMMAND(IDR_CUT, OnCut)
	ON_COMMAND(IDR_PASTE, OnPaste)
	ON_COMMAND(IDR_Compute, OnCompute)
	ON_COMMAND(IDR_EXIT, OnExit)
	ON_BN_CLICKED(IDC_CUT, OnCut)
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_PASTE, OnPaste)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIFC97IFC67Dlg message handlers

BOOL CIFC97IFC67Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_EDX.EnableWindow(FALSE);
	m_EDV.EnableWindow(FALSE);
    m_EDT.EnableWindow(FALSE);
	m_EDS.EnableWindow(FALSE);
	m_EDP.EnableWindow(FALSE);
    m_EDH.EnableWindow(FALSE);
	m_bX=false;
	m_bV=false;
	m_bT=false;
	m_bS=false;
	m_bP=false;
	m_bH=false;
	Index=0;
    stdid=67;

	SWStatus67[1] = "区域为：	区间1; 低于350℃的未饱和水";
    SWStatus67[2] = "区域为：	区间2; 过热蒸汽";
    SWStatus67[3] = "区域为：	区间3; 超 临 界";
    SWStatus67[4] = "区域为：	区间4; 亚临界未饱和水";
    SWStatus67[5] = "区域为：	区间5; 亚临界湿蒸汽";
    SWStatus67[6] = "区域为：	区间6; 低于350℃的湿蒸汽";
    SWStatus67[7] = "区域为：	区间7; 临 界 点";

    SWStatus97[1] = "区域为：	区间1; 低于350℃的未饱和水";
    SWStatus97[2] = "区域为：	区间2; 过热蒸汽";
    SWStatus97[3] = "区域为：	区间3; 临界点附近水和蒸汽";
    SWStatus97[4] = "区域为：	区间4; 湿蒸汽或饱和线";
    SWStatus97[5] = "区域为：	区间5; 高温低压蒸汽";
	
	CheckRadioButton(IDC_RADIO_97,IDC_RADIO_67,IDC_RADIO_97);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIFC97IFC67Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIFC97IFC67Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIFC97IFC67Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}




void CIFC97IFC67Dlg::OnCompute() 
{
	// TODO: Add your control notification handler code here
	UINT  chi=GetCheckedRadioButton(IDC_RADIO_97,IDC_RADIO_67);
	
	if (chi==IDC_RADIO_97)  
		stdid=97;
	else
		stdid=67;
    SETSTD_WASP(stdid);  //设置计算标准 IF97/IFC67
	
	switch (Index) 
	{
	case 1:
		{
	       ComputeP2XYZ(); break;
		}
    case 12:
		{    
	       ComputePT2XYZ(); break;
		}
	case 13:
		{
		   ComputePH2XYZ(); break;
		}
	case 14:
		{ 
		   ComputePS2XYZ(); break;
		}
	case 15:
		{
		  ComputePV2XYZ(); break;
		}
	case 16:
		{
		  ComputePX2XYZ(); break;
		}
	
	case 2:
		{
			ComputeT2XYZ(); break;
		}
    case 23:
		{
			ComputeTH2XYZ(); break;
		}
	case 24:
		{
		    ComputeTS2XYZ(); break;
		}
    case 25:
		{
			ComputeTV2XYZ(); break;
		}
	case 26:
		{
			ComputeTX2XYZ(); break;
		}

	case 34:
		{
			ComputeHS2XYZ();break;
		}
	case 35:
		{
			ComputeHV2XYZ(); break;
		}
    case 36:
		{
			ComputeHX2XYZ(); break;
		}

	case 45:
		{
			ComputeSV2XYZ(); break;
		}
    case 46:
		{
			ComputeSX2XYZ(); break;
		}

	case 56:
		{
			ComputeVX2XYZ(); break;
		}
    default:
		{
		}
	}
	

}

void CIFC97IFC67Dlg::ComputeP2XYZ()
{
    double  P;
	double  *T, t;
	double  *HL,hl,*HG,hg;
	double  *SL,sl,*SG,sg;
	double  *VL,vl,*VG,vg;
    double  *XL,xl,*XG,xg;
	double  *CPL,cpl,*CPG,cpg;
	double  *CVL,cvl,*CVG,cvg;
	double  *EL,el,*EG,eg;
	double  *SSPL,sspl,*SSPG,sspg;
	double  *KSL,ksl,*KSG,ksg;
	double  *ETAL,etal,*ETAG,etag;
    double  *UL,ul,*UG,ug;
	double  *RAMDL,ramdl,*RAMDG,ramdg;
	double  *PRNL,prnl,*PRNG,prng;
	double  *EPSL,epsl,*EPSG,epsg;
	double  *NL,nl,*NG,ng;

	int *Range, range;
	CString   cs0, cs,cs1,cs2,cs3,cs4,cs5,cs6,cs7,cs8,cs9,cs10,cs11,cs12,cs13,cs14,cs15,cs16;
	CString   cs17,cs18,cs19,cs20,cs21,cs22,cs23,cs24,cs25,cs26,cs27,cs28,cs29,cs30,cs31,cs32;
	T=&t;	
	Range=&range;

	m_ResultList.SetWindowText("");   
    cs.Format("\r\n\r\n");

	UpdateData(TRUE);	
	P=m_P;   	
	P2T(P,T,Range);	
	if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
	if (stdid==97) //(*Range==4)
	{
      cs0.Format(SWStatus97[*Range]+"\r\n\r\n");
	}
	else
	{
		if(stdid==67)   //(*Range==5)||(*Range==6)
		{
          cs0.Format(SWStatus67[*Range]+"\r\n\r\n");
		}	
	}

	

    cs1.Format("压力%12sP    =%f  MPa\r\n"," ",P);
	cs2.Format("温度%12sT    =%f ℃\r\n干度      	X    =不确定!\r\n\r\n"," ",*T);
	
    HL=&hl;
	HG=&hg;
    SL=&sl;
	SG=&sg;
	VL=&vl;
	VG=&vg;
	CPL=&cpl;
	CPG=&cpg;
	CVL=&cvl;
	CVG=&cvg;
	EL=&el;
	EG=&eg;
	SSPL=&sspl;
	SSPG=&sspg;
	KSL=&ksl;
	KSG=&ksg;
	ETAL=&etal;
	ETAG=&etag;
	UL=&ul;
	UG=&ug;
	RAMDL=&ramdl;
	RAMDG=&ramdg;
	PRNL=&prnl;
	PRNG=&prng;
	EPSL=&epsl;
	EPSG=&epsg;
	NL=&nl;
	NG=&ng;
    XL=&xl;
	XG=&xg;

	P2L(P,T,HL,SL,VL,XL,Range);
	//P2HL(P,HL,Range); 	
    cs3.Format("饱和水比焓%6sHL   = %f kJ/kg\r\n"," ",*HL);	
	
    //P2SL(P,SL,Range);
    cs4.Format("饱和水比熵%6sSL   = %f (kJ/(kg.℃)\r\n"," ",*SL);	
	
	//P2VL(P,VL,Range);    
    cs5.Format("饱和水比容%6sVL   = %f m^3/kg\r\n\r\n"," ",*VL);
	

    P2CPL(P,CPL,Range);    
    cs6.Format("饱和水定压比热%2sCPL  = %f kJ/(kg.℃)\r\n"," ",*CPL);	

	P2CVL(P,CVL,Range);    
    cs7.Format("饱和水定容比热%2sCVL  = %f kJ/(kg.℃)\r\n"," ",*CVL);	

	P2EL(P,EL,Range);   
    cs8.Format("饱和水内能%6sEL   = %f kJ/kg\r\n"," ",*EL);
	
    P2SSPL(P,SSPL,Range);    
    cs9.Format("饱和水声速%6sSSPL = %f m/s\r\n"," ",*SSPL);	

	P2KSL(P,KSL,Range);   
    cs10.Format("饱和水定熵指数%2sKSL  = %f \r\n"," ",*KSL);

    P2ETAL(P,ETAL,Range);
    cs11.Format("饱和水动力粘度%2sETAL = %e kg/(m.s)\r\n"," ",*ETAL);

    P2UL(P,UL,Range);   
    cs12.Format("饱和水运动粘度%2sUL   = %e kg/(m.s)\r\n"," ",*UL);	

	P2RAMDL(P,RAMDL,Range);    
    cs13.Format("饱和水导热系数%2sRAMDL= %e W/(m.℃)\r\n"," ",*RAMDL);	 

    P2PRNL(P,PRNL,Range);   
    cs14.Format("饱和水普朗特数%2sPRNL = %f \r\n"," ",*PRNL);	 

    P2EPSL(P,EPSL,Range);    
    cs15.Format("饱和水介电常数%2sEPSL = %f \r\n"," ",*EPSL);	

	P2NL(P,2.265E-7,NL,Range);
    cs16.Format("当给定波长为: %2s %f μm时\r\n"," ",0.2265);
	cs17.Format("饱和水折射率%4sNL   = %f \r\n\r\n"," ",*NL);
	   
 
	P2G(P,T,HG,SG,VG,XG,Range);
  	//P2HG(P,HG,Range);	
    cs18.Format("饱和汽比焓%6sHG   = %f kJ/kg\r\n"," ",*HG);	
 
	//P2SG(P,SG,Range);
    cs19.Format("饱和汽比熵%6sSG   = %f kJ/(kg.℃)\r\n"," ",*SG);	
	
	//P2VG(P,VG,Range);   
    cs20.Format("饱和汽比容%6sVG   = %f m^3/kg\r\n\r\n"," ",*VG);	

    P2CPG(P,CPG,Range);    
    cs21.Format("饱和汽定压比热%2sCPG  = %f kJ/(kg.℃)\r\n"," ",*CPG);

	P2CVG(P,CVG,Range);    
    cs22.Format("饱和汽定容比热%2sCVG  = %f  kJ/(kg.℃)\r\n"," ",*CVG);
	
	P2EG(P,EG,Range);   
    cs23.Format("饱和汽内能%6sEG   = %f kJ/kg\r\n"," ",*EG);

    P2SSPG(P,SSPG,Range);    
    cs24.Format("饱和汽声速%6sSSPG = %f m/s\r\n"," ",*SSPG);	

	P2KSG(P,KSG,Range);   
    cs25.Format("饱和汽定熵指数%2sKSG  = %f \r\n"," ",*KSG);
	
    P2ETAG(P,ETAG,Range);   
    cs26.Format("饱和汽动力粘度%2sETAG = %e kg/(m.s)\r\n"," ",*ETAG);

    P2UG(P,UG,Range);    
    cs27.Format("饱和汽运动粘度%2sUG   = %e kg/(m.s)\r\n"," ",*UG);

	P2RAMDG(P,RAMDG,Range);
    cs28.Format("饱和汽导热系数%2sRAMDG= %e W/(m.℃)\r\n"," ",*RAMDG);
	
    P2PRNG(P,PRNG,Range);  
    cs29.Format("饱和汽普朗特数%2sPRNG = %f \r\n"," ",*PRNG);
	
    P2EPSG(P,EPSG,Range);    
    cs30.Format("饱和汽介电常数%2sEPSG = %f \r\n"," ",*EPSG);
	
	P2NG(P,2.265E-7,NG,Range);
	cs31.Format("当给定波长为: %2s %f μm时,\r\n"," ",0.2265);
	cs32.Format("饱和汽折射率  %2sNG   = %f \r\n"," ",*NG);

	cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6+cs7+cs8+cs9+cs10+cs11+cs12+cs13+cs14+cs15+cs16;
	cs=cs+cs17+cs18+cs19+cs20+cs21+cs22+cs23+cs24+cs25+cs26+cs27+cs28+cs29+cs30+cs31+cs32;
	m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputePT2XYZ()
{
   double  P,T;
   double  *H,h;
   double  *S,s;
   double  *V,v;
   double  *CV,cv;
   double  *CP,cp;
   double  *E,e;
   double  *SSP,ssp;
   double  *KS,ks;
   double  *ETA,eta;
   double  *U,u;
   double  *RAMD,ramd;
   double  *PRN,prn;
   double  *EPS,eps;
   double  *N,n;
   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6,cs7,cs8,cs9,cs10,cs11,cs12,cs13,cs14,cs15,cs16,cs17;
   int *Range, range;

   Range=&range;
   H=&h;
   S=&s;
   V=&v;
   CV=&cv;
   CP=&cp;
   E=&e;
   SSP=&ssp;
   KS=&ks;
   ETA=&eta;
   U=&u;
   RAMD=&ramd;
   PRN=&prn;
   EPS=&eps;
   N=&n;
 
   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   
   UpdateData(TRUE);	
   P=m_P;
   T=m_T;   
   cs1.Format("压力%12sP    = %f MPa\r\n"," ",P);   
   cs2.Format("温度%12sT    = %f ℃\r\n"," ",T);   

   PT2H(P,T,H,Range); 
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs3.Format("比焓%12sH    = %f kJ/kg\r\n"," ",*H);
   
   PT2S(P,T,S,Range);   
   cs4.Format("比熵%12sS    = %f kJ/(kg.℃)\r\n"," ",*S);
   
   PT2V(P,T,V,Range); 
   cs5.Format("比容%12sV    = %f m^3/kg\r\n\r\n"," ",*V);
   
   PT2CP(P,T,CP,Range);   
   cs6.Format("定压比热%8sCP   = %f kJ/(kg.℃)\r\n"," ",*CP);
   
   PT2CV(P,T,CV,Range);   
   cs7.Format("定容比热%8sCV   = %f kJ/(kg.℃)\r\n"," ",*CV);
  
   PT2E(P,T,E,Range);
   cs8.Format("内能%12sE    = %f kJ/kg\r\n"," ",*E);
   
   PT2SSP(P,T,SSP,Range);  
   cs9.Format("声速%12sSSP  = %f m/s\r\n"," ",*SSP);
   
   PT2KS(P,T,KS,Range);  
   cs10.Format("定熵指数%8sKS   = %f \r\n"," ",*KS);   

   PT2ETA(P,T,ETA,Range);  
   cs11.Format("动力粘度%8sETA  = %e kg/(m.s)\r\n"," ",*ETA);   
 
   PT2U(P,T,U,Range);  
   cs12.Format("运动粘度%8sU    = %e (m^2/s)\r\n"," ",*U);
   
   PT2RAMD(P,T,RAMD,Range);   
   cs13.Format("导热系数%8sRAMD = %e W/(m.℃)\r\n"," ",*RAMD);
   
   PT2PRN(P,T,PRN,Range);  
   cs14.Format("普朗特数%8sPRN  = %f \r\n"," ",*PRN);
   
   PT2EPS(P,T,EPS,Range);  
   cs15.Format("介电常数%8sEPS  = %f \r\n"," ",*EPS);
    
   
   PT2N(P,T,2.265E-7,N,Range);
   cs16.Format("当给定波长为: %2s %f μm时\r\n"," ",0.2265);
   cs17.Format("折射率 %8sN    = %f \r\n"," ",*N);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6+cs7+cs8+cs9+cs10+cs11+cs12+cs13+cs14+cs15+cs16+cs17;
   m_ResultList.SetWindowText(cs);

}

void CIFC97IFC67Dlg::ComputePH2XYZ()
{
   double P,H;
   double *T,t;
   double *S,s;
   double *V,v;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5;
   T=&t;
   S=&s;
   V=&v;
   X=&x;
   Range=&range;
 
   
   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   
   UpdateData(TRUE);	
   P=m_P;
   H=m_H;

   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",P);
     
   PH2T(P,H,T,Range);
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);  

   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",H);
   
   
   PH2S(P,H,S,Range);  
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);
   
   PH2V(P,H,V,Range);   
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5;
   m_ResultList.SetWindowText(cs);



}

void CIFC97IFC67Dlg::ComputePS2XYZ()
{
   double P,S;
   double *T,t;
   double *H,h;
   double *V,v;
   double *X,x;
   int   *Range,range;

   CString cs0, cs,cs1,cs2,cs3,cs4,cs5;
   T=&t;
   H=&h;
   V=&v;
   X=&x;
   Range=&range;

   
   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   
   UpdateData(TRUE);	
   P=m_P;
   S=m_S;

   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",P);
      
   PS2T(P,S,T,Range);

   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);    

   PS2H(P,S,H,Range);  
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);
         
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",S);
   
   PS2V(P,S,V,Range);  
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputePV2XYZ()
{
   double P,V;
   double *T,t;
   double *H,h;
   double *S,s;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5;
   T=&t;
   H=&h;
   S=&s;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   
   UpdateData(TRUE);	
   P=m_P;
   V=m_V;

   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",P);
      
   PV2T(P,V,T,Range); 

   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);
   
   PV2H(P,V,H,Range);   
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);
   
    
   PV2S(P,V,S,Range);   
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);  
  
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",V);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputePX2XYZ()
{
   double P,X;
   double *T,t;
   double *H,h;
   double *S,s;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   T=&t;
   H=&h;
   S=&s;
   V=&v;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   

   UpdateData(TRUE);	
   P=m_P;
   X=m_X;

   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",P);
      
   PX2T(P,X,T,Range); 
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);
   
   PX2H(P,X,H,Range);  
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);
      
   PX2S(P,X,S,Range);   
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S); 

   PX2V(P,X,V,Range); 
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);
   
   cs6.Format("干度 %12sX    = %f \r\n"," ",X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeT2XYZ()
{
    double  T;
	double  *P,p;
	double  *HL,hl,*HG,hg;
	double  *SL,sl,*SG,sg;
	double  *VL,vl,*VG,vg;
	double  *XL,xl,*XG,xg;
	double  *CPL,cpl,*CPG,cpg;
	double  *CVL,cvl,*CVG,cvg;
	double  *EL,el,*EG,eg;
	double  *SSPL,sspl,*SSPG,sspg;
	double  *KSL,ksl,*KSG,ksg;
	double  *ETAL,etal,*ETAG,etag;
    double  *UL,ul,*UG,ug;
	double  *RAMDL,ramdl,*RAMDG,ramdg;
	double  *PRNL,prnl,*PRNG,prng;
	double  *EPSL,epsl,*EPSG,epsg;
	double  *NL,nl,*NG,ng;
    double  *SURFT,surft;

	int *Range, range;
	CString   cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6,cs7,cs8,cs9,cs10,cs11,cs12,cs13,cs14,cs15,cs16;
	CString   cs17,cs18,cs19,cs20,cs21,cs22,cs23,cs24,cs25,cs26,cs27,cs28,cs29,cs30,cs31,cs32,cs33;
	P=&p;	
	Range=&range;

	
    m_ResultList.SetWindowText("");   
    cs.Format("\r\n\r\n");
	UpdateData(TRUE);	
	T=m_T;    
	
	T2P(T,P,Range);	

	if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
	if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
	cs1.Format("温度%12sT    = %f  ℃\r\n"," ",T);
    cs2.Format("压力%12sP    = %f MPa\r\n干度      	X    =不确定!\r\n\r\n"," ",*P);	
	
    HL=&hl;
	HG=&hg;
    SL=&sl;
	SG=&sg;
	VL=&vl;
	VG=&vg;
	CPL=&cpl;
	CPG=&cpg;
	CVL=&cvl;
	CVG=&cvg;
	EL=&el;
	EG=&eg;
	SSPL=&sspl;
	SSPG=&sspg;
	KSL=&ksl;
	KSG=&ksg;
	ETAL=&etal;
	ETAG=&etag;
	UL=&ul;
	UG=&ug;
	RAMDL=&ramdl;
	RAMDG=&ramdg;
	PRNL=&prnl;
	PRNG=&prng;
	EPSL=&epsl;
	EPSG=&epsg;
	NL=&nl;
	NG=&ng;
    SURFT=&surft;
	XL=&xl;
	XG=&xg;

	T2L(P,T,HL,SL,VL,XL,Range);
	//T2HL(T,HL,Range);	
    cs3.Format("饱和水比焓%6sHL   = %f kJ/kg\r\n"," ",*HL);	
	
    //T2SL(T,SL,Range);	
    cs4.Format("饱和水比熵%6sSL   = %f kJ/(kg.℃)\r\n"," ",*SL);
	
	//T2VL(T,VL,Range);    
    cs5.Format("饱和水比容%6sVL   = %f m^3/kg\r\n\r\n"," ",*VL);
	
  	T2CPL(T,CPL,Range);    
    cs6.Format("饱和水定压比热%2sCPL  = %f kJ/(kg.℃)\r\n"," ",*CPL);
	
	T2CVL(T,CVL,Range);    
    cs7.Format("饱和水定容比热%2sCVL  = %f kJ/(kg.℃)\r\n"," ",*CVL);

	T2EL(T,EL,Range);   
    cs8.Format("饱和水内能%6sEL   = %f kJ/kg\r\n"," ",*EL);
	
    T2SSPL(T,SSPL,Range);   
    cs9.Format("饱和水声速%6sSSPL = %f m/s\r\n"," ",*SSPL);

	T2KSL(T,KSL,Range);   
    cs10.Format("饱和水定熵指数%2sKSL  = %f \r\n"," ",*KSL);

    T2ETAL(T,ETAL,Range);    
    cs11.Format("饱和水动力粘度%2sETAL = %e kg/(m.s)\r\n"," ",*ETAL);
	
    T2UL(T,UL,Range);  
    cs12.Format("饱和水运动粘度%2sUL   = %e kg/(m.s)\r\n"," ",*UL);

	T2RAMDL(T,RAMDL,Range);    
    cs13.Format("饱和水导热系数%2sRAMDL= %e W/(m.℃)\r\n"," ",*RAMDL);
	
    T2PRNL(T,PRNL,Range);    
    cs14.Format("饱和水普朗特数%2sPRNL = %f \r\n"," ",*PRNL);
	
    T2EPSL(T,EPSL,Range);  
    cs15.Format("饱和水介电常数%2sEPSL = %f \r\n"," ",*EPSL); 

	T2NL(T,2.265E-7,NL,Range);
    cs16.Format("当给定波长为: %2s %f μm时,\r\n"," ",0.2265);
	
    cs17.Format("饱和水折射率%4sNL   = %f \r\n"," ",*NL);

    T2SURFT(T,SURFT,Range);   
    cs18.Format("饱和水表面张力%2sSURFT= %f \r\n\r\n"," ",*SURFT);
 

	T2G(P,T,HG,SG,VG,XG,Range);
	//T2HG(T,HG,Range);
    cs19.Format("饱和汽比焓%6sHG   = %f kJ/kg\r\n"," ",*HG);	 
	//T2SG(T,SG,Range);
    cs20.Format("饱和汽比熵%6sSG   = %f kJ/(kg.℃)\r\n"," ",*SG);		
	//T2VG(T,VG,Range);    
    cs21.Format("饱和汽比容%6sVG   = %f m^3/kg\r\n\r\n"," ",*VG);
	
   	T2CPG(T,CPG,Range);   
    cs22.Format("饱和汽定压比热%2sCPG  = %f kJ/(kg.℃)\r\n"," ",*CPG);
	
	T2CVG(T,CVG,Range);   
    cs23.Format("饱和汽定容比热%2sCVG  = %f kJ/(kg.℃)\r\n"," ",*CVG);
	
	T2EG(T,EG,Range);   
    cs24.Format("饱和汽内能%6sEG   = %f kJ/kg\r\n"," ",*EG);
	
    T2SSPG(T,SSPG,Range);    
    cs25.Format("饱和汽声速%6sSSPG = %f m/s\r\n"," ",*SSPG);


	T2KSG(T,KSG,Range);    
    cs26.Format("饱和汽定熵指数%2sKSG  = %f \r\n"," ",*KSG);

    T2ETAG(T,ETAG,Range);    
    cs27.Format("饱和汽动力粘度%2sETAG = %e kg/(m.s)\r\n"," ",*ETAG);

    T2UG(T,UG,Range);    
    cs28.Format("饱和汽运动粘度%2sUG   = %e kg/(m.s)\r\n"," ",*UG);


	T2RAMDG(T,RAMDG,Range);    
    cs29.Format("饱和汽导热系数%2sRAMDG= %e W/(m.℃)\r\n"," ",*RAMDG);
	 
    T2PRNG(T,PRNG,Range);   
    cs30.Format("饱和汽普朗特数%2sPRNG = %f \r\n"," ",*PRNG);	

    T2EPSG(T,EPSG,Range);  
    cs31.Format("饱和汽介电常数%2sEPSG = %f \r\n"," ",*EPSG);	

	T2NG(T,2.265E-7,NG,Range);
    cs32.Format("当给定波长为: %2s %f μm时,\r\n"," ",0.2265);
    
	cs33.Format("饱和汽折射率  %2sNG   = %f \r\n"," ",*NG);	
	
	cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6+cs7+cs8+cs9+cs10+cs11+cs12+cs13+cs14+cs15+cs16+cs17+cs18;
	cs=cs+cs19+cs20+cs21+cs22+cs23+cs24+cs25+cs26+cs27+cs28+cs29+cs30+cs31+cs32+cs33;
	m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeTH2XYZ()
{
   double T,H;
   double *P,p;
   double *V,v;
   double *S,s;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   V=&v;
   S=&s;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   
   UpdateData(TRUE);	
   T=m_T;
   H=m_H;

   TH2P(T,H,P,Range);  
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);
     
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",T);
   
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",H);   
    
   TH2S(T,H,S,Range); 
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);  

   TH2V(T,H,V,Range);   
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);
   
   TH2X(T,H,X,Range);   
   cs6.Format("干度 %12sX    = %f \r\n"," ",*X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeTS2XYZ()
{
   double T,S;
   double *P,p;
   double *V,v;
   double *H,h;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   V=&v;
   H=&h;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");
   

   UpdateData(TRUE);	
   T=m_T;
   S=m_S;

   TS2P(T,S,P,Range);
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);      
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",T);    

   TS2H(T,S,H,Range);  
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);       
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",S);
   
   TS2V(T,S,V,Range);   
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);   

   TS2X(T,S,X,Range); 
   cs6.Format("干度 %12sX    = %f \r\n"," ",*X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeTV2XYZ()
{
   double T,V;
   double *P,p;
   double *S,s;
   double *H,h;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   S=&s;
   H=&h;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");   

   UpdateData(TRUE);	
   T=m_T;
   V=m_V;

   TV2P(T,V,P,Range);  

   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);    
  
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",T);    

   TV2H(T,V,H,Range);  
   cs3.Format("比焓 %12sH    = %f  kJ/kg\r\n"," ",*H);
     
   TV2S(T,V,S,Range);   
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);
      
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",V);
  
   TV2X(T,V,X,Range);   
   cs6.Format("干度 %12sX    = %f \r\n"," ",*X);
 
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeTX2XYZ()
{
   double T,X;
   double *P,p;
   double *S,s;
   double *H,h;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   S=&s;
   H=&h;
   V=&v;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");   

   UpdateData(TRUE);	
   T=m_T;
   X=m_X;

   TX2P(T,X,P,Range);  
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);
      
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",T);   

   TX2H(T,X,H,Range);  
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);
       
   TX2S(T,X,S,Range);   
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);
   
   TX2V(T,X,V,Range);   
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);
   
   cs6.Format("干度 %12sX    = %f \r\n"," ",X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeHS2XYZ()
{
   double H,S;
   double *P,p;
   double *T,t;
   double *X,x;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   X=&x;
   V=&v;
   Range=&range;

   
   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");

   UpdateData(TRUE);	
   H=m_H;
   S=m_S;

   HS2P(H,S,P,Range);    

   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f  MPa\r\n"," ",*P);
    
   HS2T(H,S,T,Range);   
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);    

   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",H);      
 
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",S);
   
   HS2V(H,S,V,Range);  
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);

   HS2X(H,S,X,Range);   
   cs6.Format("干度 %12sX    = %f \r\n"," ",*X);   

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);

}

void CIFC97IFC67Dlg::ComputeHV2XYZ()
{
   double H,V;
   double *P,p;
   double *T,t;
   double *X,x;
   double *S,s;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   X=&x;
   S=&s;
   Range=&range;

   
   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");   

   UpdateData(TRUE);	
   H=m_H;
   V=m_V;

   HV2P(H,V,P,Range);  
  
   if (*Range==0)
   {
		MessageBox("参数越界!");
		return;
	}
    if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);
   
   
   HV2T(H,V,T,Range);
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);
   
   cs3.Format("比焓 %12sH    = %f kJ/kg"," ",H);   
    
   HV2S(H,V,S,Range);
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);  

   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",V);   

   HV2X(H,V,X,Range);
   cs6.Format("干度 %12sX    = %f \r\n"," ",*X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeHX2XYZ()
{
   double H,X;
   double *P,p;
   double *T,t;
   double *V,v;
   double *S,s;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   V=&v;
   S=&s;
   Range=&range;

   m_ResultList.SetWindowText("");  
   cs.Format("\r\n\r\n");
   
   UpdateData(TRUE);	
   H=m_H;
   X=m_X;

   HX2P(H,X,P,Range);  
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);   
   
   HX2T(H,X,T,Range);  
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T); 

   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",H); 
    
   HX2S(H,X,S,Range);
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S);   

   HX2V(H,X,V,Range);  
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V);
   
   cs6.Format("干度 %12sX    = %f \r\n"," ",X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeSV2XYZ()
{
   double S,V;
   double *P,p;
   double *T,t;
   double *H,h;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   H=&h;
   X=&x;
   Range=&range;
   
   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");   

   UpdateData(TRUE);	
   S=m_S;
   V=m_V;

   SV2P(S,V,P,Range); 
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);  
   
   SV2T(S,V,T,Range);  
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);  

   SV2H(S,V,H,Range); 
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);  
    
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",S); 

   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",V);
 
   SV2X(S,V,X,Range);   
   cs6.Format("干度 %12sX    = %f \r\n"," ",*X);

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
  
}

void CIFC97IFC67Dlg::ComputeSX2XYZ()
{
   double S,X;
   double *P,p;
   double *T,t;
   double *H,h;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   H=&h;
   V=&v;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");   

   UpdateData(TRUE);	
   S=m_S;
   X=m_X;

   SX2P(S,X,P,Range); 
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f  MPa\r\n"," ",*P);
      
   SX2T(S,X,T,Range);
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);
   
   SX2H(S,X,H,Range); 
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);  
    
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",S);
  
   SX2V(S,X,V,Range);   
   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",*V); 
  
   cs6.Format("干度 %12sX    = %f \r\n"," ",X);   

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CIFC97IFC67Dlg::ComputeVX2XYZ()
{
   double V,X;
   double *P,p;
   double *T,t;
   double *H,h;
   double *S,s;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   H=&h;
   S=&s;
   Range=&range;

   m_ResultList.SetWindowText("");   
   cs.Format("\r\n\r\n");   

   UpdateData(TRUE);	
   V=m_V;
   X=m_X;

   VX2P(V,X,P,Range); 
   
   if (*Range==0)
	{
		MessageBox("参数越界!");
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+"\r\n");
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+"\r\n");
   }
   cs1.Format("压力 %12sP    = %f MPa\r\n"," ",*P);
     
   VX2T(V,X,T,Range);  
   cs2.Format("温度 %12sT    = %f ℃\r\n"," ",*T);   

   VX2H(V,X,H,Range);  
   cs3.Format("比焓 %12sH    = %f kJ/kg\r\n"," ",*H);   
   
   VX2S(V,X,S,Range);   
   cs4.Format("比熵 %12sS    = %f kJ/(kg.℃)\r\n"," ",*S); 

   cs5.Format("比容 %12sV    = %f m^3/kg\r\n"," ",V);   

   cs6.Format("干度 %12sX    = %f \r\n"," ",X);   

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);

}

int CIFC97IFC67Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CIFC97IFC67Dlg::OnChp() 
{
	// TODO: Add your control notification handler code here
	
	if (m_bP==FALSE)
    {	
		m_EDP.EnableWindow(TRUE); 
		m_bP=true;
		if (Index==0)
		{
			Index=1; //P
		}
		if (Index==2)
		{
			Index=12; //PT
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 

		}
		if (Index==3)
		{
			Index=13; //PH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 
		}
		if (Index==4)
		{
			Index=14; //PS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDH.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHH.EnableWindow(FALSE); 
		}
		if (Index==5)
		{
			Index=15; //PV
			m_EDX.EnableWindow(FALSE);
	        m_EDH.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHH.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 
		}
		if (Index==6)
		{
			Index=16;//PX
			m_EDH.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHH.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 
		}
	}
	else
	{
		m_EDP.EnableWindow(FALSE);
		m_bP=false;
		if (Index==1)
		{
			Index=0;
		}
		if (Index==12)
		{
            Index=2;     //PT

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHH.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==13)
		{
            Index=3;  //PH
			
			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==14)
		{
            Index=4;  //PS
			   

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHH.EnableWindow(true); 
		}
		if (Index==15)
		{
			Index=5;  //PV
			 

			m_CHX.EnableWindow(true);
	        m_CHH.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==16)
		{
			Index=6;  //PX	 		  

			m_CHH.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
	}
}

void CIFC97IFC67Dlg::OnChh() 
{
	// TODO: Add your control notification handler code here
	if (m_bH==FALSE)
    {	
		m_EDH.EnableWindow(TRUE); 
		m_bH=true;
		if (Index==0)
		{
			Index=3;   //H
		}
		if (Index==1)
		{
			Index=13; //PH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 

		}
		if (Index==2)
		{
			Index=23;  //TH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE); 
		}
		if (Index==4)
		{
           Index=34;  //HS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
		}
		if (Index==5)
		{
            Index=35;  //HV
			m_EDX.EnableWindow(FALSE);
	        m_EDT.EnableWindow(FALSE);
            m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHT.EnableWindow(FALSE);
            m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
		}
		if (Index==6)
		{ 
			Index=36;  //HX
			m_EDT.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHT.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDH.EnableWindow(FALSE);
		m_bH=false;
		if (Index==3)
		{
			Index=0; //H
		}		
		if (Index==13)
		{
			Index=1;  //PH
			//m_EDH.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==23)
		{
			Index=2;  //TH
			//m_EDH.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
		if (Index==34)
		{
            Index=4;  //HS
			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
		if (Index==35)
		{
            Index=5;  //HV
			m_CHX.EnableWindow(true);
	        m_CHT.EnableWindow(true);
            m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
		if (Index==36)
		{
			Index=6;  //HX
			m_CHT.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
	}
}

void CIFC97IFC67Dlg::OnChs() 
{
	// TODO: Add your control notification handler code here
	if (m_bS==FALSE)
    {	
		m_EDS.EnableWindow(TRUE); 
		m_bS=true;
		if (Index==0)
		{
			Index=4;  //S
		}
		
		if (Index==1)
		{
			Index=14;  //PS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);   
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);   
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==2)
		{
			Index=24;  //TS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
         	m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
         	m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
			Index=34; //HS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);	
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);	
	        m_CHP.EnableWindow(FALSE);
		}
		if (Index==5)
		{
            Index=45; //SV
			m_EDX.EnableWindow(FALSE);
	        m_EDH.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);	
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHH.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);	
	        m_CHP.EnableWindow(FALSE);
		}	    
	    if (Index==6)
		{
			Index=46; //SX
			m_EDH.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);	
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHH.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);	
	        m_CHP.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDS.EnableWindow(FALSE);
		m_bS=false;
		if (Index==4)
		{
			Index=0; //S
		}
		
		if (Index==14)
		{
			Index=1; //PS
            //m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);   
            m_CHH.EnableWindow(true);
		}
		if (Index==24)
		{
			Index=2; //TS
			//m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
         	m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==34)
		{
			Index=3; //HS
			//m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);	
	        m_CHP.EnableWindow(true);
		}
		if (Index==45)
		{
           Index=5; //SV
			//m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHH.EnableWindow(true);
            m_CHT.EnableWindow(true);	
	        m_CHP.EnableWindow(true);
		}
		if (Index==46)
		{
			Index=6; //SX
			//m_EDS.EnableWindow(true);

			m_CHH.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);	
	        m_CHP.EnableWindow(true);
		}
	}
}

void CIFC97IFC67Dlg::OnCht() 
{
	// TODO: Add your control notification handler code here
	if (m_bT==FALSE)
    {	
		m_EDT.EnableWindow(TRUE); 
		m_bT=true;
		if (Index==0)
		{
			Index=2; //T
		}
		if (Index==1)
		{
			Index=12; //PT
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
            Index=23; //TH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDP.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHP.EnableWindow(FALSE);  
		}
		if (Index==4)
		{
            Index=24; //TS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDP.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHP.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==5)
		{
            Index=25; //TV
			m_EDX.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==6)
		{
			Index=26; //TX
			m_EDP.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHP.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDT.EnableWindow(FALSE);
		m_bT=false;
		if (Index==2)
		{
			Index=0; //T
		}
		
		if (Index==12)
		{
			Index=1; //PT
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}		
        if (Index==23)
		{
			Index=3; //TH
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHP.EnableWindow(true);
		}
		if (Index==24)
		{
			Index=4; //TS
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHP.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}	
		if (Index==25)
		{
			Index=5; //TV
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHP.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}
		if (Index==26)
		{
			Index=6; //TX
			//m_EDT.EnableWindow(true);

			m_CHP.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}		
	}
}

void CIFC97IFC67Dlg::OnChv() 
{
	// TODO: Add your control notification handler code here
	if (m_bV==FALSE)
    {	
		m_EDV.EnableWindow(TRUE); 
		m_bV=true;
		if (Index==0)
		{
			Index=5; 
		}
		if (Index==1)
		{
			Index=15; //PV
            m_EDX.EnableWindow(FALSE);	
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);	
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==2)
		{
			Index=25;  //TV
			m_EDX.EnableWindow(FALSE);	
	        m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);	
	        m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
			Index=35;  //HV
			m_EDX.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
    
		}
		if (Index==4)
		{
			Index=45;  //SV
			m_EDX.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==6)
		{
			Index=56;  //VX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDV.EnableWindow(FALSE);
		m_bV=false;
		if (Index==5)
		{
			Index=0; //V
		}
		if (Index==15)
		{
			Index=1; //PV
            //m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);	
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}
		if (Index==25)
		{
			Index=2; //TV
			//m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);	
	        m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==35)
		{
			Index=3; //HV
			//m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true);
		}
		if (Index==45)
		{
			Index=4; //SV
			//m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}	
		if (Index==56)
		{
			Index=6; //VX
			//m_EDV.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}	
	}
}

void CIFC97IFC67Dlg::OnChx() 
{
	// TODO: Add your control notification handler code here
	if (m_bX==FALSE)
    {	
		m_EDX.EnableWindow(TRUE); 
		m_bX=true;
		if (Index==0)
		{
			Index=6; //X
		}
		if (Index==1)
		{
			Index=16; //PX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDV.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHV.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==2)  
		{
			Index=26;  //TX
			m_EDV.EnableWindow(FALSE);	        
            m_EDS.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHV.EnableWindow(FALSE);	        
            m_CHS.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
			Index=36;  //HX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDV.EnableWindow(FALSE);

			m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHV.EnableWindow(FALSE);
		}
		if (Index==4)
		{
			Index=46;  //SX
			m_EDV.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHV.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==5)
		{
			Index=56;  //VX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

            m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDX.EnableWindow(FALSE);
		m_bX=false;
		if (Index==6)
		{
			Index=0; //P
		}
		if (Index==16)
		{
			Index=1;  //PX
			//m_EDX.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHV.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==26)
		{
			Index=2;  //TX
			//m_EDX.EnableWindow(true);

			m_CHV.EnableWindow(true);	        
            m_CHS.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==36)
		{
			Index=3;   //HX
			//m_EDX.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHV.EnableWindow(true);
		}
		if (Index==46)
		{
			Index=4;  //SX
			//m_EDX.EnableWindow(true);

			m_CHV.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==56)
		{
			Index=5;  //VX
			//m_EDX.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
	}
}

void CIFC97IFC67Dlg::OnClearResult() 
{
	// TODO: Add your control notification handler code here
	m_ResultList.SetWindowText("");
}

void CIFC97IFC67Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	exit(1);
}



void CIFC97IFC67Dlg::OnCopy() 
{
	// TODO: Add your command handler code here
	
}

void CIFC97IFC67Dlg::OnCut() 
{
	// TODO: Add your command handler code here
	if (!OpenClipboard())
	{
	}
}

void CIFC97IFC67Dlg::OnPaste() 
{
	// TODO: Add your command handler code here
	
}

void CIFC97IFC67Dlg::OnHelp() 
{
	HtmlHelp(NULL,AfxGetApp()->m_pszHelpFilePath,HH_DISPLAY_TOC,NULL);	
}

void CIFC97IFC67Dlg::OnButtonHelp() 
{
	// TODO: Add your control notification handler code here
	OnHelp();
}
