#pragma once

#include "Component.h"
#include "..//ApplicationManager.h"


class Ground :public Component {
private:
	int Number_of_Ground = 0;
	double value_of_Ground_voltage = 0;

public:
	Ground(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Ground
	Ground();
	ApplicationManager* pManager = nullptr;
	//UI* pUI = pManager->GetUI();
};
