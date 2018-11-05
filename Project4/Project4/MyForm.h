#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "telescope.h"
#include "lens.h"
#include "diffractiongrating.h"
#include "classicastrospectrograph.h"

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  PDiameter;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  PFocalLength;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  CFocalLength;
	private: System::Windows::Forms::TextBox^  CDiameter;
	private: System::Windows::Forms::TextBox^  CThickness;



	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  DiffractionWidth;
	private: System::Windows::Forms::TextBox^  DiffractionHeight;
	private: System::Windows::Forms::HScrollBar^  DiffractionPosition;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::ComboBox^  DiffractionOrder;


	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::HScrollBar^  DiffractionAngle;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  MinWavelength;
	private: System::Windows::Forms::TextBox^  MaxWavelength;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::HScrollBar^  FPosition;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::TextBox^  FFocalLength;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::TextBox^  FDiameter;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::TextBox^  FThickness;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;

	private: System::Windows::Forms::TextBox^  DWidth;



	private: System::Windows::Forms::Label^  label43;

	private: System::Windows::Forms::Label^  ScaleLabel;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::TextBox^  Grooves;

	private: System::Windows::Forms::Label^  label47;

	private: System::Windows::Forms::TextBox^  PixelWidth;

	private: System::Windows::Forms::Label^  label49;

private: System::Windows::Forms::Label^  SlitDistance;
private: System::Windows::Forms::Label^  GratingDistance1;
private: System::Windows::Forms::Label^  GratingDistance;
private: System::Windows::Forms::Label^  FLensDistance1;
private: System::Windows::Forms::Label^  FLensDistance;
private: System::Windows::Forms::Label^  DetectorDistance;
private: System::Windows::Forms::Label^  IncidentAngle1;
private: System::Windows::Forms::Label^  IncidentAngle;
private: System::Windows::Forms::Label^  DiffractedAngle1;
private: System::Windows::Forms::Label^  DiffractedAngle;
private: System::Windows::Forms::Label^  CenWavelength;
private: System::Windows::Forms::Label^  ColWarning;
private: System::Windows::Forms::Label^  DifWarning;
private: System::Windows::Forms::Label^  DetWarning;
private: System::Windows::Forms::Label^  Res;
private: System::Windows::Forms::Label^  ResolutionLabel;
private: System::Windows::Forms::Label^  SpectralRange;

















	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->PDiameter = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->PFocalLength = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->CFocalLength = (gcnew System::Windows::Forms::TextBox());
			this->CDiameter = (gcnew System::Windows::Forms::TextBox());
			this->CThickness = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->DiffractionWidth = (gcnew System::Windows::Forms::TextBox());
			this->DiffractionHeight = (gcnew System::Windows::Forms::TextBox());
			this->DiffractionPosition = (gcnew System::Windows::Forms::HScrollBar());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->DiffractionOrder = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->DiffractionAngle = (gcnew System::Windows::Forms::HScrollBar());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->MinWavelength = (gcnew System::Windows::Forms::TextBox());
			this->MaxWavelength = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->FPosition = (gcnew System::Windows::Forms::HScrollBar());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->FFocalLength = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->FDiameter = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->FThickness = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->DWidth = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->ScaleLabel = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->Grooves = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->PixelWidth = (gcnew System::Windows::Forms::TextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->SlitDistance = (gcnew System::Windows::Forms::Label());
			this->GratingDistance1 = (gcnew System::Windows::Forms::Label());
			this->GratingDistance = (gcnew System::Windows::Forms::Label());
			this->FLensDistance1 = (gcnew System::Windows::Forms::Label());
			this->FLensDistance = (gcnew System::Windows::Forms::Label());
			this->DetectorDistance = (gcnew System::Windows::Forms::Label());
			this->IncidentAngle1 = (gcnew System::Windows::Forms::Label());
			this->IncidentAngle = (gcnew System::Windows::Forms::Label());
			this->DiffractedAngle1 = (gcnew System::Windows::Forms::Label());
			this->DiffractedAngle = (gcnew System::Windows::Forms::Label());
			this->CenWavelength = (gcnew System::Windows::Forms::Label());
			this->ColWarning = (gcnew System::Windows::Forms::Label());
			this->DifWarning = (gcnew System::Windows::Forms::Label());
			this->DetWarning = (gcnew System::Windows::Forms::Label());
			this->Res = (gcnew System::Windows::Forms::Label());
			this->ResolutionLabel = (gcnew System::Windows::Forms::Label());
			this->SpectralRange = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(749, 421);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_1);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// PDiameter
			// 
			this->PDiameter->BackColor = System::Drawing::Color::White;
			this->PDiameter->ForeColor = System::Drawing::Color::Black;
			this->PDiameter->Location = System::Drawing::Point(278, 492);
			this->PDiameter->MaxLength = 30;
			this->PDiameter->Name = L"PDiameter";
			this->PDiameter->Size = System::Drawing::Size(35, 20);
			this->PDiameter->TabIndex = 1;
			this->PDiameter->Text = L"60";
			this->PDiameter->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->PDiameter->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->PDiameter->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PDiameter_KeyPress);
			this->PDiameter->Leave += gcnew System::EventHandler(this, &MyForm::PDiameter_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(164, 474);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Telescope";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(164, 495);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Primary Diameter";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(319, 495);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"mm";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(164, 515);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Primary Focal Length";
			// 
			// PFocalLength
			// 
			this->PFocalLength->BackColor = System::Drawing::Color::White;
			this->PFocalLength->ForeColor = System::Drawing::Color::Black;
			this->PFocalLength->Location = System::Drawing::Point(278, 512);
			this->PFocalLength->MaxLength = 30;
			this->PFocalLength->Name = L"PFocalLength";
			this->PFocalLength->Size = System::Drawing::Size(35, 20);
			this->PFocalLength->TabIndex = 6;
			this->PFocalLength->Text = L"360";
			this->PFocalLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->PFocalLength->TextChanged += gcnew System::EventHandler(this, &MyForm::PFocalLength_TextChanged);
			this->PFocalLength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PFocalLength_KeyPress);
			this->PFocalLength->Leave += gcnew System::EventHandler(this, &MyForm::PFocalLength_Leave);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(319, 515);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"mm";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(164, 539);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 16);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Collimating Lens";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(164, 560);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Focal Length";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(164, 580);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Diameter";
			// 
			// CFocalLength
			// 
			this->CFocalLength->BackColor = System::Drawing::Color::White;
			this->CFocalLength->ForeColor = System::Drawing::Color::Black;
			this->CFocalLength->Location = System::Drawing::Point(278, 557);
			this->CFocalLength->MaxLength = 30;
			this->CFocalLength->Name = L"CFocalLength";
			this->CFocalLength->Size = System::Drawing::Size(35, 20);
			this->CFocalLength->TabIndex = 11;
			this->CFocalLength->Text = L"50";
			this->CFocalLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CFocalLength->TextChanged += gcnew System::EventHandler(this, &MyForm::CFocalLength_TextChanged);
			this->CFocalLength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::CFocalLength_KeyPress);
			this->CFocalLength->Leave += gcnew System::EventHandler(this, &MyForm::CFocalLength_Leave);
			// 
			// CDiameter
			// 
			this->CDiameter->BackColor = System::Drawing::Color::White;
			this->CDiameter->ForeColor = System::Drawing::Color::Black;
			this->CDiameter->Location = System::Drawing::Point(278, 577);
			this->CDiameter->MaxLength = 30;
			this->CDiameter->Name = L"CDiameter";
			this->CDiameter->Size = System::Drawing::Size(35, 20);
			this->CDiameter->TabIndex = 12;
			this->CDiameter->Text = L"1";
			this->CDiameter->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CDiameter->TextChanged += gcnew System::EventHandler(this, &MyForm::CDiameter_TextChanged);
			this->CDiameter->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::CDiameter_KeyPress);
			this->CDiameter->Leave += gcnew System::EventHandler(this, &MyForm::CDiameter_Leave);
			// 
			// CThickness
			// 
			this->CThickness->BackColor = System::Drawing::Color::White;
			this->CThickness->ForeColor = System::Drawing::Color::Black;
			this->CThickness->Location = System::Drawing::Point(278, 597);
			this->CThickness->MaxLength = 30;
			this->CThickness->Name = L"CThickness";
			this->CThickness->Size = System::Drawing::Size(35, 20);
			this->CThickness->TabIndex = 13;
			this->CThickness->Text = L"5.2";
			this->CThickness->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CThickness->TextChanged += gcnew System::EventHandler(this, &MyForm::CThickness_TextChanged);
			this->CThickness->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::CThickness_KeyPress);
			this->CThickness->Leave += gcnew System::EventHandler(this, &MyForm::CThickness_Leave);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(164, 600);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(56, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Thickness";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(319, 560);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(23, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"mm";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(319, 580);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(27, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"inch";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(319, 600);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(23, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"mm";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(360, 474);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(113, 16);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Diffraction Grating";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(360, 495);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(35, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Width";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(360, 515);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(38, 13);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Height";
			// 
			// DiffractionWidth
			// 
			this->DiffractionWidth->BackColor = System::Drawing::Color::White;
			this->DiffractionWidth->ForeColor = System::Drawing::Color::Black;
			this->DiffractionWidth->Location = System::Drawing::Point(418, 492);
			this->DiffractionWidth->MaxLength = 30;
			this->DiffractionWidth->Name = L"DiffractionWidth";
			this->DiffractionWidth->Size = System::Drawing::Size(35, 20);
			this->DiffractionWidth->TabIndex = 21;
			this->DiffractionWidth->Text = L"25";
			this->DiffractionWidth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->DiffractionWidth->TextChanged += gcnew System::EventHandler(this, &MyForm::DiffractionWidth_TextChanged);
			this->DiffractionWidth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::DiffractionWidth_KeyPress);
			this->DiffractionWidth->Leave += gcnew System::EventHandler(this, &MyForm::DiffractionWidth_Leave);
			// 
			// DiffractionHeight
			// 
			this->DiffractionHeight->BackColor = System::Drawing::Color::White;
			this->DiffractionHeight->ForeColor = System::Drawing::Color::Black;
			this->DiffractionHeight->Location = System::Drawing::Point(418, 512);
			this->DiffractionHeight->MaxLength = 30;
			this->DiffractionHeight->Name = L"DiffractionHeight";
			this->DiffractionHeight->Size = System::Drawing::Size(35, 20);
			this->DiffractionHeight->TabIndex = 22;
			this->DiffractionHeight->Text = L"12.5";
			this->DiffractionHeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->DiffractionHeight->TextChanged += gcnew System::EventHandler(this, &MyForm::DiffractionHeight_TextChanged);
			this->DiffractionHeight->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::DiffractionHeight_KeyPress);
			this->DiffractionHeight->Leave += gcnew System::EventHandler(this, &MyForm::DiffractionHeight_Leave);
			// 
			// DiffractionPosition
			// 
			this->DiffractionPosition->LargeChange = 1;
			this->DiffractionPosition->Location = System::Drawing::Point(382, 577);
			this->DiffractionPosition->Maximum = 175;
			this->DiffractionPosition->Name = L"DiffractionPosition";
			this->DiffractionPosition->Size = System::Drawing::Size(93, 20);
			this->DiffractionPosition->TabIndex = 23;
			this->DiffractionPosition->Value = 100;
			this->DiffractionPosition->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::DiffractionPosition_Scroll);
			this->DiffractionPosition->ValueChanged += gcnew System::EventHandler(this, &MyForm::DiffractionPosition_ValueChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(360, 535);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(33, 13);
			this->label16->TabIndex = 24;
			this->label16->Text = L"Order";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(360, 560);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(62, 13);
			this->label17->TabIndex = 25;
			this->label17->Text = L"Position: 1 f";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(360, 600);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(93, 13);
			this->label18->TabIndex = 26;
			this->label18->Text = L"Angle: 45 degrees";
			// 
			// DiffractionOrder
			// 
			this->DiffractionOrder->BackColor = System::Drawing::Color::White;
			this->DiffractionOrder->ForeColor = System::Drawing::Color::Black;
			this->DiffractionOrder->FormattingEnabled = true;
			this->DiffractionOrder->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"2", L"1", L"-1", L"-2" });
			this->DiffractionOrder->Location = System::Drawing::Point(418, 532);
			this->DiffractionOrder->MaxLength = 1;
			this->DiffractionOrder->Name = L"DiffractionOrder";
			this->DiffractionOrder->Size = System::Drawing::Size(35, 21);
			this->DiffractionOrder->TabIndex = 27;
			this->DiffractionOrder->Text = L"1";
			this->DiffractionOrder->TextChanged += gcnew System::EventHandler(this, &MyForm::DiffractionOrder_TextChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(360, 580);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(19, 13);
			this->label19->TabIndex = 28;
			this->label19->Text = L"2 f";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(478, 580);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(34, 13);
			this->label20->TabIndex = 29;
			this->label20->Text = L"0.25 f";
			// 
			// DiffractionAngle
			// 
			this->DiffractionAngle->LargeChange = 1;
			this->DiffractionAngle->Location = System::Drawing::Point(384, 613);
			this->DiffractionAngle->Maximum = 900;
			this->DiffractionAngle->Minimum = -900;
			this->DiffractionAngle->Name = L"DiffractionAngle";
			this->DiffractionAngle->Size = System::Drawing::Size(91, 20);
			this->DiffractionAngle->TabIndex = 30;
			this->DiffractionAngle->Value = 450;
			this->DiffractionAngle->ValueChanged += gcnew System::EventHandler(this, &MyForm::DiffractionAngle_ValueChanged);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(359, 616);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(22, 13);
			this->label21->TabIndex = 31;
			this->label21->Text = L"-90";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(478, 616);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(19, 13);
			this->label22->TabIndex = 32;
			this->label22->Text = L"90";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(459, 495);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(23, 13);
			this->label23->TabIndex = 33;
			this->label23->Text = L"mm";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(459, 515);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(23, 13);
			this->label24->TabIndex = 34;
			this->label24->Text = L"mm";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Black;
			this->label25->Location = System::Drawing::Point(12, 474);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(124, 16);
			this->label25->TabIndex = 35;
			this->label25->Text = L"Wavelength Range";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->ForeColor = System::Drawing::Color::Black;
			this->label26->Location = System::Drawing::Point(12, 495);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(48, 13);
			this->label26->TabIndex = 36;
			this->label26->Text = L"Minimum";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->ForeColor = System::Drawing::Color::Black;
			this->label27->Location = System::Drawing::Point(12, 515);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(51, 13);
			this->label27->TabIndex = 37;
			this->label27->Text = L"Maximum";
			// 
			// MinWavelength
			// 
			this->MinWavelength->BackColor = System::Drawing::Color::White;
			this->MinWavelength->ForeColor = System::Drawing::Color::Black;
			this->MinWavelength->Location = System::Drawing::Point(80, 492);
			this->MinWavelength->MaxLength = 30;
			this->MinWavelength->Name = L"MinWavelength";
			this->MinWavelength->Size = System::Drawing::Size(35, 20);
			this->MinWavelength->TabIndex = 38;
			this->MinWavelength->Text = L"390";
			this->MinWavelength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->MinWavelength->TextChanged += gcnew System::EventHandler(this, &MyForm::MinWavelength_TextChanged);
			this->MinWavelength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MinWavelength_KeyPress);
			this->MinWavelength->Leave += gcnew System::EventHandler(this, &MyForm::MinWavelength_Leave);
			// 
			// MaxWavelength
			// 
			this->MaxWavelength->BackColor = System::Drawing::Color::White;
			this->MaxWavelength->ForeColor = System::Drawing::Color::Black;
			this->MaxWavelength->Location = System::Drawing::Point(80, 512);
			this->MaxWavelength->MaxLength = 30;
			this->MaxWavelength->Name = L"MaxWavelength";
			this->MaxWavelength->Size = System::Drawing::Size(35, 20);
			this->MaxWavelength->TabIndex = 39;
			this->MaxWavelength->Text = L"700";
			this->MaxWavelength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->MaxWavelength->TextChanged += gcnew System::EventHandler(this, &MyForm::MaxWavelength_TextChanged);
			this->MaxWavelength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MaxWavelength_KeyPress);
			this->MaxWavelength->Leave += gcnew System::EventHandler(this, &MyForm::MaxWavelength_Leave);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->ForeColor = System::Drawing::Color::Black;
			this->label28->Location = System::Drawing::Point(121, 495);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(21, 13);
			this->label28->TabIndex = 40;
			this->label28->Text = L"nm";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->ForeColor = System::Drawing::Color::Black;
			this->label29->Location = System::Drawing::Point(121, 515);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(21, 13);
			this->label29->TabIndex = 41;
			this->label29->Text = L"nm";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(527, 516);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(95, 16);
			this->label30->TabIndex = 42;
			this->label30->Text = L"Focusing Lens";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(527, 537);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(69, 13);
			this->label31->TabIndex = 43;
			this->label31->Text = L"Focal Length";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(527, 557);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(49, 13);
			this->label32->TabIndex = 44;
			this->label32->Text = L"Diameter";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(527, 577);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(56, 13);
			this->label33->TabIndex = 45;
			this->label33->Text = L"Thickness";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(527, 600);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(77, 13);
			this->label34->TabIndex = 46;
			this->label34->Text = L"Position: 1.01 f";
			// 
			// FPosition
			// 
			this->FPosition->LargeChange = 1;
			this->FPosition->Location = System::Drawing::Point(564, 613);
			this->FPosition->Maximum = 300;
			this->FPosition->Minimum = 101;
			this->FPosition->Name = L"FPosition";
			this->FPosition->Size = System::Drawing::Size(93, 20);
			this->FPosition->TabIndex = 47;
			this->FPosition->Value = 101;
			this->FPosition->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::FPosition_Scroll);
			this->FPosition->ValueChanged += gcnew System::EventHandler(this, &MyForm::FPosition_ValueChanged);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(527, 616);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(34, 13);
			this->label35->TabIndex = 48;
			this->label35->Text = L"1.01 f";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(660, 616);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(19, 13);
			this->label36->TabIndex = 49;
			this->label36->Text = L"3 f";
			// 
			// FFocalLength
			// 
			this->FFocalLength->BackColor = System::Drawing::Color::White;
			this->FFocalLength->ForeColor = System::Drawing::Color::Black;
			this->FFocalLength->Location = System::Drawing::Point(611, 534);
			this->FFocalLength->MaxLength = 30;
			this->FFocalLength->Name = L"FFocalLength";
			this->FFocalLength->Size = System::Drawing::Size(35, 20);
			this->FFocalLength->TabIndex = 50;
			this->FFocalLength->Text = L"25";
			this->FFocalLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->FFocalLength->TextChanged += gcnew System::EventHandler(this, &MyForm::FFocalLength_TextChanged);
			this->FFocalLength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::FFocalLength_KeyPress);
			this->FFocalLength->Leave += gcnew System::EventHandler(this, &MyForm::FFocalLength_Leave);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(652, 537);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(23, 13);
			this->label37->TabIndex = 51;
			this->label37->Text = L"mm";
			// 
			// FDiameter
			// 
			this->FDiameter->BackColor = System::Drawing::Color::White;
			this->FDiameter->ForeColor = System::Drawing::Color::Black;
			this->FDiameter->Location = System::Drawing::Point(611, 554);
			this->FDiameter->MaxLength = 30;
			this->FDiameter->Name = L"FDiameter";
			this->FDiameter->Size = System::Drawing::Size(35, 20);
			this->FDiameter->TabIndex = 52;
			this->FDiameter->Text = L"1";
			this->FDiameter->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->FDiameter->TextChanged += gcnew System::EventHandler(this, &MyForm::FDiameter_TextChanged);
			this->FDiameter->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::FDiameter_KeyPress);
			this->FDiameter->Leave += gcnew System::EventHandler(this, &MyForm::FDiameter_Leave);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(652, 557);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(27, 13);
			this->label38->TabIndex = 53;
			this->label38->Text = L"inch";
			// 
			// FThickness
			// 
			this->FThickness->BackColor = System::Drawing::Color::White;
			this->FThickness->ForeColor = System::Drawing::Color::Black;
			this->FThickness->Location = System::Drawing::Point(611, 574);
			this->FThickness->MaxLength = 30;
			this->FThickness->Name = L"FThickness";
			this->FThickness->Size = System::Drawing::Size(35, 20);
			this->FThickness->TabIndex = 54;
			this->FThickness->Text = L"5.2";
			this->FThickness->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->FThickness->TextChanged += gcnew System::EventHandler(this, &MyForm::FThickness_TextChanged);
			this->FThickness->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::FThickness_KeyPress);
			this->FThickness->Leave += gcnew System::EventHandler(this, &MyForm::FThickness_Leave);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(652, 577);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(23, 13);
			this->label39->TabIndex = 55;
			this->label39->Text = L"mm";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->Location = System::Drawing::Point(693, 474);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(59, 16);
			this->label40->TabIndex = 56;
			this->label40->Text = L"Detector";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(693, 495);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(35, 13);
			this->label41->TabIndex = 57;
			this->label41->Text = L"Width";
			// 
			// DWidth
			// 
			this->DWidth->BackColor = System::Drawing::Color::White;
			this->DWidth->ForeColor = System::Drawing::Color::Black;
			this->DWidth->Location = System::Drawing::Point(765, 492);
			this->DWidth->MaxLength = 30;
			this->DWidth->Name = L"DWidth";
			this->DWidth->Size = System::Drawing::Size(35, 20);
			this->DWidth->TabIndex = 59;
			this->DWidth->Text = L"8.467";
			this->DWidth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->DWidth->TextChanged += gcnew System::EventHandler(this, &MyForm::DWidth_TextChanged);
			this->DWidth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::DWidth_KeyPress);
			this->DWidth->Leave += gcnew System::EventHandler(this, &MyForm::DWidth_Leave);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(806, 495);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(23, 13);
			this->label43->TabIndex = 61;
			this->label43->Text = L"mm";
			// 
			// ScaleLabel
			// 
			this->ScaleLabel->AutoSize = true;
			this->ScaleLabel->Location = System::Drawing::Point(531, 433);
			this->ScaleLabel->Name = L"ScaleLabel";
			this->ScaleLabel->Size = System::Drawing::Size(230, 13);
			this->ScaleLabel->TabIndex = 63;
			this->ScaleLabel->Text = L"Simulation Window Scale: 5000 mm x 5000 mm";
			this->ScaleLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(531, 477);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(68, 13);
			this->label45->TabIndex = 64;
			this->label45->Text = L"Grooves/mm";
			// 
			// Grooves
			// 
			this->Grooves->BackColor = System::Drawing::Color::White;
			this->Grooves->ForeColor = System::Drawing::Color::Black;
			this->Grooves->Location = System::Drawing::Point(611, 473);
			this->Grooves->MaxLength = 30;
			this->Grooves->Name = L"Grooves";
			this->Grooves->Size = System::Drawing::Size(35, 20);
			this->Grooves->TabIndex = 65;
			this->Grooves->Text = L"600";
			this->Grooves->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->Grooves->TextChanged += gcnew System::EventHandler(this, &MyForm::Grooves_TextChanged);
			this->Grooves->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Grooves_KeyPress);
			this->Grooves->Leave += gcnew System::EventHandler(this, &MyForm::Grooves_Leave);
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(693, 515);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(60, 13);
			this->label47->TabIndex = 67;
			this->label47->Text = L"Pixel Width";
			// 
			// PixelWidth
			// 
			this->PixelWidth->BackColor = System::Drawing::Color::White;
			this->PixelWidth->ForeColor = System::Drawing::Color::Black;
			this->PixelWidth->Location = System::Drawing::Point(765, 512);
			this->PixelWidth->MaxLength = 30;
			this->PixelWidth->Name = L"PixelWidth";
			this->PixelWidth->Size = System::Drawing::Size(35, 20);
			this->PixelWidth->TabIndex = 69;
			this->PixelWidth->Text = L"3.6";
			this->PixelWidth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->PixelWidth->TextChanged += gcnew System::EventHandler(this, &MyForm::PixelWidth_TextChanged);
			this->PixelWidth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PixelWidth_KeyPress);
			this->PixelWidth->Leave += gcnew System::EventHandler(this, &MyForm::PixelWidth_Leave);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(806, 515);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(21, 13);
			this->label49->TabIndex = 71;
			this->label49->Text = L"um";
			// 
			// SlitDistance
			// 
			this->SlitDistance->AutoSize = true;
			this->SlitDistance->BackColor = System::Drawing::Color::Black;
			this->SlitDistance->ForeColor = System::Drawing::Color::White;
			this->SlitDistance->Location = System::Drawing::Point(21, 24);
			this->SlitDistance->Name = L"SlitDistance";
			this->SlitDistance->Size = System::Drawing::Size(183, 13);
			this->SlitDistance->TabIndex = 73;
			this->SlitDistance->Text = L"Slit to Collimating Lens Center: 50 mm";
			// 
			// GratingDistance1
			// 
			this->GratingDistance1->AutoSize = true;
			this->GratingDistance1->BackColor = System::Drawing::Color::Black;
			this->GratingDistance1->ForeColor = System::Drawing::Color::White;
			this->GratingDistance1->Location = System::Drawing::Point(21, 48);
			this->GratingDistance1->Name = L"GratingDistance1";
			this->GratingDistance1->Size = System::Drawing::Size(129, 13);
			this->GratingDistance1->TabIndex = 74;
			this->GratingDistance1->Text = L"Collimating Lens Center to";
			// 
			// GratingDistance
			// 
			this->GratingDistance->AutoSize = true;
			this->GratingDistance->BackColor = System::Drawing::Color::Black;
			this->GratingDistance->ForeColor = System::Drawing::Color::White;
			this->GratingDistance->Location = System::Drawing::Point(21, 61);
			this->GratingDistance->Name = L"GratingDistance";
			this->GratingDistance->Size = System::Drawing::Size(222, 13);
			this->GratingDistance->TabIndex = 75;
			this->GratingDistance->Text = L"Center of Diffraction Grating\'s Surface: 50 mm";
			// 
			// FLensDistance1
			// 
			this->FLensDistance1->AutoSize = true;
			this->FLensDistance1->BackColor = System::Drawing::Color::Black;
			this->FLensDistance1->ForeColor = System::Drawing::Color::White;
			this->FLensDistance1->Location = System::Drawing::Point(21, 85);
			this->FLensDistance1->Name = L"FLensDistance1";
			this->FLensDistance1->Size = System::Drawing::Size(197, 13);
			this->FLensDistance1->TabIndex = 76;
			this->FLensDistance1->Text = L"Center of Diffraction Grating\'s Surface to";
			// 
			// FLensDistance
			// 
			this->FLensDistance->AutoSize = true;
			this->FLensDistance->BackColor = System::Drawing::Color::Black;
			this->FLensDistance->ForeColor = System::Drawing::Color::White;
			this->FLensDistance->Location = System::Drawing::Point(21, 98);
			this->FLensDistance->Name = L"FLensDistance";
			this->FLensDistance->Size = System::Drawing::Size(147, 13);
			this->FLensDistance->TabIndex = 77;
			this->FLensDistance->Text = L"Focusing Lens Center: 50 mm";
			// 
			// DetectorDistance
			// 
			this->DetectorDistance->AutoSize = true;
			this->DetectorDistance->BackColor = System::Drawing::Color::Black;
			this->DetectorDistance->ForeColor = System::Drawing::Color::White;
			this->DetectorDistance->Location = System::Drawing::Point(21, 123);
			this->DetectorDistance->Name = L"DetectorDistance";
			this->DetectorDistance->Size = System::Drawing::Size(237, 13);
			this->DetectorDistance->TabIndex = 78;
			this->DetectorDistance->Text = L"Focusing Lens Center to Detector Center: 50 mm";
			// 
			// IncidentAngle1
			// 
			this->IncidentAngle1->AutoSize = true;
			this->IncidentAngle1->BackColor = System::Drawing::Color::Black;
			this->IncidentAngle1->ForeColor = System::Drawing::Color::White;
			this->IncidentAngle1->Location = System::Drawing::Point(21, 148);
			this->IncidentAngle1->Name = L"IncidentAngle1";
			this->IncidentAngle1->Size = System::Drawing::Size(136, 13);
			this->IncidentAngle1->TabIndex = 79;
			this->IncidentAngle1->Text = L"Incident Angle of Light from";
			// 
			// IncidentAngle
			// 
			this->IncidentAngle->AutoSize = true;
			this->IncidentAngle->BackColor = System::Drawing::Color::Black;
			this->IncidentAngle->ForeColor = System::Drawing::Color::White;
			this->IncidentAngle->Location = System::Drawing::Point(21, 161);
			this->IncidentAngle->Name = L"IncidentAngle";
			this->IncidentAngle->Size = System::Drawing::Size(216, 13);
			this->IncidentAngle->TabIndex = 80;
			this->IncidentAngle->Text = L"Diffraction Grating\'s Optical Axis: 45 degrees";
			// 
			// DiffractedAngle1
			// 
			this->DiffractedAngle1->AutoSize = true;
			this->DiffractedAngle1->BackColor = System::Drawing::Color::Black;
			this->DiffractedAngle1->ForeColor = System::Drawing::Color::White;
			this->DiffractedAngle1->Location = System::Drawing::Point(21, 186);
			this->DiffractedAngle1->Name = L"DiffractedAngle1";
			this->DiffractedAngle1->Size = System::Drawing::Size(203, 13);
			this->DiffractedAngle1->TabIndex = 81;
			this->DiffractedAngle1->Text = L"Center Wavelength Diffraction Angle from";
			// 
			// DiffractedAngle
			// 
			this->DiffractedAngle->AutoSize = true;
			this->DiffractedAngle->BackColor = System::Drawing::Color::Black;
			this->DiffractedAngle->ForeColor = System::Drawing::Color::White;
			this->DiffractedAngle->Location = System::Drawing::Point(21, 199);
			this->DiffractedAngle->Name = L"DiffractedAngle";
			this->DiffractedAngle->Size = System::Drawing::Size(216, 13);
			this->DiffractedAngle->TabIndex = 82;
			this->DiffractedAngle->Text = L"Diffraction Grating\'s Optical Axis: 45 degrees";
			// 
			// CenWavelength
			// 
			this->CenWavelength->AutoSize = true;
			this->CenWavelength->BackColor = System::Drawing::Color::Black;
			this->CenWavelength->ForeColor = System::Drawing::Color::White;
			this->CenWavelength->Location = System::Drawing::Point(21, 223);
			this->CenWavelength->Name = L"CenWavelength";
			this->CenWavelength->Size = System::Drawing::Size(140, 13);
			this->CenWavelength->TabIndex = 83;
			this->CenWavelength->Text = L"Center Wavelength: 500 nm";
			// 
			// ColWarning
			// 
			this->ColWarning->AutoSize = true;
			this->ColWarning->ForeColor = System::Drawing::Color::Red;
			this->ColWarning->Location = System::Drawing::Point(9, 433);
			this->ColWarning->Name = L"ColWarning";
			this->ColWarning->Size = System::Drawing::Size(207, 13);
			this->ColWarning->TabIndex = 84;
			this->ColWarning->Text = L"Warning: Collimating lens not wide enough";
			this->ColWarning->Visible = false;
			// 
			// DifWarning
			// 
			this->DifWarning->AutoSize = true;
			this->DifWarning->ForeColor = System::Drawing::Color::Red;
			this->DifWarning->Location = System::Drawing::Point(9, 446);
			this->DifWarning->Name = L"DifWarning";
			this->DifWarning->Size = System::Drawing::Size(274, 13);
			this->DifWarning->TabIndex = 85;
			this->DifWarning->Text = L"Warning: Diffraction grating dimensions not large enough";
			this->DifWarning->Visible = false;
			// 
			// DetWarning
			// 
			this->DetWarning->AutoSize = true;
			this->DetWarning->ForeColor = System::Drawing::Color::Red;
			this->DetWarning->Location = System::Drawing::Point(9, 459);
			this->DetWarning->Name = L"DetWarning";
			this->DetWarning->Size = System::Drawing::Size(175, 13);
			this->DetWarning->TabIndex = 86;
			this->DetWarning->Text = L"Warning: Vignetting on the detector";
			this->DetWarning->Visible = false;
			// 
			// Res
			// 
			this->Res->AutoSize = true;
			this->Res->BackColor = System::Drawing::Color::Black;
			this->Res->ForeColor = System::Drawing::Color::White;
			this->Res->Location = System::Drawing::Point(21, 247);
			this->Res->Name = L"Res";
			this->Res->Size = System::Drawing::Size(166, 13);
			this->Res->TabIndex = 87;
			this->Res->Text = L"Estimated Resolving Power: 5000";
			// 
			// ResolutionLabel
			// 
			this->ResolutionLabel->AutoSize = true;
			this->ResolutionLabel->BackColor = System::Drawing::Color::Black;
			this->ResolutionLabel->ForeColor = System::Drawing::Color::White;
			this->ResolutionLabel->Location = System::Drawing::Point(21, 272);
			this->ResolutionLabel->Name = L"ResolutionLabel";
			this->ResolutionLabel->Size = System::Drawing::Size(144, 13);
			this->ResolutionLabel->TabIndex = 88;
			this->ResolutionLabel->Text = L"Estimated Resolution: 2.6 nm";
			// 
			// SpectralRange
			// 
			this->SpectralRange->AutoSize = true;
			this->SpectralRange->BackColor = System::Drawing::Color::Black;
			this->SpectralRange->ForeColor = System::Drawing::Color::White;
			this->SpectralRange->Location = System::Drawing::Point(21, 298);
			this->SpectralRange->Name = L"SpectralRange";
			this->SpectralRange->Size = System::Drawing::Size(274, 13);
			this->SpectralRange->TabIndex = 89;
			this->SpectralRange->Text = L"Estimated Spectral Range on Detector: 400 nm - 600 nm";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 650);
			this->Controls->Add(this->SpectralRange);
			this->Controls->Add(this->ResolutionLabel);
			this->Controls->Add(this->Res);
			this->Controls->Add(this->DetWarning);
			this->Controls->Add(this->DifWarning);
			this->Controls->Add(this->ColWarning);
			this->Controls->Add(this->CenWavelength);
			this->Controls->Add(this->DiffractedAngle);
			this->Controls->Add(this->DiffractedAngle1);
			this->Controls->Add(this->IncidentAngle);
			this->Controls->Add(this->IncidentAngle1);
			this->Controls->Add(this->DetectorDistance);
			this->Controls->Add(this->FLensDistance);
			this->Controls->Add(this->FLensDistance1);
			this->Controls->Add(this->GratingDistance);
			this->Controls->Add(this->GratingDistance1);
			this->Controls->Add(this->SlitDistance);
			this->Controls->Add(this->label49);
			this->Controls->Add(this->PixelWidth);
			this->Controls->Add(this->label47);
			this->Controls->Add(this->Grooves);
			this->Controls->Add(this->label45);
			this->Controls->Add(this->ScaleLabel);
			this->Controls->Add(this->label43);
			this->Controls->Add(this->DWidth);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->FThickness);
			this->Controls->Add(this->label38);
			this->Controls->Add(this->FDiameter);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->FFocalLength);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->FPosition);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->MaxWavelength);
			this->Controls->Add(this->MinWavelength);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->DiffractionAngle);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->DiffractionOrder);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->DiffractionPosition);
			this->Controls->Add(this->DiffractionHeight);
			this->Controls->Add(this->DiffractionWidth);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->CThickness);
			this->Controls->Add(this->CDiameter);
			this->Controls->Add(this->CFocalLength);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->PFocalLength);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PDiameter);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"The IPFW Physics Classic Astronomical Spectrograph Simulator - Version 1.0";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		//****THIS IS THE MAIN CODE OF THE PROGRAM****
		//Should have renamed pictureBox1 to something more appropriate, oh well.

		telescope scope(
			System::Single::Parse(PDiameter->Text), 
			System::Single::Parse(PFocalLength->Text));
		
		lens collimator(
			System::Single::Parse(CDiameter->Text) * 25.4f, 
			System::Single::Parse(CThickness->Text),
			System::Single::Parse(CFocalLength->Text),
			System::Single::Parse(CFocalLength->Text),
			1.515f);

		lens focuser(
			System::Single::Parse(FDiameter->Text) * 25.4f,
			System::Single::Parse(FThickness->Text),
			System::Single::Parse(FFocalLength->Text),
			FPosition->Value * 0.01f * System::Single::Parse(FFocalLength->Text),
			1.515f);

		diffractiongrating grating(
			System::Single::Parse(DiffractionWidth->Text),
			System::Single::Parse(DiffractionHeight->Text),
			1.0f,
			System::Single::Parse(DiffractionOrder->Text),
			1.0f,
			1.0f,
			System::Single::Parse(Grooves->Text));
		//Unused portions of the grating are set to be 1.0f

		classicastrospectrograph astro(
			System::Single::Parse(MinWavelength->Text) * 1E-9f, 
			System::Single::Parse(MaxWavelength->Text) * 1E-9f,
			scope.getDiameter(),
			scope.getFocalLength(), 
			collimator.getDiameter(), 
			collimator.getFocalLength(),
			collimator.getLastPlaneDistance(), 
			grating.getWidth(), 
			2.0f * collimator.getFocalLength() - DiffractionPosition->Value * 0.01f * collimator.getFocalLength(),
			DiffractionAngle->Value * 0.1f * 3.1415926535897932384626f / 180.0f,
			grating.getGrooves(), 
			grating.getOrder(), 
			focuser.getDiameter(), 
			focuser.getFocalLength(),
			focuser.getObjectDistance(), 
			focuser.getLastPlaneDistance(), 
			focuser.getImageDistance(),
			System::Single::Parse(DWidth->Text),
			System::Single::Parse(PixelWidth->Text));

		
		float pixelspermm = pictureBox1->Right / (5.0f * collimator.getFocalLength()); //Converts mm to pixels
		float beamstartx = 0.0f; //initialize starting x coordinate in picturebox
		float beamstarty = 0.0f; //initialize starting y coordinate in picturebox

		//Now let's set our origin
		if (astro.getGratingAngle() >= 0.0f)
		{
			beamstartx = pictureBox1->Right - 50.0f;
			beamstarty = pictureBox1->Bottom / 4.0f;
		}
		else
		{
			beamstartx = pictureBox1->Right - 50.0f;
			beamstarty = pictureBox1->Bottom / 1.35f;
		}
		


		//Calculations on left side of picturebox
		SlitDistance->Text = ("Slit to Collimating Lens Center: " +
			System::Convert::ToString(Math::Round(collimator.getCenterDistance(), 2)) + " mm");
		GratingDistance->Text = ("Center of Diffraction Grating's Surface: " +
			System::Convert::ToString(Math::Round(astro.getDistSourceToGrating() - collimator.getCenterDistance(), 2)) + " mm");
		FLensDistance->Text = ("Focusing Lens Center: " +
			System::Convert::ToString(Math::Round(focuser.getCenterDistance(), 2)) + " mm");
		DetectorDistance->Text = ("Focusing Lens Center to Detector Center: " +
			System::Convert::ToString(Math::Round(focuser.getFocalLength() + focuser.getThickness() / 2.0f + focuser.getPrinciplePlane(), 2)) + " mm");
		IncidentAngle->Text = ("Diffraction Grating's Optical Axis: " +
			System::Convert::ToString(Math::Round(astro.getIncidentAngle() * 180.0f / 3.1415926535897932384626f, 2)) + " degrees");
		DiffractedAngle->Text = ("Diffraction Grating's Optical Axis: " +
			System::Convert::ToString(Math::Round(astro.getCenDiffractAngle() * 180.0f / 3.1415926535897932384626f, 2)) + " degrees");
		CenWavelength->Text = ("Center Wavelength: " +
			System::Convert::ToString(Math::Round(astro.getCenWavelength() * 1E9f, 2)) + " nm");		
		SpectralRange->Text = ("Estimated Spectral Range on Detector: " +
			System::Convert::ToString(Math::Round(astro.getSpectralRangeMin(), 2)) + " nm - " +
			System::Convert::ToString(Math::Round(astro.getSpectralRangeMax(), 2)) + " nm");
		Res->Text = ("Estimated Resolving Power: " +
			System::Convert::ToString(Math::Round(fabsf(astro.getResolvingPower()), 2)));
		ResolutionLabel->Text = ("Estimated Spectral Resolution: " +
			System::Convert::ToString(Math::Round(fabsf(astro.getResolution() * 1E9f), 2)) + " nm");

		//Set the Scale Label to let the user know the simulation window size in mm
		ScaleLabel->Text = ("Simulation Window Scale: " +
			System::Convert::ToString(Math::Round(pictureBox1->Right / pixelspermm, 1)) + " mm x " +
			System::Convert::ToString(Math::Round(pictureBox1->Bottom / pixelspermm, 1)) + " mm");


		//Error checks
		if (astro.getInitialBeamWidth() > collimator.getDiameter())
		{
			ColWarning->Visible = true;
		}
		else
		{
			ColWarning->Visible = false;
		}
		if ((astro.getCollimatedRadius() * 2.0f) > grating.getHeight() || (astro.getCollimatedRadius() * 2.0f / cosf(astro.getIncidentAngle() + 0.000001f)) > grating.getWidth())
		{
			DifWarning->Visible = true;
		}
		else
		{
			DifWarning->Visible = false;
		}
		if ((focuser.getFocalLength() / focuser.getDiameter()) > (focuser.getFocalLength() / astro.getDiffractedDispersion()))
		{
			DetWarning->Visible = true;
		}
		else
		{
			DetWarning->Visible = false;
		}



		
		//********* NOW FOR GRAPHICS, RAY BY RAY ***********

		//Fill the picturebox with a black background
		SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
		Rectangle rect = Rectangle(0, 0,
			pictureBox1->Right, pictureBox1->Bottom);
		e->Graphics->FillRectangle(blackBrush, rect);

		Graphics^ g = e->Graphics;

		//First, light from telescope
		g->DrawLine(System::Drawing::Pens::White, 
			beamstartx,
			beamstarty,
			beamstartx - collimator.getFocalLength() * pixelspermm,
			beamstarty - (astro.getInitialBeamWidth() / 2.0f) * pixelspermm);
		g->DrawLine(System::Drawing::Pens::White, 
			beamstartx,
			beamstarty,
			beamstartx - collimator.getFocalLength() * pixelspermm,
			beamstarty + (astro.getInitialBeamWidth() / 2.0f) * pixelspermm);

		//Next, draw the line representing center of collimating lens at its diameter
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - collimator.getCenterDistance() * pixelspermm,
			beamstarty - collimator.getRadius() * pixelspermm,
			beamstartx - collimator.getCenterDistance() * pixelspermm,
			beamstarty + collimator.getRadius() * pixelspermm);

		//Next, light through collimating lens
		g->DrawLine(System::Drawing::Pens::White, 
			beamstartx - collimator.getFocalLength() * pixelspermm,
			beamstarty - astro.getCollimatedRadius() * pixelspermm,
			beamstartx - collimator.getLastPlaneDistance() * pixelspermm,
			beamstarty - astro.getCollimatedRadius() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::White, 
			beamstartx - collimator.getFocalLength() * pixelspermm,
			beamstarty + astro.getCollimatedRadius() * pixelspermm,
			beamstartx - collimator.getLastPlaneDistance() * pixelspermm,
			beamstarty + astro.getCollimatedRadius() * pixelspermm);

		//Next, draw line representing surface of diffraction grating
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - astro.getDistSourceToGrating() * pixelspermm,
			beamstarty,
			beamstartx - astro.getGratingTopX() * pixelspermm,
			beamstarty - astro.getGratingY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - astro.getDistSourceToGrating() * pixelspermm,
			beamstarty,
			beamstartx - astro.getGratingBottomX() * pixelspermm,
			beamstarty + astro.getGratingY() * pixelspermm);

		//Next, collimated light hitting the grating's surface
		g->DrawLine(System::Drawing::Pens::White, 
			beamstartx - collimator.getLastPlaneDistance() * pixelspermm,
			beamstarty - astro.getCollimatedRadius() * pixelspermm,
			beamstartx - astro.getGratingRayTopX() * pixelspermm,
			beamstarty - astro.getGratingRayY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::White, 
			beamstartx - collimator.getLastPlaneDistance() * pixelspermm,
			beamstarty + astro.getCollimatedRadius() * pixelspermm,
			beamstartx - astro.getGratingRayBottomX() * pixelspermm,
			beamstarty + astro.getGratingRayY() * pixelspermm);

		//Draw focusing lens
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - astro.getFocuserCenterX() * pixelspermm,
			beamstarty - astro.getFocuserCenterY() * pixelspermm,
			beamstartx - astro.getFocuserTopX() * pixelspermm,
			beamstarty - astro.getFocuserTopY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - astro.getFocuserCenterX() * pixelspermm,
			beamstarty - astro.getFocuserCenterY() * pixelspermm,
			beamstartx - astro.getFocuserBottomX() * pixelspermm,
			beamstarty - astro.getFocuserBottomY() * pixelspermm);

				
		//Draw top rays diffracting
		g->DrawLine(System::Drawing::Pens::Red, 
			beamstartx - astro.getGratingRayTopX() * pixelspermm,
			beamstarty - astro.getGratingRayY() * pixelspermm,
			beamstartx - astro.getFocuserTopRX() * pixelspermm,
			beamstarty - astro.getFocuserTopRY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::Blue, 
			beamstartx - astro.getGratingRayTopX() * pixelspermm,
			beamstarty - astro.getGratingRayY() * pixelspermm,
			beamstartx - astro.getFocuserTopBX() * pixelspermm,
			beamstarty - astro.getFocuserTopBY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::SpringGreen, 
			beamstartx - astro.getGratingRayTopX() * pixelspermm,
			beamstarty - astro.getGratingRayY() * pixelspermm,
			beamstartx - astro.getFocuserTopGX() * pixelspermm,
			beamstarty - astro.getFocuserTopGY() * pixelspermm);



		//Now, Draw bottom rays diffracting
		g->DrawLine(System::Drawing::Pens::Red,
			beamstartx - astro.getGratingRayBottomX() * pixelspermm,
			beamstarty + astro.getGratingRayY() * pixelspermm,
			beamstartx - astro.getFocuserBottomRX() * pixelspermm,
			beamstarty - astro.getFocuserBottomRY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::Blue,
			beamstartx - astro.getGratingRayBottomX() * pixelspermm,
			beamstarty + astro.getGratingRayY() * pixelspermm,
			beamstartx - astro.getFocuserBottomBX() * pixelspermm,
			beamstarty - astro.getFocuserBottomBY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::SpringGreen,
			beamstartx - astro.getGratingRayBottomX() * pixelspermm,
			beamstarty + astro.getGratingRayY() * pixelspermm,
			beamstartx - astro.getFocuserBottomGX() * pixelspermm,
			beamstarty - astro.getFocuserBottomGY() * pixelspermm);

		//Now draw the top rays transmitting through the lens
		g->DrawLine(System::Drawing::Pens::Red,
			beamstartx - astro.getFocuserTopRX() * pixelspermm,
			beamstarty - astro.getFocuserTopRY() * pixelspermm,
			beamstartx - astro.getFocuserThruTopRX() * pixelspermm,
			beamstarty - astro.getFocuserThruTopRY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::Blue,
			beamstartx - astro.getFocuserTopBX() * pixelspermm,
			beamstarty - astro.getFocuserTopBY() * pixelspermm,
			beamstartx - astro.getFocuserThruTopBX() * pixelspermm,
			beamstarty - astro.getFocuserThruTopBY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::SpringGreen,
			beamstartx - astro.getFocuserTopGX() * pixelspermm,
			beamstarty - astro.getFocuserTopGY() * pixelspermm,
			beamstartx - astro.getFocuserThruTopGX() * pixelspermm,
			beamstarty - astro.getFocuserThruTopGY() * pixelspermm);


		//Now draw bottom rays transmitting through focusing lens
		g->DrawLine(System::Drawing::Pens::Red,
			beamstartx - astro.getFocuserBottomRX() * pixelspermm,
			beamstarty - astro.getFocuserBottomRY() * pixelspermm,
			beamstartx - astro.getFocuserThruBottomRX() * pixelspermm,
			beamstarty - astro.getFocuserThruBottomRY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::Blue,
			beamstartx - astro.getFocuserBottomBX() * pixelspermm,
			beamstarty - astro.getFocuserBottomBY() * pixelspermm,
			beamstartx - astro.getFocuserThruBottomBX() * pixelspermm,
			beamstarty - astro.getFocuserThruBottomBY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::SpringGreen,
			beamstartx - astro.getFocuserBottomGX() * pixelspermm,
			beamstarty - astro.getFocuserBottomGY() * pixelspermm,
			beamstartx - astro.getFocuserThruBottomGX() * pixelspermm,
			beamstarty - astro.getFocuserThruBottomGY() * pixelspermm);

	
		//Draw detector
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - astro.getDetectorCenterX() * pixelspermm,
			beamstarty - astro.getDetectorCenterY() * pixelspermm,
			beamstartx - astro.getDetectorTopX() * pixelspermm,
			beamstarty - astro.getDetectorTopY() * pixelspermm);
		g->DrawLine(System::Drawing::Pens::Aqua, 
			beamstartx - astro.getDetectorCenterX() * pixelspermm,
			beamstarty - astro.getDetectorCenterY() * pixelspermm,
			beamstartx - astro.getDetectorBottomX() * pixelspermm,
			beamstarty - astro.getDetectorBottomY() * pixelspermm);

		//Finally, draw our last converging lines
		g->DrawLine(System::Drawing::Pens::Red,
			beamstartx - astro.getFocuserThruTopRX() * pixelspermm,
			beamstarty - astro.getFocuserThruTopRY() * pixelspermm,
			beamstartx - astro.getDetectorRX() * pixelspermm,
			beamstarty - astro.getDetectorRY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::Blue,
			beamstartx - astro.getFocuserThruTopBX() * pixelspermm,
			beamstarty - astro.getFocuserThruTopBY() * pixelspermm,
			beamstartx - astro.getDetectorBX() * pixelspermm,
			beamstarty - astro.getDetectorBY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::SpringGreen,
			beamstartx - astro.getFocuserThruTopGX() * pixelspermm,
			beamstarty - astro.getFocuserThruTopGY() * pixelspermm,
			beamstartx - astro.getDetectorCenterX() * pixelspermm,
			beamstarty - astro.getDetectorCenterY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::Red,
			beamstartx - astro.getFocuserThruBottomRX() * pixelspermm,
			beamstarty - astro.getFocuserThruBottomRY() * pixelspermm,
			beamstartx - astro.getDetectorRX() * pixelspermm,
			beamstarty - astro.getDetectorRY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::Blue,
			beamstartx - astro.getFocuserThruBottomBX() * pixelspermm,
			beamstarty - astro.getFocuserThruBottomBY() * pixelspermm,
			beamstartx - astro.getDetectorBX() * pixelspermm,
			beamstarty - astro.getDetectorBY() * pixelspermm);

		g->DrawLine(System::Drawing::Pens::SpringGreen,
			beamstartx - astro.getFocuserThruBottomGX() * pixelspermm,
			beamstarty - astro.getFocuserThruBottomGY() * pixelspermm,
			beamstartx - astro.getDetectorCenterX() * pixelspermm,
			beamstarty - astro.getDetectorCenterY() * pixelspermm);


	}



	//The bulk of the rest of the code is making suring the user doesn't do something stupid like
	//set the wavelength to a letter or set the grating size to just "." or make things negative

	//Error preventing most things, hopefully.

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (PDiameter->Text != "" && PDiameter->Text != ".")
		{
			if (System::Single::Parse(PDiameter->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void PFocalLength_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (PFocalLength->Text != "" && PFocalLength->Text != ".")
		{
			if (System::Single::Parse(PFocalLength->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void PDiameter_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Allow only positive numbers and backspace in textbox, e->Handled = true/false
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void PDiameter_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (PDiameter->Text == "" || PDiameter->Text == ".")
		{
			PDiameter->Text = "1";
		}
	}
	private: System::Void PFocalLength_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (PFocalLength->Text == "" || PFocalLength->Text == ".")
		{
			PFocalLength->Text = "1";
		}
	}
	private: System::Void CFocalLength_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (CFocalLength->Text != "" && CFocalLength->Text != ".")
		{
			if (System::Single::Parse(CFocalLength->Text) > System::Single::Parse(CThickness->Text))
			{
				if (System::Single::Parse(CFocalLength->Text) > 0)
				{
					pictureBox1->Refresh();
				}
			}
		}
	}
	private: System::Void CFocalLength_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (CFocalLength->Text == "" || CFocalLength->Text == ".")
		{
			CFocalLength->Text = CThickness->Text;
		}
		if (System::Single::Parse(CFocalLength->Text) < System::Single::Parse(CThickness->Text))
		{
			CFocalLength->Text = CThickness->Text;
		}
	}
	private: System::Void CFocalLength_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Allow only positive numbers and backspace in textbox, e->Handled = true/false
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void PFocalLength_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Allow only positive numbers and backspace in textbox, e->Handled = true/false
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void CDiameter_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (CDiameter->Text != "" && CDiameter->Text != ".")
		{
			if (System::Single::Parse(CDiameter->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void CDiameter_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (CDiameter->Text == "" || CDiameter->Text == ".")
		{
			CDiameter->Text = "1";
		}
	}
	private: System::Void CDiameter_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void CThickness_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (CThickness->Text != "" && CThickness->Text != ".")
		{
			if (System::Single::Parse(CFocalLength->Text) > System::Single::Parse(CThickness->Text))
			{
				if (System::Single::Parse(CThickness->Text) > 0)
				{
					pictureBox1->Refresh();
				}
			}
		}
	}
	private: System::Void CThickness_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (CThickness->Text == "" || CThickness->Text == ".")
		{
			CThickness->Text = CFocalLength->Text;
		}
		if (System::Single::Parse(CFocalLength->Text) < System::Single::Parse(CThickness->Text))
		{
			CThickness->Text = CFocalLength->Text;
		}
	}
	private: System::Void CThickness_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void DiffractionPosition_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		label17->Text = ("Position: " + System::Convert::ToString(Math::Round((200.0f - DiffractionPosition->Value) * 0.01f, 2)) + " f");
		pictureBox1->Refresh();
	}
	private: System::Void DiffractionAngle_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		label18->Text = ("Angle: " + System::Convert::ToString(Math::Round(DiffractionAngle->Value * 0.1f, 1)) + " degrees");
		pictureBox1->Refresh();
	}
	private: System::Void DiffractionWidth_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (DiffractionWidth->Text != "" && DiffractionWidth->Text != ".")
		{
			if (System::Single::Parse(DiffractionWidth->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void DiffractionWidth_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void DiffractionWidth_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (DiffractionWidth->Text == "" || DiffractionWidth->Text == ".")
		{
			DiffractionWidth->Text = "1";
		}
	}
	private: System::Void DiffractionHeight_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (DiffractionHeight->Text != "" && DiffractionHeight->Text != ".")
		{
			if (System::Single::Parse(DiffractionHeight->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void DiffractionHeight_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void DiffractionHeight_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (DiffractionHeight->Text == "" || DiffractionHeight->Text == ".")
		{
			DiffractionHeight->Text = "1";
		}
	}
	private: System::Void DiffractionOrder_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (DiffractionOrder->Text == "2" || DiffractionOrder->Text == "1" ||
			DiffractionOrder->Text == "-1" || DiffractionOrder->Text == "-2") {

			pictureBox1->Refresh();
		}
		else {
			DiffractionOrder->Text = "1";
		}
	}
	private: System::Void FPosition_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		label34->Text = ("Position: " + System::Convert::ToString(Math::Round((FPosition->Value) * 0.01f, 2)) + " f");
		pictureBox1->Refresh();
	}
	private: System::Void DiffractionPosition_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	}
	private: System::Void MinWavelength_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (MinWavelength->Text != "" && MinWavelength->Text != ".")
		{
			if (System::Single::Parse(MinWavelength->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void MinWavelength_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (MinWavelength->Text == "" || MinWavelength->Text == ".")
		{
			MinWavelength->Text = "1";
		}
	}
	private: System::Void MinWavelength_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void MaxWavelength_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (MaxWavelength->Text != "" && MaxWavelength->Text != ".")
		{
			if (System::Single::Parse(MaxWavelength->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void MaxWavelength_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (MaxWavelength->Text == "" || MaxWavelength->Text == ".")
		{
			MaxWavelength->Text = "1";
		}
	}
	private: System::Void MaxWavelength_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void Grooves_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (Grooves->Text != "")
		{
			if (System::Single::Parse(Grooves->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void Grooves_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (Grooves->Text == "")
		{
			Grooves->Text = "1";
		}
	}
	private: System::Void Grooves_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void FFocalLength_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (FFocalLength->Text != "" && FFocalLength->Text != ".")
		{
			if (System::Single::Parse(FFocalLength->Text) > System::Single::Parse(FThickness->Text))
			{
				if (System::Single::Parse(FFocalLength->Text) > 0)
				{
					pictureBox1->Refresh();
				}
			}
		}
	}
	private: System::Void FFocalLength_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (FFocalLength->Text == "" || FFocalLength->Text == ".")
		{
			FFocalLength->Text = FThickness->Text;
		}
		if (System::Single::Parse(FFocalLength->Text) < System::Single::Parse(FThickness->Text))
		{
			FFocalLength->Text = FThickness->Text;
		}
	}
	private: System::Void FFocalLength_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void FDiameter_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (FDiameter->Text != "" && FDiameter->Text != ".")
		{
			if (System::Single::Parse(FDiameter->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void FDiameter_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (FDiameter->Text == "" || FDiameter->Text == ".")
		{
			FDiameter->Text = "1";
		}
	}
	private: System::Void FDiameter_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void FThickness_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (FThickness->Text != "" && FThickness->Text != ".")
		{
			if (System::Single::Parse(FFocalLength->Text) > System::Single::Parse(FThickness->Text))
			{
				if (System::Single::Parse(FThickness->Text) > 0)
				{
					pictureBox1->Refresh();
				}
			}
		}
	}
	private: System::Void FThickness_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (FThickness->Text == "" || FThickness->Text == ".")
		{
			FThickness->Text = FFocalLength->Text;
		}
		if (System::Single::Parse(FFocalLength->Text) < System::Single::Parse(FThickness->Text))
		{
			FThickness->Text = FFocalLength->Text;
		}
	}
	private: System::Void FThickness_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void DWidth_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (DWidth->Text != "" && DWidth->Text != ".")
		{
			if (System::Single::Parse(DWidth->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void DWidth_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (DWidth->Text == "" || DWidth->Text == ".")
		{
			DWidth->Text = "1";
		}
	}
	private: System::Void DWidth_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
	private: System::Void PixelWidth_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (PixelWidth->Text != "" && PixelWidth->Text != ".")
		{
			if (System::Single::Parse(PixelWidth->Text) > 0)
			{
				pictureBox1->Refresh();
			}
		}
	}
	private: System::Void PixelWidth_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (PixelWidth->Text == "" || PixelWidth->Text == ".")
		{
			PixelWidth->Text = "1";
		}
	}
	private: System::Void PixelWidth_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar != '\b' && e->KeyChar != '.')
		{
			e->Handled = !Char::IsDigit(e->KeyChar);
		}
	}
private: System::Void FPosition_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
}
};
}
