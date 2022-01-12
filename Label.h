#pragma once
#include "ApplicationManager.h"

class Label
{
private:
	int comp_num;
	int conn_num;
	int* pcomp_num = nullptr;
	string comp_new_name;
	string conn_new_name;

public:
	int choose_option();

	void label_comp(int choice);

	void label_conn(int choice);

	void label();

};

