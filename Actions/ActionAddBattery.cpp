#pragma once
#include"ActionAddBattery.h"
#include"..//Components/Battery.h"

ActionAddBattery::ActionAddBattery(ApplicationManager* pApp) : Action(pApp)
{}

ActionAddBattery::~ActionAddBattery(void)
{}

void ActionAddBattery::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Battery: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Getting the resistence of the battery
	pUI->PrintMsg("Enter the resistence of the battery:");
	Internal_Resistance_Of_Battery = stod(pUI->GetSrting());

	//Getting the voltage of the battery
	pUI->PrintMsg("Enter the voltage of the battery");
	Voltage_Of_Battery = stod(pUI->GetSrting());



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
		//creating new objectof batterycomponent
		Battery* pb = new Battery(pGInfo, Voltage_Of_Battery, Internal_Resistance_Of_Battery);
		//Adding the new component
		pManager->AddComponent(pb);
	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}
}

void ActionAddBattery::Undo()
{}

void ActionAddBattery::Redo()
{}

