#pragma once
#include "..//ApplicationManager.h"
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

	Resistor(string name, double Value);		// Arg_constructor

	void set_label(string resistance_name);
	string get_label();

	void set_value_resistor(double resistance);	
	double get_value_resistor();


	void load(string label, double value);

	Component* copy();

	virtual ~Resistor();


protected:
	string Nam_Of_res;

	double Val_Of_res;

};



