#pragma once
class Battery {
private:
	float power;
	float voltage;
	float max_energy;
	float current_energy;
	float required_energy;
	float current;
	int time;
public:
	Battery();
	void Get_Energy(float currentenergy, float maxenergy, float voltage);
	void Power_Device(float current, float volatge, int time);
	void Max_Time(float current, float voltage, int time);

};