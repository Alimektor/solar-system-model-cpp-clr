#include "SolarSystemForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SolarSystem::SolarSystemForm form;
	Application::Run(%form);

}

inline System::Void SolarSystem::SolarSystemForm::SolarSystemForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	not_clicked = true;

	sun = gcnew TBody(gcnew Coordinate(this->PictureBox->Width / 2, this->PictureBox->Height / 2),
		30, // size
		Color::Yellow // color
	);

	TBody^ mercury = gcnew TBody(
		sun, // center
		58, // radius
		-0.416, // rotation speed
		3, // size
		Color::Orange // color
	);

	TBody^ venus = gcnew TBody(
		sun, // center
		108, // radius
		0.416, // rotation speed
		5, // size
		Color::Aqua // color
	);

	TBody^ earth = gcnew TBody(
		sun, // center
		150, // radius
		0.1, // rotation speed
		6, // size
		Color::Green // color
	);

	TBody^ mars = gcnew TBody(
		sun, // center
		228, // radius
		-0.053, // rotation speed
		4, // size
		Color::Red // color
	);

	TBody^ moon = gcnew TBody(
		earth, // center
		15, // radius
		1.3, // rotation speed
		2, // size
		Color::White // color
	);

	TBody^ phobos = gcnew TBody(
		mars, // center
		7, // radius
		114.4, // rotation speed
		1, // size
		Color::Gray // color
	);

	TBody^ deimos = gcnew TBody(
		mars, // center
		12, // radius
		30.4, // rotation speed
		1, // size
		Color::Purple // color
	);

	sun->add_new_satellite(mercury);
	sun->add_new_satellite(venus);
	sun->add_new_satellite(earth);
	earth->add_new_satellite(moon);
	sun->add_new_satellite(mars);
	mars->add_new_satellite(phobos);
	mars->add_new_satellite(deimos);
}

inline System::Void SolarSystem::SolarSystemForm::PictureBox_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	Graphics^ graphics = e->Graphics;
	graphics->Clear(Color::Black);
	sun->draw(graphics);
}

inline System::Void SolarSystem::SolarSystemForm::RunButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (not_clicked)
	{

		TimerSS->Enabled = true;
		this->RunButton->Text = L"Stop";
		not_clicked = false;
	} 
	else
	{
		TimerSS->Enabled = false;
		this->RunButton->Text = L"Start";
		not_clicked = true;
	}
}

inline System::Void SolarSystem::SolarSystemForm::TimerSS_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	sun->rotate();
	this->PictureBox->Invalidate();
}

inline System::Void SolarSystem::SolarSystemForm::sizeTrackBar_Scroll(System::Object ^ sender, System::EventArgs ^ e)
{
	int coefficient = this->sizeTrackBar->Value;
	sun->change_size(coefficient);
	this->PictureBox->Invalidate();
}

inline System::Void SolarSystem::SolarSystemForm::radiusTrackBar_Scroll(System::Object ^ sender, System::EventArgs ^ e)
{
	int coefficient = this->radiusTrackBar->Value;
	sun->change_radius(coefficient);
	this->PictureBox->Invalidate();
}
