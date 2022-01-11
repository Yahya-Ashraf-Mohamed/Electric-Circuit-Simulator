#pragma once
#include "Component.h"
#include "..//ApplicationManager.h"


using namespace std;


class Module :public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

	Module();		// No_Arg Constructor

	Module(string name, int number, double Value);		// Arg_constructor

	void set_name_Module(string newName);
	string get_name_Module();
	void set_value_Module(double newValue);	
	double get_value_Module();
	void set_Num_Module(int newNumber);	// limitations of resistance value
	double get_Num_Module();


	virtual ~Module();

protected:
	string Nam_Of_Module = "Defult Module";
	int Num_Of_Module;
	double Val_Of_res = 1;
	// double Resis[];
	double Val_Of_res_eq=0;
};

