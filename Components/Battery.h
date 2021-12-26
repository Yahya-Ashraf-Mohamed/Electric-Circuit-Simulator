#pragma once
#include "Component.h"
#include "..//ApplicationManager.h"

class Battery {
private:
	float power;
	float voltage;
	float max_energy;
	float current_energy;
	float required_energy;
	float current;
	int time;

	int number_of_Battery = 1;
	double value_of_Battery = 1;

public:
	Battery();
	void Get_Energy(float currentenergy, float maxenergy, float voltage);
	void Power_Device(float current, float volatge, int time);
	void Max_Time(float current, float voltage, int time);


	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Battery
	ApplicationManager* pManager = nullptr;
	UI* pUI = pManager->GetUI();
	Battery(string m_label, int number, double value);
	void set_value_of_the_battery(UI* pUI) const;
	double get_value_of_the_battery(double value_of_Battery);
	void set_name_of_the_battery();
	string get_name_of_the_battery();
};