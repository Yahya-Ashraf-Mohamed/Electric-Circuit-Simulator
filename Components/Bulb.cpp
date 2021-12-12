#include "Bulb.h"
#include <iostream>
#include<string.h>
using namespace std;


Bulb::Bulb(GraphicsInfo* r_GfxInfo):Component(r_GfxInfo)
{}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->Draw_Bulb(*m_pGfxInfo); //update to draw resistor

}

void Bulb::Operate(){}
	Bulb::Bulb()		// no arg constructor
	{
		Internal_res = 0;
		isTurn = false;
	}
	Bulb::Bulb(double in_res, bool state)		// arg constructor
	{
		Internal_res = in_res;
		isTurn = state;
	}
	// functions
	void Bulb::setInter_Resistance()
	{
		cout << "Enter the Internal Resistance: " << endl;
		cin >> Internal_res;
	}
	double Bulb::getInter_Resistance()
	{
		return Internal_res;
	}
	bool Bulb::Display_Light()
	{
			cout << "Turn on (y or n ) ? " << endl;
			char option = 'y';
			cin >> option;
			if (option == 'y' || option == 'Y')
				isTurn = true;
			else
				isTurn = false;
			return isTurn;
	}
