#pragma once
#include "ApplicationManager.h"
#include <string>

class Label : public Component
{
private:
	string comp_name;
	UI* pUI = nullptr;
	/*window* pWind = nullptr;*/
	//Action* pAct = new Select(this);
	//Component* choosen_component;

public:
	Label();
	Label(ApplicationManager* pApp); //Constructor
	virtual ~Label(); //Destructor

	//Component* Get_Selected_Comp();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
