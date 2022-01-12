#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"


class SwitchToDisMood : public Action
{
private:

	UI* pUI;

public:
	SwitchToDisMood(ApplicationManager* pApp); //Constructor
	virtual ~SwitchToDisMood(void); //Destructor


	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
