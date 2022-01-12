#include "Module.h"

Module::Module(GraphicsInfo* r_GfxInfo, string name, int number, double Value) :Component(r_GfxInfo)
{
	this->Nam_Of_Module = name;
	this->Num_Of_Module = number;
	this->Val_Of_res = Value;

}

void Module::Draw(UI* pUI)
{
	pUI->Draw_Module(*m_pGfxInfo, isSelected); //update to draw resistor
}

void Module::Operate() {}
Module::Module()
{
	Nam_Of_Module = "Default Module";

	//to do determine the number of modules by templet class  think to put her or in action
	Num_Of_Module = 1;

	set_value_Module(1);
}

Module::Module(string name, int number, double Value)		// Arg_constructor
{
	Nam_Of_Module = name;
	//to do check if the number exists before    think to put her or in action
	Num_Of_Module = number;
	set_value_Module(Value);
	
}
void Module::set_name_Module(string newName)
{
	Nam_Of_Module = newName;
}
string Module::get_name_Module()
{
	return Nam_Of_Module;
}

void Module::set_value_Module(double newValue)
{
	
	if (newValue > 0 && newValue < 10000)
	{
		Val_Of_res = newValue;
	}
	else
	{
		// to do tell user to insert another number
		Val_Of_res = 1;
	}
	Val_Of_res_eq = 1 / ((1 / (Val_Of_res + Val_Of_res)) + (1 / (Val_Of_res + Val_Of_res)));

}
double Module::get_value_Module()
{
	return Val_Of_res_eq;
}

void Module::set_Num_Module(int newNumber)
{
	Num_Of_Module = newNumber;
}
double Module::get_Num_Module()
{
	return Num_Of_Module;
}


Module::~Module()
{}

