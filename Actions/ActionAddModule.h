#pragma once

#include "Action.h"
#include "..//Components/Module.h"

//Class responsible for adding a new resistor action
class ActionAddModule : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	string Nam_Of_Module = "Defult Module";
	int Num_Of_Module;
	double Val_Of_res = 1;

public:
	ActionAddModule(ApplicationManager* pApp);
	virtual ~ActionAddModule(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

