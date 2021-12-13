#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Electric Circuit Simulator");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}


int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

// Function get App mode Design or simulation
MODE UI::GetAppMode()const 
{
	return AppMode;
}

void UI::GetClickLocation(int& x, int& y) {
	pWind->GetMouseClick(x, y);
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:						return ADD_RESISTOR;	//Item Resistor is clicked
			case ITM_Battery:					return Add_Battery;		//Item Battery is clicked
			case ITM_Switch:					return Add_Switch;		//Item Switch is clicked
			case ITM_Bulb:						return Add_Bulb;		//Item Bulb is clicked
			case ITM_Ground:					return Add_Ground;		//Item Ground is clicked
			case ITM_Buzzer:					return Add_Buzzer;		//Item Buzzer is clicked
			case ITM_Fuse:						return Add_Fuse;		//Item Fuse is clicked
			case ITM_ADD_CONNECTION:			return ADD_CONNECTION;	//Item Connection is clicked
			case Group_ChangeSwitch_And_Save:							
				if (y < ToolBarHeight / 2) {							//user clicked on the upper part of the image
					return Change_Switch;								//Item Change switch is clicked
				}
				else
				{
					return SAVE;										//Item Save is clicked
				}

			case Group_Select_And_Load:
				if (y < ToolBarHeight / 2) {							//user clicked on the upper part of the image
					return SELECT;										//Item Select is clicked
				}
				else
				{
					return LOAD;										//Item Load is clicked
				}

			case Group_Move_And_Undo:
				if (y < ToolBarHeight / 2) {							//user clicked on the upper part of the image
					return MOVE;										//Item Move is clicked
				}
				else
				{
					return UNDO;										//Item undo is clicked
				}

			case Group_Lable_And_Redo:
				if (y < ToolBarHeight / 2) {							//user clicked on the upper part of the image
					return ADD_Label;									//Item Add Lable is clicked
				}
				else
				{
					return REDO;										//Item Redo is clicked
				}

			case Group_EditLable_And_Delete:
				if (y < ToolBarHeight / 2) {							//user clicked on the upper part of the image
					return EDIT_Label;									//Item Edit Lable is clicked
				}
				else
				{
					return DEL;											//Item Delete is clicked
				}
				
			case Change_Mode_Simulation:		return SIM_MODE;		//change app mode to simulation mode
				
			case ITM_EXIT_Design:				return EXIT;			//Exit the appliction

			default: return DSN_TOOL;									//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	if (AppMode == SIMULATION)	//application is in simulation mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Start_SIM:			return Start_Simulation; //Item Start simulation
			case ITM_Stop_SIM:			return Stop_Simulation;	 //Item Stop simulation
			case ChangeSwitch_ON_OFF:	return Change_Switch;	 //Item Change switch state
			case Select:				return SELECT;			 //Item Select is clicked
			case Change_Mode_Design:	return DSN_MODE;		 //change app mode to Design mode
			case ITM_EXIT_Design:		return EXIT;			 //Exit the application

			default: return DSN_TOOL;							 //A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}

}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
//Changes the title of the application
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
//Create the status bar
void UI::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
//Print the string in the status bar
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
//Clears the status bar
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	//Overwrite using bachground color to erase the message
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor_image.jpg";
	MenuItemImages[ITM_Battery] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Open_Switch.jpg";
	MenuItemImages[ITM_Bulb] = "images\\Menu\\Menu_Closed_Bulb.jpg";
	MenuItemImages[ITM_Ground] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_Buzzer] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_Fuse] = "images\\Menu\\Menu_Fuse.jpg";
	MenuItemImages[ITM_ADD_CONNECTION] = "images\\Menu\\Menu_Wire.jpg";
	MenuItemImages[Group_ChangeSwitch_And_Save] = "images\\Menu\\on_off_switch&Save.jpg";
	MenuItemImages[Group_Select_And_Load] = "images\\Menu\\select&load.jpg";
	MenuItemImages[Group_Move_And_Undo] = "images\\Menu\\move&undo.jpg";
	MenuItemImages[Group_Lable_And_Redo] = "images\\Menu\\Lable&redo.jpg";
	MenuItemImages[Group_EditLable_And_Delete] = "images\\Menu\\Edit_Lable&delete.jpg";
	MenuItemImages[Change_Mode_Simulation] = "images\\Menu\\Menu_simulation.jpg";

	MenuItemImages[ITM_EXIT_Design] = "images\\Menu\\Menu_Exit.jpg";


	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	
	pWind->DrawLine(0, 0, width, 0);
	pWind->DrawLine(0, 0, 0, ToolBarHeight);
	pWind->DrawLine(1370, 0, 1370, ToolBarHeight);
	
	pWind->SetBrush(BLACK);

	//Loop to draw the separation lines between the componnents in Design tool bar
	for (int position = 0; position < 1420; position=position+80) {
		pWind->DrawLine(position, 0, position, ToolBarHeight);
	};
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode

	//List of images for each menu item
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_Start_SIM] = "images\\Menu\\Start.jpg";
	MenuItemImages[ITM_Stop_SIM] = "images\\Menu\\End.jpg";
	MenuItemImages[ChangeSwitch_ON_OFF] = "images\\Menu\\ON&OFF.jpg";
	MenuItemImages[Select] = "images\\Menu\\select.jpg";
	MenuItemImages[Change_Mode_Design] = "images\\Menu\\Menu_Design.jpg";

	MenuItemImages[ITM_EXIT_Simulation] = "images\\Menu\\Menu_Exit.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	pWind->DrawLine(0, 0, width, 0);
	pWind->DrawLine(0, 0, 0, ToolBarHeight);
	pWind->DrawLine(1370, 0, 1370, ToolBarHeight);

	pWind->SetBrush(BLACK);

	//Loop to draw the separation lines between the componnents in Simulation tool bar
	for (int position = 0; position < 560; position = position + 80) {
		pWind->DrawLine(position, 0, position, ToolBarHeight);
	};
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

// This Function prevent the user to draw any where exept in Design area
bool UI::Check_Valid(int x, int y)const{

	if (y > ToolBarHeight + (getCompHeight()/2) + 1 && y < height - (StatusBarHeight + (getCompHeight() / 2)) + 1 && x > (getCompWidth()/2) + 1 && x < width - (getCompWidth() / 2) + 1)   
	{
		return true;
	}
	else
	{
		return false;
	}
}

// To do : Function check if the place where user clicked in the design area empty to draw the componnent or not
// To do : Function check if the place where the two component will be connected in the design area empty to draw the conection or not


// Draws a resistor function
void UI::Draw_Resistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string ResImage;
	if(selected)	
		ResImage ="Images\\Comp\\Resistor_image_HI.jpg";	//use image of highlighted resistor
	else  
		ResImage = "Images\\Comp\\Resistor_image.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws a battery function
void UI::Draw_Battery(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string Battery_Image;
	if (selected)
		Battery_Image = "Images\\Comp\\Battery_image_HI.jpg";	//use image of highlighted resistor
	else
		Battery_Image = "Images\\Comp\\Battery_image.jpg";	//use image of the normal resistor

	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(Battery_Image, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws a Switch function
void UI::Draw_Switch(const GraphicsInfo& r_GfxInfo, bool selected, bool isOn) const
{
	string Switch_Image;
	if (isOn) 
	{
		if (selected)
			Switch_Image = "Images\\Comp\\Open_Switch_HI.jpg";	//use image of highlighted resistor
		else
			Switch_Image = "Images\\Comp\\Open_Switch.jpg";	//use image of the normal resistor
	}
	else
	{
		if (selected)
			Switch_Image = "Images\\Comp\\Closed_Switch_HI.jpg";	//use image of highlighted resistor
		else
			Switch_Image = "Images\\Comp\\Closed_Switch.jpg";	//use image of the normal resistor

	}
	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(Switch_Image, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws On Bulb function
void UI::Draw_Bulb(const GraphicsInfo& r_GfxInfo, bool selected, bool isOn) const
{
	string Bulb_Image;
	if (isOn) {
		if (selected)
			Bulb_Image = "Images\\Comp\\ON_Bulb_HI.jpg";	//use image of highlighted resistor
		else
			Bulb_Image = "Images\\Comp\\ON_Bulb.jpg";	//use image of the normal resistor
	}
	else
	{
		if (selected)
			Bulb_Image = "Images\\Comp\\Closed_Bulb_HI.jpg";	//use image of highlighted resistor
		else
			Bulb_Image = "Images\\Comp\\Closed_Bulb.jpg";	//use image of the normal resistor
	}

	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(Bulb_Image, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws a Ground function
void UI::Draw_Ground(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string Ground_Image;
	if (selected)
		Ground_Image = "Images\\Comp\\Ground_HI.jpg";	//use image of highlighted resistor
	else
		Ground_Image = "Images\\Comp\\Ground.jpg";	//use image of the normal resistor

	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(Ground_Image, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws a Buzzer function
void UI::Draw_Buzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string Buzzer_Image;
	if (selected)
		Buzzer_Image = "Images\\Comp\\Buzzer_image_HI.jpg";	//use image of highlighted resistor
	else
		Buzzer_Image = "Images\\Comp\\Buzzer_image.jpg";	//use image of the normal resistor

	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(Buzzer_Image, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws a Fuse function
void UI::Draw_Fuse(const GraphicsInfo& r_GfxInfo, bool selected, bool isDameged) const
{
	string Fuze_Image;
	if (isDameged)
	{
		if (selected)
			Fuze_Image = "Images\\Comp\\Dameged_Fuse_HI.jpg";	//use image of highlighted resistor
		else
			Fuze_Image = "Images\\Comp\\Dameged_Fuse.jpg";	//use image of the normal resistor
	}
	else
	{
		if (selected)
			Fuze_Image = "Images\\Comp\\Fuse_HI.jpg";	//use image of highlighted resistor
		else
			Fuze_Image = "Images\\Comp\\Fuse.jpg";	//use image of the normal resistor	
	}

	//Draw Battery at Gfx_Info (1st corner)
	pWind->DrawImage(Fuze_Image, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

// Draws Connection function   // to be completed soon
void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	/*
	//TODO: Add code to draw connection
	if (selected) {
		pWind->SetPen(BLACK, 3);
		
	}
	else {

	}
*/
	//pWind->SetPen(BLACK, 3);
	//pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y, FILLED);
}


UI::~UI()
{
	delete pWind;
}