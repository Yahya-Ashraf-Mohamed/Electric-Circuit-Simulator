#include "Battery.h"
#include<iostream>

using namespace std;


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

