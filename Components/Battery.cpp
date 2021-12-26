#include "Battery.h"
#include<iostream>

using namespace std;
/*
//Battery::Battery(GraphicsInfo* r_GfxInfo) : Component(r_GfxInfo) //calling apointer to get the point in the Graphics information of the Battery//
//{}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.//
	//pUI->Draw_Battery(*m_pGfxInfo, true); //update to draw Battery

}

Battery::Battery() {
	float power = 0;
	float voltage = 0;
	float max_energy = 0;
	float current_energy = 0;
	float required_energy = 0;
	float current = 0;
	int time = 0;
}
//takkeing the components of energy ;
void Battery::Get_Energy(float newvalueofcurrentenergy, float newvalueofmaxenergy, float newvalueofvoltage) {
	current_energy = newvalueofcurrentenergy;
	max_energy = newvalueofmaxenergy;
	voltage = newvalueofvoltage;
}
//the power of the device to know when to close the circuit;
void Battery::Power_Device(float newvalueofcurrent, float newvalueofthevoltage, int newvalueoftime) {
	current = newvalueofcurrent;
	time = newvalueoftime;
	voltage = newvalueofthevoltage;


	power = voltage * current;
	required_energy = power * time;
	cout << "the power of the battery is:" << power;
}
void Battery::Max_Time(float newvalueoofthecurrent, float newvalueofthevoltage, int newvalueofthetime) {
	current = newvalueoofthecurrent;
	voltage = newvalueofthevoltage;
	time = newvalueofthetime;
	power = voltage * current;
	required_energy = power * time;
	float maximuumtime = required_energy / power;
	cout << "the lamp can be lighten for:" << maximuumtime;
}

*/