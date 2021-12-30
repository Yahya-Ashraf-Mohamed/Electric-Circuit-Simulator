#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	

//Coordinates of cornerpoint 1
	X1 = m_pGfxInfo->PointsList[0].x;
	Y1 = m_pGfxInfo->PointsList[0].y;
//Coordinates of cornerpoint 2
	X2 = m_pGfxInfo->PointsList[1].x;
	Y2 = m_pGfxInfo->PointsList[1].y;
//Coordinates of Center point
	Cx = (X1 + X2) / 2;
	Cy = (Y1 + Y2) / 2;

}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}


bool Component::isInRegion(int x, int y) //, UI* pUI)
{

	if (x >= X1 && x <= X2)  //to do 
	{
		if (y >= Y1 && y <= Y2)
			return true;
		else
			return false;
	}
	else
		return false;
}

void Component::setSelect(bool isselected)
{
	isSelected = isselected;
}

bool Component::getSelect()
{
	return isSelected;
}

GraphicsInfo* Component::get_Comp_Graphics_Info() { return m_pGfxInfo; }

Component::~Component()
{}

