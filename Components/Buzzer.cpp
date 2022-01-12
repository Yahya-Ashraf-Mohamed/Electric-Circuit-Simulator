#include "Buzzer.h"


Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->Draw_Buzzer(*m_pGfxInfo, false); //update to draw resistor
}

ApplicationManager* pManager = nullptr;
UI* pUI = pManager->GetUI();

Buzzer::Buzzer(double in_resistance, bool IsOn)
{
	this->in_resistance = in_resistance;
	this->IsOn = IsOn;
}

void Buzzer::set_label(string Label)
{
	this->buzzer_label = Label;
}

string Buzzer::get_label()
{
	return buzzer_label;
}



void Buzzer::setinner_Resistance()
{
	pUI->PrintMsg("Enter The Inner Resistance: \n");
	string In_resistance = pUI->GetSrting();
	in_resistance = stoi(In_resistance);
	pUI->ClearStatusBar();
}
double Buzzer::getinner_Resistance()
{
	return in_resistance;
}

//bool Buzzer::Turned_on()
//{
//	
//}

void Buzzer::load(string label, double value)
{

	this->in_resistance = value;
	this->buzzer_label = label;
}

Component* Buzzer::copy()
{
	Buzzer* pBuzzer = new Buzzer;
	Component* pcomponent = pBuzzer;
	return pcomponent;
}

Buzzer::~Buzzer()
{}
