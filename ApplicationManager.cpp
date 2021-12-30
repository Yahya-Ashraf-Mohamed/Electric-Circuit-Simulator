#include "ApplicationManager.h"


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

	if (ConnList != nullptr)
	{
		for (int i = 0; i < ConnCount; i++)
		{
			if (ConnList[i]->isInRegion(x, y))
			{
				ConnList[i]->setSelect(true);
				ConnList[i]->Draw(pUI);
				return ConnList[i];
			}
		}
		return nullptr;
	}
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
		//	pAct = new ActionAddRes(this);
			break;
		case Add_Battery:
		//	pAct = new ActionAddRes(this);
			break;
		case Add_Ground:
		//	pAct = new ActionAddRes(this);
			break;
		case Add_Buzzer:
		//	pAct = new ActionAddRes(this);
			break;
		case Add_Fuse:
		//	pAct = new ActionAddRes(this);
			break;
		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
		//	pAct = new ActionAddRes(this);
			break;
		case Add_Module_1:
			pAct = new ActionAddRes(this);
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
		//	pAct = new ActionAddRes(this);
			break;
		case SIM_MODE:
		//	pAct = new ActionAddRes(this);
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



////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}