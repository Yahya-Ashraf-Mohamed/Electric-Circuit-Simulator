#include "Switch_to_Simulation_mood.h"

SwitchToSimMood::SwitchToSimMood(ApplicationManager* pApp) :Action(pApp)
{
	pUI = pManager->GetUI();
	pUI->PrintMsg("Switching to simulation mode");

}

SwitchToSimMood::~SwitchToSimMood(void)
{}

void SwitchToSimMood::Execute()
{
	pUI->ClearToolBar();
	pUI->SetAppMode(SIMULATION);
	pUI->ClearStatusBar();

}


void SwitchToSimMood::Undo()
{

}

void SwitchToSimMood::Redo()
{

}
