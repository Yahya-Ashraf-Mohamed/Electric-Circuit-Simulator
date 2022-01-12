#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo, double x) :Component(r_GfxInfo)
{
	this->Internal_res = x;
}


void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->Draw_Bulb(*m_pGfxInfo); //update to draw resistor

}

void Bulb::Operate() {}

Bulb::Bulb()		// no arg constructor
{
	Internal_res = 0;
	isTurn = false;
	this->bulb_num += 1;
}

//Bulb::Bulb(double Internal_res, bool isTurn)		// Arg constructor
//{
//	this -> Internal_res = Internal_res;
//	this -> isTurn = isTurn;
//	this->bulb_num += 1;
//}

// functions
void Bulb::setInter_Resistance()
{
	pUI->PrintMsg("Enter the Internal Resistance: \n");
	string internal_res = pUI->GetSrting();
	Internal_res = stoi(internal_res);
	pUI->ClearStatusBar();
}
double Bulb::getInter_Resistance()
{
	return Internal_res;
	pUI->ClearStatusBar();
}

bool Bulb::Display_Light()
{
	pUI->PrintMsg("Turn on (y or n ) ? ");
	string option;
	option = pUI->GetSrting();
	if (option == "y" || option == "Y")
		isTurn = true;
	else
		isTurn = false;
	return isTurn;
}

void Bulb::set_label(string name)
{
	bulb_name = name;
}

string Bulb::get_label()
{
	return bulb_name;
}

void Bulb::load(string label, double value)
{

	this->Internal_res = value;
	label = label;
}

