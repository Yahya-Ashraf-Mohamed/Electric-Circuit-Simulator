#include "Select.h"

Select::Select(ApplicationManager* pApp) :Action(pApp) 
{
	pUI = pApp->GetUI(); //Pointer to UI

	Componentcount = pApp->GetCompCount();
	ConnectionCount = pApp->GetConnCount();

//	for (int i = 0; i < Componentcount; i++) {
	//	ComponentList = pApp->GetCompList();
	//}
	ComponentList = pApp->GetCompList();
//	ConnectionList = pApp->GetConnList();
}

Select::~Select(void)
{
}

void Select::Execute()
{
	//Get the center point of the area where The component should selected
	pUI->GetClickLocation(Selected_X, Selected_y);

	//if this component is clicked it will be selected
	Component* selected_Component = Select_Component(Selected_X, Selected_y);

	//if this connection is clicked it will be selected
	//Connection* selected_Connection = Select_Connection(Selected_X, Selected_y);

}

Component* Select::Select_Component(int x, int y) 
{
	if (ComponentList != nullptr)
	{
		for (int i = 0; i < Componentcount; i++)
		{
			if (ComponentList[i]->isInRegion(x, y, pUI))
			{
				ComponentList[i]->setSelect(true);
				ComponentList[i]->Draw(pUI);
				return ComponentList[i];
			}
		}
		return nullptr;
	}

}

Connection* Select::Select_Connection(int x, int y) 
{
	if (ConnectionList != nullptr)
	{
		for (int i = 0; i < ConnectionCount; i++)
		{
			if (ConnectionList[i]->isInRegion(x, y, pUI))
			{
				ConnectionList[i]->setSelect(true);
				ConnectionList[i]->Draw(pUI);
				return ConnectionList[i];
			}
		}
		return nullptr;
		
	}
//	else
	//{
		//Select::unselect();
	//}

}

void Select::unselect() 
{
	for (int i = 0; i < Componentcount; i++)
		ComponentList[i]->setSelect(false);
	for (int j = 0; j < ConnectionCount; j++)
		ConnectionList[j]->setSelect(false);
}

void Select::Undo()
{

}

void Select::Redo()
{

}

/*
Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Component is selcted");

	//Get the pointes where the user clicked
	pUI->GetPointClicked(X, Y);

	Select* pSelect = nullptr;

	// pSelect must be equal to component pointer selected
	pManager->Get_Component_By_Coordinates(X, Y)->isInRegion(X, Y, pUI);


	//Clear Status Bar
//	pUI->ClearStatusBar();



	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = X - compWidth / 2;
		pGInfo->PointsList[0].y = Y - compHeight / 2;
		pGInfo->PointsList[1].x = X + compWidth / 2;
		pGInfo->PointsList[1].y = Y + compHeight / 2;

	//	Select* pSelected = new Select(pGInfo);  // pointer to the component selected
	//	pManager->AddComponent(pSelected);       // then draw it highlighted

	}



void Select::Undo()
{}

void Select::Redo()
{}





/*
#include "Select.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Component is selected");

	//Get Center point of the area where the Comp should be drawn
	/*
	pUI->GetPointClicked(Cx, Cy);

	if (pUI->Check_Valid(Cx, Cy))
	{

		//Clear Status Bar
		pUI->ClearStatusBar();



		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;

		Resistor* pR = new Resistor(pGInfo);
		pManager->AddComponent(pR);

	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void Select::Undo()
{}

void Select::Redo()
{}
*/
