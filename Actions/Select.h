#pragma once

#include "Action.h"
#include "..//Components/Component.h"
#include "..\ApplicationManager.h"


class Select : public Action
{
private:
	
	int Selected_X, Selected_y;	//Clicked pointes

	UI* pUI;

	//int Num_Selected_Comp = 0;

	Component* selected_Component;

	Connection* Selected_Connection;


public:
	Select(ApplicationManager* pApp); //Constructor
	virtual ~Select(void); //Destructor


	Connection* GetSelected_Connection();

	Component* GetSelected_Component ();

	//Component** Select::All_Selected_Components();

	void unselect(int i);
	void unselect_All();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
