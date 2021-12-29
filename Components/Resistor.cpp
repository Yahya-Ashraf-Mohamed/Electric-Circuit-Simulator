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
		// Num_Of_res = 1;
		Val_Of_res = 1;
	}
	Resistor::Resistor(string name, int number, double Value)		// Arg_constructor
	{
		Nam_Of_res = name;
		// Num_Of_res = number;
	}
	void Resistor ::set_name_resistor()
	{
		cout << "Enter the name of resistance. \n ";
		cin >> Nam_Of_res;
	}
	string get_name_resistor(string Nam_Of_res)
	{
		return Nam_Of_res;
	}
	void Resistor::set_value_resistor()	// limitations of resistance value
	{
		for (int i = 1; i < 3; i++)
		{
			double Value;
			cout << "Enter the value of resistance. \n";
			cin >> Value;
			if (Value > 0 && Value < 10000)
			{
				Val_Of_res = Value;
				break;
			}
			else
			{
				cout << "Out of Range. " << endl;
			}
		}
	}
	double Resistor::get_value_resistor()
	{
		return Val_Of_res;
	}

	Resistor::~Resistor()
	{
		cout << "Resistance is deconstructed. \n";
	}