#include "Edit.h"



ApplicationManager* pManager = nullptr;
UI* pUI = pManager->GetUI();

Edit::Edit(ApplicationManager* pApp) : Component() 
{
	pUI = pManager->GetUI();
}

void Edit::Execute()
{

	if (pManager->is_one_Comp_selected() == false)
	{
		pUI->PrintMsg("One component must be selected Only!");
		return;
	}
	Component* pcomp = nullptr;
	

}
