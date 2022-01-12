#include"Ground.h"
Ground::Ground(GraphicsInfo* r_GfxInfo) : Component(r_GfxInfo)
{
	UI* pUI = pManager->GetUI();
}
void Ground::Draw(UI* pUI)
{
	//Call output class and pass Ground drawing info to it.//
	pUI->Draw_Ground(*m_pGfxInfo, true); //update to draw Ground

}
Ground::Ground() {
	double value_of_Ground_voltage = 0;
	this->Number_of_Ground += 1;
}
void Ground::Operate() {};

