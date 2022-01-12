#include "..//Actions/ActionAddSwitch.h"
#include"..//ApplicationManager.h"
#include"..//Components/Switch.h"
ActionAddSwitch::ActionAddSwitch(ApplicationManager* pApp) : Action(pApp)
{}

ActionAddSwitch::~ActionAddSwitch(void)
{}

void ActionAddSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Switch: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	if (pUI->Check_Valid(Cx, Cy) == true) {



		//Clear Status Bar
		pUI->ClearStatusBar();


		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;

		//creating new objectof switch component
		//Switch* pS = new Switch(pGInfo);
		//Adding the new component
		//pManager->AddComponent(pS);
	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}
