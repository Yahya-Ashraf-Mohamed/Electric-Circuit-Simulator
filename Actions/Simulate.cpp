#include "Simulate.h"


Simulate::Simulate(ApplicationManager* pApp) :Action(pApp)
{
	//Get a Pointer to the user Interfaces
	pUI = pManager->GetUI();
	
	pUI->ClearStatusBar();

	//Print Action Message
	pUI->PrintMsg("Simulation has Started");

}

Simulate::~Simulate(void)
{}

void Simulate::Execute()
{
	bool simulation = true;

	// Circuit Validation. 
	if (pManager->is_1_Ground_present() == false)
	{
		pUI->PrintMsg("Error! One ground only should be placed");
		
	}
	else //to do the rest of cuircuit validation
	{

	}


	// Start simulation
	if (isCircuit_Valid == true)
	{
		while (simulation = true)
		{

			pManager->GetUI()->GetPointClicked(Selected_X, Selected_y);

			Component* Switch = pManager->getSwitch(Selected_X, Selected_y);
			if (Switch != nullptr)
			{
				if (Switch->get_state() == true)
					Switch->set_state(false);
				else
					Switch->set_state(true);

				pUI->PrintMsg("Switch state has changed");
			}

			pManager->GetUI()->ClearStatusBar();

			if (pManager->is_All_Switchs_Closed())			//to do check all switches are closed
			{
				pManager->Turn_Lamp_on();		//loop for lamps to turn on
				//pUI->GetpWind()->PlaySound("Buzzer_Sound.MP3", Null, SND_SYNC)			//buzzer emit sound
			}
		}
	}


}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

