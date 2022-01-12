#pragma once
#include"ActionAddSwitch.h"

ActionAddSwitch::ActionAddSwitch(ApplicationManager* pApp) : Action(pApp)
{}

ActionAddSwitch::~ActionAddSwitch(void)
{}

void ActionAddSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding Switch: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Getting the Name of Switch
	pUI->PrintMsg("Enter the Name of the Switch");
	Nam_Of_Switch = pUI->GetSrting();

	//Getting the ID number of Switch
	pUI->PrintMsg("Enter the ID of the Switch");
	Number_of_Switch = stoi(pUI->GetSrting());

	//Getting the State of the Switch
	pUI->PrintMsg("Enter the State of the Switch [0] for closed [1] for open");
	isClosed = stoi(pUI->GetSrting());

	if (pUI->Check_Valid(Cx, Cy))
	{

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


		Switch* pS = new Switch(pGInfo, Nam_Of_Switch, Number_of_Switch, isClosed);
		pManager->AddComponent(pS);

	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}

