#include "Switch_to_Design_mood.h"

SwitchToDisMood::SwitchToDisMood(ApplicationManager* pApp) :Action(pApp)
{
	pUI = pManager->GetUI();
	pUI->PrintMsg("Switching to simulation mode");

}

SwitchToDisMood::~SwitchToDisMood(void)
{}

void SwitchToDisMood::Execute()
{
	pUI->ClearToolBar();
	pUI->SetAppMode(DESIGN);
	pUI->ClearStatusBar();

}


void SwitchToDisMood::Undo()
{

}

void SwitchToDisMood::Redo()
{

}
