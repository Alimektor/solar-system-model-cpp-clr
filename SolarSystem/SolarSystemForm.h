#pragma once
#include "Coordinate.h"
#include "TBody.h"

namespace SolarSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// —водка дл€ SolarSystemForm
	/// </summary>
	public ref class SolarSystemForm : public System::Windows::Forms::Form
	{
	public:
		SolarSystemForm(void)
		{
			InitializeComponent();
		}

		TBody^ sun;
		bool not_clicked;
	protected: System::Windows::Forms::TrackBar^  sizeTrackBar;
	protected: System::Windows::Forms::TrackBar^  radiusTrackBar;
	private: System::Windows::Forms::Label^  RadiusLabel;
	protected:
	private: System::Windows::Forms::Label^  SizeLabel;
	public:
	protected: System::Windows::Forms::Timer^  TimerSS;
	public:
		

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SolarSystemForm()
		{
			if (components)
			{
				delete components;
			}
		}
	internal:
		System::Windows::Forms::Button^  RunButton;
	protected:
		
	private:
		System::Windows::Forms::PictureBox^  PictureBox;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->TimerSS = (gcnew System::Windows::Forms::Timer(this->components));
			this->sizeTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->radiusTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->RadiusLabel = (gcnew System::Windows::Forms::Label());
			this->SizeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radiusTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// RunButton
			// 
			this->RunButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->RunButton->Location = System::Drawing::Point(335, 724);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(80, 25);
			this->RunButton->TabIndex = 0;
			this->RunButton->Text = L"Start";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &SolarSystemForm::RunButton_Click);
			// 
			// PictureBox
			// 
			this->PictureBox->Location = System::Drawing::Point(12, 12);
			this->PictureBox->Name = L"PictureBox";
			this->PictureBox->Size = System::Drawing::Size(700, 700);
			this->PictureBox->TabIndex = 1;
			this->PictureBox->TabStop = false;
			this->PictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SolarSystemForm::PictureBox_Paint);
			// 
			// TimerSS
			// 
			this->TimerSS->Tick += gcnew System::EventHandler(this, &SolarSystemForm::TimerSS_Tick);
			// 
			// sizeTrackBar
			// 
			this->sizeTrackBar->LargeChange = 2;
			this->sizeTrackBar->Location = System::Drawing::Point(608, 718);
			this->sizeTrackBar->Maximum = 5;
			this->sizeTrackBar->Minimum = 1;
			this->sizeTrackBar->Name = L"sizeTrackBar";
			this->sizeTrackBar->Size = System::Drawing::Size(104, 45);
			this->sizeTrackBar->TabIndex = 2;
			this->sizeTrackBar->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->sizeTrackBar->Value = 1;
			this->sizeTrackBar->Scroll += gcnew System::EventHandler(this, &SolarSystemForm::sizeTrackBar_Scroll);
			// 
			// radiusTrackBar
			// 
			this->radiusTrackBar->LargeChange = 2;
			this->radiusTrackBar->Location = System::Drawing::Point(12, 718);
			this->radiusTrackBar->Maximum = 5;
			this->radiusTrackBar->Minimum = 1;
			this->radiusTrackBar->Name = L"radiusTrackBar";
			this->radiusTrackBar->Size = System::Drawing::Size(104, 45);
			this->radiusTrackBar->TabIndex = 3;
			this->radiusTrackBar->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->radiusTrackBar->Value = 1;
			this->radiusTrackBar->Scroll += gcnew System::EventHandler(this, &SolarSystemForm::radiusTrackBar_Scroll);
			// 
			// RadiusLabel
			// 
			this->RadiusLabel->AutoSize = true;
			this->RadiusLabel->Location = System::Drawing::Point(42, 743);
			this->RadiusLabel->Name = L"RadiusLabel";
			this->RadiusLabel->Size = System::Drawing::Size(41, 13);
			this->RadiusLabel->TabIndex = 4;
			this->RadiusLabel->Text = L"Radius";
			// 
			// SizeLabel
			// 
			this->SizeLabel->AutoSize = true;
			this->SizeLabel->Location = System::Drawing::Point(644, 743);
			this->SizeLabel->Name = L"SizeLabel";
			this->SizeLabel->Size = System::Drawing::Size(27, 13);
			this->SizeLabel->TabIndex = 5;
			this->SizeLabel->Text = L"Size";
			// 
			// SolarSystemForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 765);
			this->Controls->Add(this->SizeLabel);
			this->Controls->Add(this->RadiusLabel);
			this->Controls->Add(this->radiusTrackBar);
			this->Controls->Add(this->sizeTrackBar);
			this->Controls->Add(this->PictureBox);
			this->Controls->Add(this->RunButton);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"SolarSystemForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Solar System Model";
			this->Load += gcnew System::EventHandler(this, &SolarSystemForm::SolarSystemForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radiusTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void PictureBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
		System::Void RunButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void SolarSystemForm_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void TimerSS_Tick(System::Object^  sender, System::EventArgs^  e);
		System::Void sizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void radiusTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);
};
}

