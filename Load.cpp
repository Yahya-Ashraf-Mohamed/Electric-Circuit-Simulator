#include "Load.h"
#include"fstream"

void Load::Execute()
{
	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("Enter the file name:  ");
	string File_Name = pUI->GetSrting() + "txt";
	ifstream myfile;

	//iostream myfile;
	pManager->Load( &myfile, File_Name);





}
