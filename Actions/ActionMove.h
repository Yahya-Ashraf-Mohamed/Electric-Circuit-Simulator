#pragma once
#include "Action.h"
#include "..//ApplicationManager.h"
#include "..//Components/Component.h"
#include "Select.h"

class ActionMove : public Action
{
private:
	
	UI* pUI;

	window Window;
	//Select* pSelect;

public:
	ActionMove(ApplicationManager* pApp); //Constructor
	virtual ~ActionMove(void); //Destructor


	void Mouse_Drag(window& testWindow);

	//Component* Get_Selected_Comp();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

