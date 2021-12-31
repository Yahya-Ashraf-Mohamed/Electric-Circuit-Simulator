#include "ActionMove.h"

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
    pUI = pManager->GetUI(); //pointer to UI
    pWind = pUI->GetpWind(); //pointer to window
 
    pManager->GetUI()->ClearStatusBar();
    pManager->GetUI()->PrintMsg("Select the component you want to move");
    pManager->GetUI()->GetPointClicked(Selected_X, Selected_y);
    if (Selected_y < pUI->getWindowHeight() - pUI->getStatusBarHeight() && Selected_y > pUI->getToolBarHeight())
        pManager->GetUI()->ClearStatusBar();
    else
    {
        pManager->GetUI()->PrintMsg("Please Select the Component from design area only!");
    }

    //pSelect->Execute();
//    pManager->ExecuteAction(SELECT);
    

  //  MoveComp = pManager->Get_Component_By_Coordinates(Selected_X, Selected_y);
    //MoveComp = pManager->GetCompList()[pManager->GetCompCount()];
    //MoveComp = pSelect->GetSelected_Component();
    /*pAct->Execute();*/
    //Component* MoveComp = pSelect->GetSelected_Component();

}

ActionMove::~ActionMove(void) {}

//Component* ActionMove::Get_Selected_Comp() { return pSelect->GetSelected_Component(); }

void ActionMove::Execute()
{
    //get selected coordinates send it to select and then get elected component then get its dimention then start to move 
    bool State = true;

    MoveComp = pManager->Get_Moveable_Component_By_Coordinates(Selected_X, Selected_y);

    if (MoveComp == nullptr)
    {
        pManager->GetUI()->ClearStatusBar();
    }
    else
    {
        while (State)
        {

            //pWind->SetBuffering(true);

            bool isDragged = false;

            int X = 0, Y = 0;

            int X_Old = 0, Y_Old = 0;

   //         GraphicsInfo MoveCompInfo = MoveComp->get_Comp_Graphics_Info();

            //to do points of the Component got from select  (pointer for the componenet)
            int X1 = MoveComp->getX1();
            int Y1 = MoveComp->getY1();
            
 //           int X1 = MoveCompInfo.PointsList[0].x;
  //          int Y1 = MoveCompInfo.PointsList[0].y;
            int height = pUI->getCompHeight();
            int width = pUI->getCompWidth();

            // Dragging Componenet
            if (isDragged == false) {
                if (pWind->GetButtonState(LEFT_BUTTON, X, Y) == BUTTON_DOWN) {
                    if (((X > X1) && (X < (X1 + width))) && ((Y > Y1) && (Y < (Y1 + height)))) {
                        isDragged = true;
                        MoveComp->setX1(X);
                        MoveComp->setY1(Y);
               //         pUI->ClearStatusBar();
                        pManager->UpdateInterface();
                        State = false;
                    }
                }
            }
            else {
                if (pWind->GetButtonState(LEFT_BUTTON, X, Y) == BUTTON_UP) {
                    isDragged = false;
                    pManager->UpdateInterface();
                    State = false;
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
                    pManager->UpdateInterface();
                }

            }

          //pWind->UpdateBuffer();
        }
    }
}
void ActionMove::Redo(){}

void ActionMove::Undo(){}
