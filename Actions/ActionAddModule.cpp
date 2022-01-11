#include "ActionAddModule.h"


ActionAddModule::ActionAddModule(ApplicationManager* pApp) :Action(pApp)
{}

ActionAddModule::~ActionAddModule(void)
{}

void ActionAddModule::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding Module 1: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

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

		
		Module* pM = new Module(pGInfo);
		pManager->AddComponent(pM);

	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void ActionAddModule::Undo()
{}

void ActionAddModule::Redo()
{}

