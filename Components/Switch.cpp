#pragma once
#include"Switch.h"
//calling apointer to get the point in the Graphics information of the Switch//

Switch::Switch(GraphicsInfo* r_GfxInfo, string name, int number, bool state) : Component(r_GfxInfo)
{
	this->Nam_Of_Switch = name;
	this->Number_of_Switch = number;
	this->isClosed = state;
}

void Switch::Draw(UI* pUI)
{
	pUI->Draw_Switch(*m_pGfxInfo, isSelected, isClosed); //update to draw resistor
}

void Switch::set_State(bool state)
{
	isClosed = state;
}

bool Switch::stateisClosed()
{
	return isClosed;
}


void Switch::Operate() {}
Switch::Switch()
{
	Nam_Of_Switch = "Default Switch";

	//to do determine the number of Switch by templet class  think to put her or in action
	Number_of_Switch = 1;

}


void Switch::set_name_Switch(string newName)
{
	Nam_Of_Switch = newName;
}
string Switch::get_name_Switch()
{
	return Nam_Of_Switch;
}

double Switch::get_value_Switch()
{
	return value_of_Switch_voltage;
}

void Switch::set_Num_Switch(int newNumber)
{
	Number_of_Switch = newNumber;
}
double Switch::get_Num_Switch()
{
	return Number_of_Switch;
}


Switch::~Switch()
{}


