#include "Component.h"
#include "..//ApplicationManager.h"


class Battery :public Component {
private:
	double Voltage_Of_Battery = 0;
	double Internal_Resistance_Of_Battery = 0;
	int Battery_Number = 0;

public:
	Battery();
	Battery(GraphicsInfo* r_GfxInfo, double Resistance, double Voltage);
	Battery(double newinter_voltage, double newinter_resistance);


	// functions
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Battery
	void setvoltage_Battery(UI* pUI);
	double getvoltage_Battery(UI* pUI);
	void setinternalrestistance_battery(UI* pUI);
	double getinternalrestistance_battery(UI* pUI);


};
