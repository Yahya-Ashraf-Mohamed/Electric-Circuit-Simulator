#pragma once

#include "Action.h"
#include "..//Components/Component.h"
#include "..//ApplicationManager.h"

//Class responsible for adding a new resistor action
class Simulate : public Action
{
private:

	int Selected_X, Selected_y;	//Clicked pointes

	UI* pUI;

	Component* selected_Component;

public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

