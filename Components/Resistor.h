#pragma once
#include "Component.h"
#include <string>
#include <iostream>
#include<string.h>
using namespace std;


class Resistor :public Component
{
public:
	Resistor(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

	Resistor();		// No_Arg Constructor

	Resistor(string name, int number, double Value);		// Arg_constructor

	void set_name_resistor();
	string get_name_resistor(string Nam_Of_res);
	void set_value_resistor();	// limitations of resistance value
	double get_value_resistor();



	virtual ~Resistor();


protected:
	string Nam_Of_res;
	// Num_Of_res;
	double Val_Of_res;
	// double Resis[];
};

