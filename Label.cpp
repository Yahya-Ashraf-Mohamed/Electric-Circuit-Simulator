#include "Label.h"


ApplicationManager* pManager = nullptr;
UI* pUI = pManager->GetUI();

//int Label::choose_option()
//{
//	pUI->PrintMsg("Do you want to label 1\ component or 2\ connection \n Enter a number : ");
//	string Choice;
//	Choice =  pUI->GetSrting();
//	int choice = stoi(Choice);
//	return choice;
//}
//void Label::label_comp(int choice)
//{
//	/*if (choice == 1)
//	{
//		pUI->PrintMsg("Enter the component number: \n");
//		string comp_num;
//		comp_num = pUI->GetSrting();
//		int comp_number = stoi(comp_num);
//		pcomp_num = &comp_number;
//
//		pUI->ClearStatusBar();
//
//		pUI->PrintMsg("Enter the component name: \n");
//		comp_new_name = pUI->GetSrting();
//		string* pcomp_name = &comp_new_name;
//		stoi(*pcomp_num) = *pcomp_name;
//		
//	}*/
//
//}

void Label::label()
{
	pManager->Label();

}