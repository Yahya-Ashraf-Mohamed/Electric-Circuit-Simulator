
#pragma once
#include "ActionMove.h"
#include "..\ApplicationManager.h"

ApplicationManager* pManager;

void Mouse_Drag(window& testWindow)
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