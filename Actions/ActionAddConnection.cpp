//#include "ActionAddConnection.h"
//
//Connection::Connection(ApplicationManager* pApp) :Action(pApp)
//{
//	pUI = pManager->GetUI();
//	pUI->ClearStatusBar();
//}
//
//Connection::~Connection(void)
//{
//	
//}
//
//void Connection::Execute()
//{
//	pManager->UnSelectedComp();
//	pUI->PrintMsg("Please Select First component to connect");
//	Select* pSelect = nullptr;
//	pSelect->Execute();
//
//	//if (pManager->is_one_Comp_selected() == false)
//	//{
//	//	pUI->PrintMsg("One componen must be selected Only!");
//	//	return;
//	//}
//
//	Comp1 = pManager->get_selected_Component();
//
//
//	pUI->PrintMsg("Please Select Second component to connect");
//	pManager->UnSelectedComp();
//	pSelect->Execute();
//	Comp2 = pManager->get_selected_Component();
//
//	if (Comp1 == nullptr)
//	{
//		pUI->PrintMsg("First Component is not Selected");
//		return;
//	}
//	else if (Comp1 == nullptr)
//	{
//		pUI->PrintMsg("Second Component is not Selected");
//		return;
//	}
//
//
//	//pUI->GetPointClicked(Selected_X, Selected_y);
//	//if (Selected_y < pUI->getWindowHeight() - pUI->getStatusBarHeight() && Selected_y > pUI->getToolBarHeight())
//	//	pUI->ClearStatusBar();
//	//else
//	//{
//	//	pUI->PrintMsg("Please Select the Component from design area only!");
//	//}
//
//	//selected_Component = pManager->Get_Component_By_Coordinates(Selected_X, Selected_y);
//	//if (selected_Component == nullptr)
//	//{
//	//	this->unselect_All();
//	//}
//}
//
//void Connection::Undo()
//{
//
//}
//
//void Connection::Redo()
//{
//
//}
//
