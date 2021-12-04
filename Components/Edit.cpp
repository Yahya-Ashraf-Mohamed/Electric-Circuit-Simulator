#include "Edit.h"
#include <iostream>
#include<string.h>
using namespace std;



	int Edit::choose_option()
	{
		cout << "Do you want to chnge the name of 1_Component OR 2_Connection \nEnter number :" << endl;
		int choice;
		cin >> choice;
		return choice;
	}
	void Edit::the_comp_conn_changed(int choice)
	{
		if (choice == 1)
		{
			cout << "Enter the name of the component: " << endl;
			cin >> old_name_of_comp;
		}
		else
		{
			cout << "Enter the name of the connection: " << endl;
			cin >> old_name_of_conn;
		}
	}

	void Edit::the_edited_comp()
	{
		cout << "Enter the new name of component : \n ";
		cin >> new_name_of_comp;

		old_name_of_comp = new_name_of_comp;

		cout << "the new name is : ";
		cout << old_name_of_comp;

	}
	void Edit::the_edited_conn()
	{
		cout << "Enter the new name of connection: \n";
		cin >> new_name_of_conn;

		old_name_of_conn = new_name_of_conn;
	}