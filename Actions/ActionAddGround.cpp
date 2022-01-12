#pragma once
#include"ActionAddGround.h"

ActionAddGround::ActionAddGround(ApplicationManager* pApp) : Action(pApp)
{}

ActionAddGround::~ActionAddGround(void)
{}

void ActionAddGround::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding Ground: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Getting the Name of module
	pUI->PrintMsg("Enter the Name of the Ground");
	Nam_Of_Ground = pUI->GetSrting();

	//Getting the ID number of module
	pUI->PrintMsg("Enter the ID of the Ground");
	Number_of_Ground = stoi(pUI->GetSrting());

	
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


		Ground* pG = new Ground(pGInfo, Nam_Of_Ground, Number_of_Ground);
		pManager->AddComponent(pG);

	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void ActionAddGround::Undo()
{}

void ActionAddGround::Redo()
{}

