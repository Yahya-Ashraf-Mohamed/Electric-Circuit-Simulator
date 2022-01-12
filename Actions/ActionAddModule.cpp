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
	
	//Getting the Name of module
	pUI->PrintMsg("Enter the Name of the Module");
	Nam_Of_Module = pUI->GetSrting();
	
	//Getting the ID number of module
	pUI->PrintMsg("Enter the ID of the Module");
	Num_Of_Module = stoi(pUI->GetSrting());

	//Getting the resistance of resestor
	pUI->PrintMsg("Enter the resistence for one resistor in the module:");
	Val_Of_res = stod(pUI->GetSrting());


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

		
		Module* pM = new Module(pGInfo, Nam_Of_Module, Num_Of_Module, Val_Of_res);
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

