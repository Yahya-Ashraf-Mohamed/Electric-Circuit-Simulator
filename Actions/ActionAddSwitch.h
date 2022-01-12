#pragma once
#include "ActionAddSwitch.h"
#include "..//ApplicationManager.h"
class ActionAddSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	double voltage_on_switch = 0;
	double internal_resistance = 0;
public:
	ActionAddSwitch(ApplicationManager* pApp);
	virtual ~ActionAddSwitch(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

