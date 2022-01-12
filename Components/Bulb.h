#pragma once
#include "Component.h"
#include "../ApplicationManager.h"
class Bulb : public Component
{
private:
	double Internal_res;
	bool isTurn;
	int bulb_num = 0;
	string bulb_name;
public:
	// constructors
	Bulb();
	Bulb(GraphicsInfo* r_GfxInfo);
	Bulb(GraphicsInfo* r_GfxInfo, double internal);
	//Bulb(double in_res, bool state);
	ApplicationManager* pManager = nullptr;
	UI* pUI = pManager->GetUI();


	// functions
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	void setInter_Resistance();
	double getInter_Resistance();

	void set_label(string name);
	string get_label();

	bool Display_Light();

	void load(string label, double value);

	~Bulb();

};
