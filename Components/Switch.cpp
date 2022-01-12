#pragma once
#include"Switch.h"
//calling apointer to get the point in the Graphics information of the Switch//
Switch::Switch(GraphicsInfo* m_GfxInfo) : Component(m_GfxInfo)
{}
//Call output class and pass Battery drawing info to it.//
void Switch::Draw(UI* pUI)
{

	pUI->Draw_Switch(*m_pGfxInfo, false, false);

}
//constructor
Switch::Switch() {
	double voltage_on_switch = 0;
	double internal_resistance = 0;;
	this->switch_number + 1;

}
/// constructor with arguments

Switch::Switch(double newinter_voltage, double newinter_resistance)
{
	voltage_on_switch = newinter_voltage;
	internal_resistance = newinter_resistance;
	this->switch_number += 1;
}
//state==false, in this condiction the switch is off and by that the circuit is opened
bool isturn(double voltage_on_switch, double volt_on_term2, double volt_on_term1, UI* pUI)
{
	if (bool state = false) {
		voltage_on_switch = 0;
		return voltage_on_switch;
	}
	else
	{
		voltage_on_switch = volt_on_term2 - volt_on_term1;
		return voltage_on_switch;
	}

}
void Switch::operate() {}


