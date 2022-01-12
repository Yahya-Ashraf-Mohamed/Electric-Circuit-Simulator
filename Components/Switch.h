#pragma once
#include "Component.h"
#include"..//ApplicationManager.h"
class Switch : public Component {
private:
	int switch_number = 0;
	double voltage_on_switch = 0;
	double internal_resistance = 0;
	double volt_on_term1 = 0;
	double volt_on_term2 = 0;
	bool state = false;
public:
	Switch(GraphicsInfo* m_GFxInfo);
	virtual void operate();//Calculates the volt on both terminals
	virtual void Draw(UI* pUI);	//Draws the switch 
	Switch();
	Switch(double newinter_voltage, double newinter_resistance);
	bool isturn(bool);
	ApplicationManager* pManager = nullptr;
	UI* pUI = pManager->GetUI();


};