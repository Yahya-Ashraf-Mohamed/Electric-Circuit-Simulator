#include "Connection.h"

Connection::Connection(GraphicsInfo *r_GfxInfo, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;

	//Coordinates of cornerpoint 1
	X1 = pGfxInfo->PointsList[0].x;
	Y1 = pGfxInfo->PointsList[0].y;
	//Coordinates of cornerpoint 2
	X2 = pGfxInfo->PointsList[1].x;
	Y2 = pGfxInfo->PointsList[1].y;
	//Coordinates of Center point
	Cx = (X1 + X2) / 2;
	Cy = (X1 + X2) / 2;

}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, *pGfxInfo, false);//getSelect());
}

bool Connection::isInRegion(int x, int y, UI* pUI)
{
	if (Cx >= X1 && Cx <= X2)  //to do 
	{
		if (Cy >= Y1 && Cy <= Y2)
			return true;
		else
			return false;
	}
	else
		return false;
}
 //Check if these points is in the component or not then draw the component selected

void Connection::setSelect(bool isselected) { }//isSelected = isselected; }

//bool Connection::getSelect() { return false; }
