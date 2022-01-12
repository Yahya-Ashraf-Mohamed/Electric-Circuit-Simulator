#include "Select.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
	pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Click on the component to select");
	pUI->GetPointClicked(Selected_X, Selected_y);
	if (Selected_y < pUI->getWindowHeight() - pUI->getStatusBarHeight() && Selected_y > pUI->getToolBarHeight())
		pUI->ClearStatusBar();
	else
	{
		pUI->PrintMsg("Please Select the Component from design area only!");
	}

}

Select::~Select(void)
{
	delete selected_Component;
	selected_Component = nullptr;
}

void Select::Execute()
{

	selected_Component = pManager->Get_Component_By_Coordinates(Selected_X, Selected_y);
	if (selected_Component == nullptr)
	{
		this->unselect_All();
	}
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
	delete selected_Component;
	selected_Component = nullptr;
}

void Select::Undo()
{

}

void Select::Redo()
{

}

