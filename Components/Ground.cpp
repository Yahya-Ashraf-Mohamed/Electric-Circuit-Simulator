#include"Ground.h"

Ground::Ground(GraphicsInfo* r_GfxInfo, string name, int number) :Component(r_GfxInfo)
{
	this->Nam_Of_Ground = name;
	this->Number_of_Ground = number;
}

void Ground::Draw(UI* pUI)
{
	pUI->Draw_Ground(*m_pGfxInfo, isSelected); //update to draw resistor
}

void Ground::Operate() {}
Ground::Ground()
{
	Nam_Of_Ground = "Default Ground";

	//to do determine the number of Ground by templet class  think to put her or in action
	Number_of_Ground = 1;

}


void Ground::set_name_Ground(string newName)
{
	Nam_Of_Ground = newName;
}
string Ground::get_name_Ground()
{
	return Nam_Of_Ground;
}

double Ground::get_value_Ground()
{
	return value_of_Ground_voltage;
}

void Ground::set_Num_Ground(int newNumber)
{
	Number_of_Ground = newNumber;
}
double Ground::get_Num_Ground()
{
	return Number_of_Ground;
}


Ground::~Ground()
{}


