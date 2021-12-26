#pragma once

#include "Action.h"
#include "..//Components/Component.h"
#include "..\ApplicationManager.h"


class Select : public Action
{
private:
	
	int Selected_X, Selected_y;	//Clicked pointes

	UI* pUI;

	int Componentcount;
	int ConnectionCount;
//todo
	Component** ComponentList;
	Connection** ConnectionList;


public:
	Select(ApplicationManager* pApp); //Constructor
	virtual ~Select(void); //Destructor

	Component* Select_Component(int x, int y);

	Connection* Select_Connection(int x, int y);

	void unselect();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


/*#pragma once
#include "..//Components/Component.h"
#include "..//Actions/Action.h"
#include "..\ApplicationManager.h"

class Select : public Action
{
public:
	Select(ApplicationManager* pApp);

	virtual ~Select(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

private:

};
*/