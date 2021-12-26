#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\ActionAddRes.h"
#include "Actions/ActionAddBulb.h"
#include "Actions/ActionMove.h"
#include "Actions/Select.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200, MaxConnCount = 200 };	//Max no of Components	

private:
	int CompCount, ConnCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount]; //List of all Connections (Array of pointers)

	UI* pUI; //pointer to the UI


public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	//Gets componnent list
	Component** GetCompList();
	int GetCompCount();

	//Gets Connection List
	Connection* GetConnList();
	int GetConnCount();

	//is in resion return a pointer 
	//Component* Get_Component_By_Coordinates(int x, int y);

	//is in resion return a pointer 
	//Component* Get_Connection_By_Coordinates(int x, int y); // to do

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	
	//Adds a new connection to the list of connections
	void AddConnection(Connection* pConn);


	//destructor
	~ApplicationManager();
};

#endif