#include "ActionMove.h"

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
    pUI = pManager->GetUI(); //pointer to UI

    pUI->PrintMsg("Select the component you want to move");

    //Component* MoveComp = pSelect->GetSelected_Component();

}

ActionMove::~ActionMove(void) {}

//Component* ActionMove::Get_Selected_Comp() { return pSelect->GetSelected_Component(); }

void ActionMove::Execute()
{
    //pUI->GetPointClicked();     get selected coordinates send it to select and then get elected component then get its dimention then start to move 

   // Component* Selected_Comp = pSelect->GetSelected_Component(); //pointer to the selected compoent

    this->Mouse_Drag(Window); // variable of type window 
}

void ActionMove::Redo(){}

void ActionMove::Undo(){}

void ActionMove::Mouse_Drag(window& testWindow)
{
    UI* pUI = pManager->GetUI();
    pUI->ClearStatusBar();
    

    testWindow.SetBuffering(true);

    bool bDragging = false;

    int iX = 0, iY = 0;

    int iXOld = 0;
    int iYOld = 0;

        
    //to do points of the Component got from select  (pointer for the componenet)
    int RectULX = 100;
    int RectULY = 100;
    int RectWidth = 20;


// Dragging Componenet
if (bDragging == false) {
    if (testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_DOWN) {
        if (((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth)))) {
            bDragging = true;
            iXOld = iX; iYOld = iY;
        }
    }
}
else {
    if (testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_UP) {
        bDragging = false;
    }
    else {
        if (iX != iXOld) {
            RectULX = RectULX + (iX - iXOld);
            iXOld = iX;
        }
        if (iY != iYOld) {
            RectULY = RectULY + (iY - iYOld);
            iYOld = iY;
        }
    }

}

testWindow.UpdateBuffer();
}