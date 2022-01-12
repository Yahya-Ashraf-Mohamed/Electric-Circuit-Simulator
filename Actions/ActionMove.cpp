#include "ActionMove.h"

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
    pUI = pManager->GetUI(); //pointer to UI
    pWind = pUI->GetpWind(); //pointer to window

}

ActionMove::~ActionMove(void) {}

//Component* ActionMove::Get_Selected_Comp() { return pSelect->GetSelected_Component(); }

void ActionMove::Execute()
{
    //get selected coordinates send it to select and then get elected component then get its dimention then start to move 

    Select* pSelect = nullptr;

    if (pManager->is_one_Comp_selected() == false)
    {
        pUI->PrintMsg("One component must be selected Only!");
        return;
    }

    //pUI->PrintMsg("Select the component you want to move");


    //for(int i =0; i = pManager->GetCompCount(); i++)
    //{
    //    
    //}

    //pSelect->Execute();
    /*pManager->ExecuteAction(SELECT);*/

    MoveComp = pManager->get_selected_Component();
    /*pAct->Execute();*/
    //Component* MoveComp = pSelect->GetSelected_Component();


    bool isDragged = false;

    int X = 0, Y = 0;

    int X_Old = 0, Y_Old = 0;

    GraphicsInfo MoveCompInfo = MoveComp->get_Comp_Graphics_Info();

    //int X1 = MoveComp->get_Comp_Graphics_Info().PointsList[0].x;
    //to do points of the Component got from select  (pointer for the componenet)
    //int X1 = MoveCompInfo.PointsList[0].x;
    //int Y1 = MoveCompInfo.PointsList[0].y;
    int height = pUI->getCompHeight();
    int width = pUI->getCompWidth();

    char cKeyData;

    pUI->ClearStatusBar();
    pWind->SetBuffering(true);
    pManager->UpdateInterface();

    while (pWind->GetKeyPress(cKeyData) != ESCAPE)
    {
        // Dragging Componenet
        if (isDragged == false) {
            if (pWind->GetButtonState(LEFT_BUTTON, X, Y) == BUTTON_DOWN) {
                if (((X > MoveCompInfo.PointsList[0].x) && (X < (MoveCompInfo.PointsList[0].x + width))) && ((Y > MoveCompInfo.PointsList[0].y) && (Y < (MoveCompInfo.PointsList[0].y + height)))) {
                    isDragged = true;
                    X_Old = X; Y_Old = Y;
                    
                    pUI->ClearDrawingArea();
                    pManager->UpdateDrawingArea();
                    pUI->PrintMsg("Moving the component press Esc to stop");

                }
            }
        }
        else {
            if (pWind->GetButtonState(LEFT_BUTTON, X, Y) == BUTTON_UP) {
                isDragged = false;
             
            }
            else {
                if (X != X_Old) {
                    MoveCompInfo.PointsList[0].x = MoveCompInfo.PointsList[0].x + (X - X_Old);
                    X_Old = X;
                }
                if (Y != Y_Old) {
                    MoveCompInfo.PointsList[0].y = MoveCompInfo.PointsList[0].y + (Y - Y_Old);
                    Y_Old = Y;
                }
                pManager->UpdateDrawingArea();
              //  pUI->PrintMsg("Moving the component");
            }

        }
        
        pUI->ClearDrawingArea();
        pManager->UpdateDrawingArea();
        pUI->PrintMsg("Moving the component press Esc to stop");

        pWind->UpdateBuffer();

    }


    pWind->SetBuffering(false);

    MoveComp->set_Comp_Graphics_Info(MoveCompInfo.PointsList[0].x, MoveCompInfo.PointsList[0].y);
    pUI->ClearStatusBar();
    pManager->UpdateInterface();
}

void ActionMove::Redo(){}

void ActionMove::Undo(){}
