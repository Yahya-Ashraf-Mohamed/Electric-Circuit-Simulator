#include "Battery.h"

Battery::Battery(GraphicsInfo* r_GfxInfo, double Resistance, double Voltage) : Component(r_GfxInfo)
{
	this->Internal_Resistance_Of_Battery = Resistance;
	this->Voltage_Of_Battery = Voltage;

}//calling apointer to get the point in the Graphics information of the Battery//

void Battery::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.//
	pUI->Draw_Battery(*m_pGfxInfo, isSelected);//ate to draw Battery

}
Battery::Battery()
{
	double Voltage_Of_Battery = 0;
	double Internal_Resistance_Of_Battery = 0;
	this->Battery_Number += 1;
}
//constructor with  argument// 
Battery::Battery(double newinter_voltage, double newinter_resistance)
{
	Voltage_Of_Battery = newinter_voltage;
	Internal_Resistance_Of_Battery = newinter_resistance;
	this->Battery_Number += 1;
}



void Battery::setvoltage_Battery(UI* pUI)
{
	pUI->PrintMsg("Enter the voltage of the Battery: \n");
	pUI->ClearStatusBar();
}

double Battery::getvoltage_Battery(UI* pUI) {
	return Voltage_Of_Battery;
	pUI->ClearStatusBar();
}
void Battery::setinternalrestistance_battery(UI* pUI) {
	pUI->PrintMsg("Enter the internal resistance of the battery:\n");
	pUI->GetSrting();
	pUI->ClearStatusBar();
}
double Battery::getinternalrestistance_battery(UI* pUI) {
	return Internal_Resistance_Of_Battery;
	pUI->ClearStatusBar();

}

void  Battery::Operate(){}