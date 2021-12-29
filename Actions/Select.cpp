#include "Select.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
	pManager->GetUI()->PrintMsg("Click on the component to select");
	pManager->GetUI()->GetPointClicked(Selected_X, Selected_y);
	pManager->GetUI()->ClearStatusBar();
}

Select::~Select(void)
{
}

void Select::Execute()
{

	selected_Component = pManager->Get_Component_By_Coordinates(Selected_X, Selected_y);
	if (selected_Component == nullptr)
	{
		this->unselect_All();
	}
	//else
	//{ 
	//	//if (pManager->isCompSelected(selected_Component) == false)
	//		selected_Component->setSelect(true);
	//		
	//}

}
Component* Select::GetSelected_Component()

{
	return selected_Component;
}

Connection* Select::GetSelected_Connection()
{
	return Selected_Connection;
}

void Select::unselect_All()
{
	pManager->UnSelectedComp();
	//selected_Component->setSelect(false);

	//delete selected_Component;
	//selected_Component = nullptr;

	//	for (int i = 0; i < Componentcount; i++)
//		ComponentList[i]->setSelect(false);
}

void Select::unselect(int I)
{
	selected_Component->setSelect(false);

	delete selected_Component;
	selected_Component = nullptr;

}

void Select::Undo()
{

}

void Select::Redo()
{

}

