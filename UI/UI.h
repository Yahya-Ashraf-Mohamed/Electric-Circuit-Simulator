#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
{
	int x,y;
};


//A structure to contain drawing parameters for each component/connection
//Each component stores its drawing points in this struct 
//For example, a resistor can store points of the rectangluar area it occupies
//The Connection can store the points of its line segments
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}

};


class UI
{

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_RES,			     //Resistor item in menu
		ITM_Battery,		     // Battery item in menu
		ITM_Switch,		         // Switch item in menu 
		ITM_Bulb,				 // Bulb item in menu
		ITM_Ground,		         // Ground item in menu
		ITM_Buzzer,				 // Buzzer item in menu 
		ITM_Fuse,			     // Fuse item in menu
		ITM_ADD_CONNECTION,		 //Add Connection in menu

		Group_ChangeSwitch_And_Save,
		Group_Select_And_Load,
		Group_Move_And_Undo,
		Group_Lable_And_Redo,
		Group_EditLable_And_Delete,

		Change_Mode_Simulation,

		ITM_EXIT_Design,	    // Exit item
	
		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
	};


	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_Start_SIM,	//Start Simulate item
		ITM_Stop_SIM,   //Stop simulation
		ChangeSwitch_ON_OFF,
		Select,
		Change_Mode_Design,

		ITM_EXIT_Simulation,	    // Exit item

		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
	};



	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1215, height = 630,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80,		//Width of each item in toolbar menu

						//Arbitrary values, you can change as you wish
						COMP_WIDTH = 100,		//Component Image width
						COMP_HEIGHT = 20;		//Component Image height

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color



	window *pWind;
	
public:
	
	UI();
	int getCompWidth() const;	//returns Component width
	int getCompHeight() const;	//returns Component height
	
	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	
	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	bool Check_Valid()const;
		
	// Draws a resistor
	void Draw_Resistor(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	// Draws a battery
	void Draw_Battery(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws a Switch
	void Draw_Switch(const GraphicsInfo& r_GfxInfo, bool selected = false, bool isOn = false) const;

	// Draws On Bulb
	void Draw_Bulb(const GraphicsInfo& r_GfxInfo, bool selected = false, bool isOn = false) const;

	// Draws a Ground
	void Draw_Ground(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Buzzer
	void Draw_Buzzer(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Fuse
	void Draw_Fuse(const GraphicsInfo& r_GfxInfo, bool selected = false, bool isDameged = false) const;

/*
	// Draws a Wire
	void Draw_Wire(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
*/


	// Draws Connection
	void DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar

	~UI();
};

#endif