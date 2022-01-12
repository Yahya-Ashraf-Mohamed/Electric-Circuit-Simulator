#pragma once

#include"..//ApplicationManager.h"
#include"..//Components/Switch.h"

class ActionAddSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	string Nam_Of_Switch = "Defult Switch";
	int Number_of_Switch;
	const double value_of_Switch_voltage = 0;
	bool isClosed = false;

public:
	ActionAddSwitch(ApplicationManager* pApp);
	virtual ~ActionAddSwitch(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

