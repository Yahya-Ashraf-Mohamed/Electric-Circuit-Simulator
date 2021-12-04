#pragma once
#include "Component.h"

class Edit : public Component
{
private:
	string new_name_of_comp;
	string old_name_of_comp;
	string new_name_of_conn;
	string old_name_of_conn;
public:

	int choose_option();

	void the_comp_conn_changed(int choice);

	void the_edited_comp();

	void the_edited_conn();
};


