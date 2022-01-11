#pragma once
#include "Component.h"
#include "..//ApplicationManager.h"



class Bulb : public Component
{
private:
	double Internal_res;
	bool isTurnON;
	int bulb_num = 0;
public:
	// constructors
	Bulb();
	Bulb(GraphicsInfo* r_GfxInfo);
	Bulb(double in_res/*, bool state*/);

	// functions
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	void setInter_Resistance();
	double getInter_Resistance();

	//bool Display_Light();

	void set_state(bool NewState);

};
