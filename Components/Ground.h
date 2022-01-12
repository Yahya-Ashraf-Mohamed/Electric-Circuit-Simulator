#pragma once

#include "Component.h"
#include "..//ApplicationManager.h"


class Ground :public Component {

public:
	Ground(GraphicsInfo* r_GfxInfo, string name, int number);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Ground
	Ground();
	ApplicationManager* pManager;
	//UI* pUI = pManager->GetUI();



	void set_name_Ground(string newName);
	string get_name_Ground();
	double get_value_Ground();
	void set_Num_Ground(int newNumber);	
	double get_Num_Ground();


	virtual ~Ground();

protected:
	string Nam_Of_Ground = "Defult Ground";
	int Number_of_Ground;
	const double value_of_Ground_voltage = 0;
};
