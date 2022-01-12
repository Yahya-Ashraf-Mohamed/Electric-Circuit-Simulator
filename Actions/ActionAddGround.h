#pragma once

#include"..//ApplicationManager.h"
#include"..//Components/Ground.h"
class ActionAddGround : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	string Nam_Of_Ground = "Defult Module";
	int Number_of_Ground;
	const double value_of_Ground_voltage = 0;

public:
	ActionAddGround(ApplicationManager* pApp);
	virtual ~ActionAddGround(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

