#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"


class SwitchToSimMood : public Action
{
private:

	UI* pUI;

public:
	SwitchToSimMood(ApplicationManager* pApp); //Constructor
	virtual ~SwitchToSimMood(void); //Destructor


	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
