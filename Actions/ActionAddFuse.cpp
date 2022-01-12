#pragma once
#include"ActionAddFuse.h"

ActionAddFuse::ActionAddFuse(ApplicationManager* pApp) : Action(pApp)
{}

ActionAddFuse::~ActionAddFuse(void)
{}

void ActionAddFuse::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding Fuse: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Getting the Name of Fuse
	pUI->PrintMsg("Enter the Name of the Fuse");
	Nam_Of_Fuse = pUI->GetSrting();

	//Getting the ID number of Fuse
	pUI->PrintMsg("Enter the ID of the Fuse");
	Number_of_Fuse = stoi(pUI->GetSrting());


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


		Fuse* pF = new Fuse(pGInfo, Nam_Of_Fuse, Number_of_Fuse, isDamaged);
		pManager->AddComponent(pF);

	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void ActionAddFuse::Undo()
{}

void ActionAddFuse::Redo()
{}

