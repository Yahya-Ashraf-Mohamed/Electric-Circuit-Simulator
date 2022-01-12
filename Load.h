#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "UI/UI.h"

class Load : public Action
{


public:


	Load(ApplicationManager* pApp);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

