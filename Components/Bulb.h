#pragma once
#include "Component.h"
#include<string.h>
using namespace std;



class Bulb : public Component
{
private:
	double Internal_res;
	bool isTurn;
public:
	// constructors
	Bulb();
	Bulb(GraphicsInfo* r_GfxInfo);
	Bulb(double in_res, bool state);

	// functions
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	void setInter_Resistance();
	double getInter_Resistance();

	bool Display_Light();

};