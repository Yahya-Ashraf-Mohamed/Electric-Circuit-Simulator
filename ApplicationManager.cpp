#include "ApplicationManager.h"

//to open :)
template <class T>
int WhatType(T* t) { return 0; } // if the type of the pointer was any thing except what I want it do nothing

template <>
int WhatType(Module* t) { return TypeModule; }	// if the type of the pointer was module so it returns module  

template <>  //to to just enter class ground and it will work
int WhatType(Ground* t) { return TypeGround; }	// if the type of the pointer was module so it returns module  

template <class Resistor>
int WhatType(Resistor* t) { return TypeResistor; }

template <class Bulb>
int WhatType(Bulb* t) { return TypeBulb; }

template <class Buzzer>
int WhatType(Buzzer* t) { return TypeBuzzer; }


//template <>
//int WhatType(Switch* t) { return TypeSwitch; }	// if the type of the pointer was module so it returns module

//template <>
//int WhatType(Fuse* t) { return TypeFuse; }

template <class Battery>
int WhatType(Battery* t) { return TypeBattery; }

//template <>  //to to just enter class ground and it will work
//int WhatType(Ground* t) { return TypeGround; }	// if the type of the pointer was module so it returns module  

//template <>
//int WhatType(Switch* t) { return TypeSwitch; }	// if the type of the pointer was module so it returns module


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::getSwitch(int x, int y)
{
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->isInRegion(x, y))
			{
				if (WhatType(CompList[i]) == TypeSwitch)
					return CompList[i];
				else
					return nullptr;
			}
		}
		return nullptr;
	}
}
////////////////////////////////////////////////////////////////////

bool ApplicationManager::is_All_Switchs_Closed()
{
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (WhatType(CompList[i]) == TypeSwitch)
			{
				//Check if CompList[i] (switch) is open
				//return false;
			}
		}
		
		return true;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::Turn_Lamp_on()
{
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (WhatType(CompList[i]) == TypeLamp)
			{
				CompList[i]->set_is_closed(true);
			}
		}
	}

}

////////////////////////////////////////////////////////////////////
int ApplicationManager::get_Module_count()
{
	
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (WhatType(CompList[i]) == TypeModule)
			{
				ModuleCount = ModuleCount + 1;
			}
		}
		return ModuleCount;
	}
	return 0;
}

bool ApplicationManager::is_1_Ground_present()
{
	int countGround = 0;

	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (WhatType(CompList[i]) == TypeGround)
			{
				countGround = countGround + 1;
			}
		}
		
	}
	if (countGround == 1)
		return true;
	else
		return false;
}


ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

Component** ApplicationManager::GetCompList() 
{
	return CompList;
}

int ApplicationManager::GetCompCount()
{
	return CompCount;
}


Connection* ApplicationManager::GetConnList()
{
	return *ConnList;
}

int ApplicationManager::GetConnCount()
{
	return ConnCount;
}

void ApplicationManager::UnSelectedComp()
{
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			CompList[i]->setSelect(false);
			CompList[i]->Draw(pUI);
		}
	}
}

bool ApplicationManager::is_one_Comp_selected()
{
	int count = 0;

	for (int j = 0; j < CompCount; j++)
	{
		if (CompList[j]->getSelect() == true)
		{
			count = count + 1;
		}
	}
	if (count != 1)
		return false;
	else
		return true;
}


//bool ApplicationManager::is_Two_Comp_selected()
//{
//	int count = 0;
//
//	for (int j = 0; j < CompCount; j++)
//	{
//		if (CompList[j]->getSelect() == true)
//		{
//			count = count + 1;
//		}
//	}
//	if (count != 2)
//		return false;
//	else
//		return true;
//}

Component* ApplicationManager::get_selected_Component()
{
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->getSelect() == true)
			{
				return CompList[i];
			}
		}
		return nullptr;
	}
}






Component* ApplicationManager::Get_Component_By_Coordinates(int x, int y) {

	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->isInRegion(x, y))
			{
				if (CompList[i]->getSelect()==false)
				{
					CompList[i]->setSelect(true);
					CompList[i]->Draw(pUI);
					return CompList[i];
				}
				else
				{
					CompList[i]->setSelect(false);
					CompList[i]->Draw(pUI);
					return CompList[i];       // to be corrected soon
				}
			}
		}
		return nullptr;
	}
}


Connection* ApplicationManager::Get_Connection_By_Coordinates(int x, int y) {

	//if (ConnList != nullptr)
	//{
	//	for (int i = 0; i < ConnCount; i++)
	//	{
	//		if (ConnList[i]->isInRegion(x, y))
	//		{
	//			ConnList[i]->setSelect(true);
	//			ConnList[i]->Draw(pUI);
	//			return ConnList[i];
	//		}
	//	}
	//	return nullptr;
	//}
	return nullptr;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case Add_Bulb:
			pAct = new ActionAddBulb(this);
			break;
		
		case Add_Switch:
			pAct = new ActionAddSwitch(this);
			break;
		case Add_Battery:
			pAct = new ActionAddBattery(this);
			break;
		case Add_Ground:
			pAct = new ActionAddGround(this);
			break;
		case Add_Buzzer:
			//pAct = new ActionAddBuz(this);
			break;
		case Add_Fuse:
			pAct = new ActionAddFuse(this);
			break;
		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
		//	pAct = new ActionAddRes(this);
			break;
		case Add_Module_1:
			pAct = new ActionAddModule(this);
			break;
		case ADD_Label:
		//	pAct = new ActionAddRes(this);
			break;
		case EDIT_Label:
		//	pAct = new ActionAddRes(this);
			break;
		case Change_Switch:
//			pAct = new ActionAddRes(this);
			break;
		case Intensity:
			//	pAct = new ActionAddRes(this);
			break;
		case Voltage:
			//			pAct = new ActionAddRes(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case DEL:
		//	pAct = new ActionAddRes(this);
			break;
		case MOVE:
			pAct = new ActionMove(this);
			break;
		case SAVE:
		//	pAct = new ActionAddRes(this);
			break;
		case LOAD:
		//	pAct = new ActionAddRes(this);
			break;
		case UNDO:
		//	pAct = new ActionAddRes(this);
			break;
		case REDO:
		//	pAct = new ActionAddRes(this);
			break;
		case DSN_MODE:
			pAct = new SwitchToDisMood(this);
			break;
		case SIM_MODE:
			pAct = new SwitchToSimMood(this);
			break;
		case Start_Simulation:
			pAct = new Simulate(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

//Function updates the user interface
void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++) // Loop for drawing each component drowen in design area one by one
			CompList[i]->Draw(pUI);
		for (int i = 0; i < ConnCount; i++) // Loop for drawing each component drowen in design area one by one
			ConnList[i]->Draw(pUI);


		if (pUI->GetAppMode() == SIMULATION)
		{
			pUI->CreateSimulationToolBar();    // Updates the Simulation tool bar
		}
		else
		{
			pUI->CreateDesignToolBar();    // Updates the design tool bar
		}
		
		pUI->CreateStatusBar();
		

}

////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateDrawingArea()
{
	for (int i = 0; i < CompCount; i++) // Loop for drawing each component drowen in design area one by one
		CompList[i]->Draw(pUI);
	for (int i = 0; i < ConnCount; i++) // Loop for drawing each component drowen in design area one by one
		ConnList[i]->Draw(pUI);

}


////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

GraphicsInfo* ApplicationManager::point(int Cx , int Cy, int graphics_x, int graphics_y)
{
	GraphicsInfo* pGInfo = new GraphicsInfo(2);
	pGInfo->PointsList[0].x = Cx - graphics_x / 2;
	pGInfo->PointsList[0].y = Cy - graphics_y / 2;
	pGInfo->PointsList[1].x = Cx + graphics_x / 2;
	pGInfo->PointsList[1].y = Cy + graphics_y / 2;

	return pGInfo;
}




void ApplicationManager::Load(ifstream& myfile, string Load_File_Name)
{
	myfile.open(Load_File_Name);
	if (!myfile)
	{
		pUI->PrintMsg("This file doesn't exist.\n Try load again.");
	}
	else
	{

		string name; int id; string label; double value; int graphics_x; int graphics_y , int Cx , int  Cy;
		int num_of_components;
		myfile >> num_of_components;
		for (int i = 0; i < num_of_components; i++)
		{
			myfile >> name;
			myfile >> id;
			myfile >> label;
			myfile >> value;
			myfile >> graphics_x;
			myfile >> graphics_y;

			if (name == "RES")
			{
				Resistor* pR = new Resistor;
				pR->load(name, value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Resistor* pR = new Resistor(pGInfo);
			}
			/*else if (name == "SWT")
			{
				Switch* pS = new Switch;
				pS -> load(name,value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Switch* pS = new Switch (pGInfo);

			}*/
			/*else if (name == "BAT")
			{
				Battery* pB = new Battery;
				pB-> load (name,value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Battery* pBat = new Battery(pGInfo);

			}*/
			else if (name == "BLb")
			{
				Bulb* pBulb = new Bulb;
				pBulb->load(label, value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Bulb* pB = new Bulb(pGInfo);
			}
			else if (name == "GND")
			{
				/*Ground* pGround = new Ground;
				pGround->load(label, value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Ground* pG = new Ground(pGInfo);
				
				*/
			}
			else if (name == "BUZ")
			{
				Buzzer* pBuzzer = new Buzzer;
				pBuzzer->load(label, value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Buzzer* pB = new Buzzer(pGInfo);
			}
			else if (name == "FUS")
			{
				/*Fuse* pFuse = new Fuse;
				pFuse->load(label, value);
				pUI->GetPointClicked(Cx, Cy);
				GraphicsInfo* pGInfo = point(Cx, Cy, graphics_x, graphics_y);
				Fuse* pB = new Fuse(pGInfo);
				
				*/
			}

		}
		/*string none_name;
		myfile >> none_name;
		int num_of_connections;
		for (int i = 0; i < num_of_connections; i++)
		{

		}*/
	}





}

void ApplicationManager::Label()
{
	
	Select* pselect = nullptr;
	pUI->PrintMsg("Select the component:  ");
	pselect -> GetSelected_Component();
	pUI->ClearStatusBar();
	component_type();
	delete pselect;
	pselect = nullptr;

}

void ApplicationManager::Edit()
{
	Select* pSelect = nullptr;
	pUI->PrintMsg("Select the component:  ");
	pSelect->GetSelected_Component();
	pUI->ClearStatusBar();
	component_type();
	delete pSelect;
	pSelect = nullptr;

}

Component* ApplicationManager::component_type()
{
	if (CompList != nullptr)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (WhatType(CompList[i]) == TypeResistor)
			{
				return CompList[i];
			}
			else if (WhatType(CompList[i]) == TypeBulb)
			{
				return CompList[i];
			}
			else if (WhatType(CompList[i]) == TypeBuzzer)
			{
				return CompList[i];
			}
			/*else if (WhatType(CompList[i]) == TypeFuse)
			{
				return CompList[i];
			}*/
			else if (WhatType(CompList[i]) == TypeBattery)
			{
				return CompList[i];
			}
		}
		return nullptr;

	}
}





ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}
