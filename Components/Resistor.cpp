#include "Resistor.h"

Resistor::Resistor(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Resistor::Draw(UI* pUI)
{
	pUI->Draw_Resistor(*m_pGfxInfo, isSelected); //update to draw resistor

}

void Resistor::Operate(){}
	Resistor::Resistor()
	{
		Nam_Of_res = "Default Ressistance";
		Val_Of_res = 1;
	}
	Resistor::Resistor(string name, double Value)		// Arg_constructor
	{
		Nam_Of_res = name;
		Val_Of_res = Value;
	}
	void Resistor ::set_label(string resistance_name)
	{
		Nam_Of_res = resistance_name;
	}
	string Resistor::get_label()
	{
		return Nam_Of_res;
	}
	/*void Resistor::set_value_resistor(double resistance)
	{
		Val_Of_res = resistance;
	}
	double Resistor::get_value_resistor()
	{
		return Val_Of_res;
	}*/

	void Resistor::load(string label, double value)
	{
		this->Val_Of_res = value;
		this->Nam_Of_res = label;
	}

	Component* Resistor::copy()
	{
		Resistor* pResistor = new Resistor;
		Component* pcomponent = pResistor;
		return pcomponent;
	}

	Resistor::~Resistor()
	{
		cout << "Resistance is deconstructed. \n";
	}
