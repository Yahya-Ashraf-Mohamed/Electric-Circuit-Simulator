#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo, double resistance) :Component(r_GfxInfo)
{
	this->Internal_res = resistance;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->Draw_Bulb(*m_pGfxInfo, isSelected, false); //update to draw resistor

}

void Bulb::Operate() {}

