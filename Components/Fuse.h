#pragma once
#include "Component.h"
#include"..//ApplicationManager.h"

class Fuse : public Component {

protected:
	ApplicationManager* pManager;

	string Nam_Of_Fuse = "Defult Switch";
	int Number_of_Fuse;
	double value_of_Fuse_Current = 0;
	bool isDamaged = false;

public:
	Fuse(GraphicsInfo* r_GfxInfo, string name, int number, bool state);
	virtual void Operate();//Calculates the volt on both terminals
	virtual void Draw(UI* pUI);	//Draws the switch 
	Fuse();

	void CheckLimit();

	void set_State(bool);
	bool stateisClosed();
	void set_name_Fuse(string newName);
	string get_name_Fuse();
	double get_value_Fuse();
	void set_Num_Fuse(int newNumber);
	double get_Num_Fuse();


	virtual ~Fuse();

};