#pragma once
#include "Component.h"
#include"..//ApplicationManager.h"

class Switch : public Component {

protected:
	ApplicationManager* pManager;

	string Nam_Of_Switch = "Defult Switch";
	int Number_of_Switch;
	const double value_of_Switch_voltage = 0;
	bool isClosed = false;

public:
	Switch(GraphicsInfo* r_GfxInfo, string name, int number, bool state);
	virtual void Operate();//Calculates the volt on both terminals
	virtual void Draw(UI* pUI);	//Draws the switch 
	Switch();



	void set_State(bool);
	bool stateisClosed();
	void set_name_Switch(string newName);
	string get_name_Switch();
	double get_value_Switch();
	void set_Num_Switch(int newNumber);
	double get_Num_Switch();


	virtual ~Switch();	

};