#pragma once
#include "Component.h"
#include "..//ApplicationManager.h"


class Bulb : public Component
{
private:
	double Internal_res;
	/*bool isTurn;
	int bulb_num = 0;*/
public:
	
	Bulb(GraphicsInfo* r_GfxInfo, double resistance);


	// functions
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	

};
