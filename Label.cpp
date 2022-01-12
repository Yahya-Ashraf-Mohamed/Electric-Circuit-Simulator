#include "Label.h"
#include "ApplicationManager.h"
#include <string.h>


ApplicationManager* pManager = nullptr;
UI* pUI = pManager->GetUI();

//void Label::label()
//{
//
//}

Label::Label(ApplicationManager* pApp) : Component()
{
    ApplicationManager* pManager = nullptr;
    UI* pUI = pManager->GetUI();

}



//Component* ActionMove::Get_Selected_Comp() { return pSelect->GetSelected_Component(); }

void Label::Execute()
{
	//get selected coordinates send it to select and then get elected component then get its dimention then start to move 

	Select* pSelect = nullptr;

	if (pManager->is_one_Comp_selected() == false)
	{
		pUI->PrintMsg("One component must be selected Only!");
		return;
	}

	//choosen_component = pManager->get_selected_Component();
	Component* choosen_component = pManager-> component_type();

	//choosen_component->set_label(comp_name);	
	Resistor* pR = new Resistor;
	Bulb* pB = new Bulb;
	Battery* pBat = new Battery;
	//Switch* pS = new Switch;
	/*Ground* pG = new Ground;
	Fuse* pF = new Fuse;*/
	Buzzer* pBuz = new Buzzer;


	for (int i = 0; i < 6; i++)
	{
		if (choosen_component == pR)
		{
			pR->set_label(comp_name);
		}
		else if (choosen_component == pB)
		{
			pB->set_label(comp_name);
		}
		/*else if (choosen_component == pS)
		{
			pS->set_label(comp_name);
		}*/
		/*else if (choosen_component == pG)
		{
			pG->set_label(comp_name);
		}
		else if (choosen_component == pF)
		{
			pF->set_label(comp_name);
		}*/
		else if (choosen_component == pBuz)
		{
			pBuz->set_label(comp_name);
		}
		/*else if (choosen_component == pBat)
		{
			pBat->set_label(comp_name);
		}*/
	}
	
}

Label::~Label() {}
