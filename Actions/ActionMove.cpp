#include "ActionMove.h"

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
    pUI = pManager->GetUI(); //pointer to UI
    pWind = pUI->GetpWind(); //pointer to window

    pUI->PrintMsg("Select the component you want to move");

    //pSelect->Execute();

    //MoveComp = pSelect->GetSelected_Component();
    /*pAct->Execute();*/
    //Component* MoveComp = pSelect->GetSelected_Component();

}

ActionMove::~ActionMove(void) {}

//Component* ActionMove::Get_Selected_Comp() { return pSelect->GetSelected_Component(); }

void ActionMove::Execute()
{
//get selected coordinates send it to select and then get elected component then get its dimention then start to move 

    pUI->ClearStatusBar();

    pWind->SetBuffering(true);

    bool isDragged = false;

    int X = 0, Y = 0;

    int X_Old = 0, Y_Old = 0;

    GraphicsInfo* MoveCompInfo = MoveComp->get_Comp_Graphics_Info();

    //to do points of the Component got from select  (pointer for the componenet)
    int X1 = MoveCompInfo->PointsList[0].x;
    int Y1 = MoveCompInfo->PointsList[0].y;
    int height = pUI->getCompHeight();
    int width = pUI->getCompWidth();

    // Dragging Componenet
    if (isDragged == false) {
        if (pWind->GetButtonState(LEFT_BUTTON, X, Y) == BUTTON_DOWN) {
            if (((X > X1) && (X < (X1 + width))) && ((Y > Y1) && (Y < (Y1 + height)))) {
                isDragged = true;
                X_Old = X; Y_Old = Y;
            }
        }
    }
    else {
        if (pWind->GetButtonState(LEFT_BUTTON, X, Y) == BUTTON_UP) {
            isDragged = false;
        }
        else {
            if (X != X_Old) {
                X1 = X1 + (X - X_Old);
                X_Old = X;
            }
            if (Y != Y_Old) {
                Y1 = Y1 + (Y - Y_Old);
                Y_Old = Y;
            }
        }

    }

    pWind->UpdateBuffer();
}


void ActionMove::Redo(){}

void ActionMove::Undo(){}
