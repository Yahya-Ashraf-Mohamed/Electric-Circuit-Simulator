#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection 
{
private:

	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection

	int X1, Y1, X2, Y2;

protected:

	//bool isSelected = false;

public:
	Connection(GraphicsInfo *r_GfxInfo, Component *cmp1=nullptr, Component *cmp2=nullptr);

	virtual void Draw(UI* );	//for connection to Draw itself
	
	//bool isInRegion(int x, int y); //Check if these points is in the component or not then draw the component selected

	//void setSelect(bool isselect);

//	bool getSelect(); //return select true:false


};

