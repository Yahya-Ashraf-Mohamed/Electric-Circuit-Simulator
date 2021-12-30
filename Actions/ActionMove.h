#pragma once
#include "Action.h"
#include "..//ApplicationManager.h"
#include "..//Components/Component.h"
#include "Select.h"

class ActionMove : public Action
{
private:
	
	UI* pUI = nullptr;
	window* pWind = nullptr;
	//Action* pAct = new Select(this);
	//Select* pSelect = nullptr;
	Component* MoveComp;

public:
	ActionMove(ApplicationManager* pApp); //Constructor
	virtual ~ActionMove(void); //Destructor

	//Component* Get_Selected_Comp();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

