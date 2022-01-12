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
#include "Actions/ActionAddModule.h"
#include "Actions/Simulate.h"
#include "Actions/ActionAddSwitch.h"
#include "Actions/ActionAddBattery.h"
#include "Actions/ActionAddGround.h"
#include "Actions/Switch_to_Simulation_mood.h"
#include "Actions/Switch_to_Design_mood.h"
#include "Actions/ActionAddBuzzer.h"
#include "Actions/ActionAddFuse.h"





//Main class that manages everything in the application.



class ApplicationManager
{

	enum { MaxCompCount = 200, MaxConnCount = 200 };	//Max no of Components	

private:
	int CompCount, ConnCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount]; //List of all Connections (Array of pointers)

	int ModuleCount = 0;				//to do for all adds

	UI* pUI; //pointer to the UI


public:

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	void UpdateDrawingArea();

	//Gets a pointer to UI Object
	UI* GetUI();
	
	//Gets componnent list
	Component** GetCompList();
	int GetCompCount();

	//Gets Connection List
	Connection* GetConnList();
	int GetConnCount();

	//Check if the coponent was selected once before
	void UnSelectedComp();

	//Check if all components are unselected
	bool is_one_Comp_selected();
	//bool is_Two_Comp_selected();
	
	Component* get_selected_Component();

	//is in resion return a pointer
	Component* Get_Component_By_Coordinates(int x, int y);

	//is in resion return a pointer 
	Connection* Get_Connection_By_Coordinates(int x, int y); // to do

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	
	//Adds a new connection to the list of connections
	void AddConnection(Connection* pConn);

	//Check if this component a switch
	Component* getSwitch(int x, int y);

	//get number of modules
	int get_Module_count();

	bool is_1_Ground_present();


	bool is_All_Switchs_Closed(); //todo

	void Turn_Lamp_on();
	//destructor
	~ApplicationManager();
};

#endif