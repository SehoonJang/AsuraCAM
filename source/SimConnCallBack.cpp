/*
 *  SimConnCallBack.cpp
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#include "SimConnCallBack.h"

//SimConnCallBack::SimConnCallBack()
//{
//    
//}
//
//SimConnCallBack::~SimConnCallBack()
//{
//
//}

//void SimConnCallBack::testCockpitCamera()
//{
//    HRESULT hr;
//
//    if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Cockpit Camera", NULL, 0, 0, 0)))
//    {
//        printf("\nConnected to Prepar3D!");
//
//        // Define private events
//        hr = SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_CAMERA_RIGHT);
//        hr = SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_CAMERA_LEFT);
//
//        hr = SimConnect_AddClientEventToNotificationGroup(hSimConnect, GROUP0, EVENT_CAMERA_RIGHT);
//        hr = SimConnect_AddClientEventToNotificationGroup(hSimConnect, GROUP0, EVENT_CAMERA_LEFT);
//
//        hr = SimConnect_SetNotificationGroupPriority(hSimConnect, GROUP0, SIMCONNECT_GROUP_PRIORITY_HIGHEST);
//
//        // Map the keys , and . keys to the private events
//        hr = SimConnect_MapInputEventToClientEvent(hSimConnect, INPUT0, "VK_PERIOD", EVENT_CAMERA_RIGHT);
//        hr = SimConnect_MapInputEventToClientEvent(hSimConnect, INPUT0, "VK_COMMA", EVENT_CAMERA_LEFT);
//
//        hr = SimConnect_SetInputGroupState(hSimConnect, INPUT0, SIMCONNECT_STATE_ON);
//
//
//        while (0 == quit)
//        {
//            SimConnect_CallDispatch(hSimConnect, DispatchProc, NULL);
//            Sleep(1);
//        }
//
//        hr = SimConnect_Close(hSimConnect);
//    }
//    else
//        printf("\nFailed to Connect");
//}

void SimConnCallBack::RegisterUserFunc(void* func, void* ctx)
{
    m_userfunc = (DispatchProc)func;

    m_userContext = ctx;
}