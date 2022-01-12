#pragma once
#include "Component.h"
#include "..\ApplicationManager.h"

class Edit : public Component 
{
private:
	string edited_name;
public:

	Edit (ApplicationManager* pApp); //Constructor


	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	~Edit();
};


