#pragma once
#include"Fuse.h"
//calling apointer to get the point in the Graphics information of the Fuse//

Fuse::Fuse(GraphicsInfo* r_GfxInfo, string name, int number, bool state) : Component(r_GfxInfo)
{
	this->Nam_Of_Fuse = name;
	this->Number_of_Fuse = number;
	this->isDamaged = state;
}

void Fuse::Draw(UI* pUI)
{
	pUI->Draw_Fuse(*m_pGfxInfo, isSelected, isDamaged); //update to draw resistor
}

void Fuse::set_State(bool state)
{
	isClosed = state;
}

bool Fuse::stateisClosed()
{
	return isClosed;
}


void Fuse::Operate() {}
Fuse::Fuse()
{
	Nam_Of_Fuse = "Default Fuse";

	//to do determine the number of Fuse by templet class  think to put her or in action
	Number_of_Fuse = 1;

}

void Fuse::CheckLimit()
{
	if (value_of_Fuse_Current > 100)
		isDamaged = true;
}

void Fuse::set_name_Fuse(string newName)
{
	Nam_Of_Fuse = newName;
}
string Fuse::get_name_Fuse()
{
	return Nam_Of_Fuse;
}

double Fuse::get_value_Fuse()
{
	return value_of_Fuse_Current;
}

void Fuse::set_Num_Fuse(int newNumber)
{
	Number_of_Fuse = newNumber;
}
double Fuse::get_Num_Fuse()
{
	return Number_of_Fuse;
}


Fuse::~Fuse()
{}


