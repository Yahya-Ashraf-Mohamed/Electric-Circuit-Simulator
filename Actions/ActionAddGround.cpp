#pragma once
#include"ActionAddGround.h"
#include"..//ApplicationManager.h"
#include"..//Components/Ground.h"
ActionAddGround::ActionAddGround(ApplicationManager* pApp) : Action(pApp)
{}

ActionAddGround::~ActionAddGround(void)
{}

void ActionAddGround::Execute()
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

		Ground* pG = new Ground(pGInfo);
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
