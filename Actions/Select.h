#pragma once

#include "Action.h"
#include "..//Components/Component.h"
#include "..\ApplicationManager.h"


class Select : public Action
{
private:
	
	int Selected_X, Selected_y;	//Clicked pointes

	UI* pUI;

	Component* selected_Component;

	Connection* Selected_Connection;

	//memoryleak

public:
	Select(ApplicationManager* pApp); //Constructor
	virtual ~Select(void); //Destructor


	Connection* GetSelected_Connection();

	Component* GetSelected_Component ();

	void unselect_All();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
