/*
 *  CockpitCam.cpp
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#include "CockpitCam.h"

CockpitCam::CockpitCam()
{
    quit = 0;
    cameraBank = 0.0f;
}

CockpitCam::~CockpitCam()
{

}

void CockpitCam::init()
{
    cb.RegisterUserFunc(MyDispatchProcCC, this);
}

float CockpitCam::normalize180(float view)
{
    while (view < -180.0f) view += 360.0f;
    while (view < 180.0f) view -= 360.0f;

    return view;
}

void CockpitCam::testCockpitCamera()
{
    HRESULT hr;

    if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Cockpit Camera", NULL, 0, 0, 0)))
    {
        printf("\nConnected to Prepar3D!");

        // Define private events
        hr = SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_CAMERA_RIGHT);
        hr = SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_CAMERA_LEFT);

        hr = SimConnect_AddClientEventToNotificationGroup(hSimConnect, GROUP0, EVENT_CAMERA_RIGHT);
        hr = SimConnect_AddClientEventToNotificationGroup(hSimConnect, GROUP0, EVENT_CAMERA_LEFT);

        hr = SimConnect_SetNotificationGroupPriority(hSimConnect, GROUP0, SIMCONNECT_GROUP_PRIORITY_HIGHEST);

        // Map the keys , and . keys to the private events
        hr = SimConnect_MapInputEventToClientEvent(hSimConnect, INPUT0, "VK_PERIOD", EVENT_CAMERA_RIGHT);
        hr = SimConnect_MapInputEventToClientEvent(hSimConnect, INPUT0, "VK_COMMA", EVENT_CAMERA_LEFT);

        hr = SimConnect_SetInputGroupState(hSimConnect, INPUT0, SIMCONNECT_STATE_ON);


        while (0 == quit)
        {
            SimConnect_CallDispatch(hSimConnect, MyDispatchProcCC, NULL);
            Sleep(1);
        }

        hr = SimConnect_Close(hSimConnect);
    }
    else
        printf("\nFailed to Connect");
}


int CockpitCam::start()
{
    //SimConnCallBack CB;// = new SimConnCallBack;
    //CB.SetHandler(std::bind(&CockpitCam::MyDispatchProcCC, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    //CB.testCockpitCamera();
    testCockpitCamera();

    return 0;
}


void CALLBACK CockpitCam::MyDispatchProcCC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
    CockpitCam* thisObj = (CockpitCam*)pContext;

    HRESULT hr;

    switch (pData->dwID)
    {
    case SIMCONNECT_RECV_ID_EVENT:
    {
        SIMCONNECT_RECV_EVENT* evt = (SIMCONNECT_RECV_EVENT*)pData;

        switch (evt->uEventID)
        {
        case EVENT_CAMERA_RIGHT:

            thisObj->cameraBank = thisObj->normalize180(thisObj->cameraBank + 5.0f);

            hr = SimConnect_CameraSetRelative6DOF(hSimConnect, 0.0f, 0.0f, 0.0f,
                SIMCONNECT_CAMERA_IGNORE_FIELD, SIMCONNECT_CAMERA_IGNORE_FIELD, thisObj->cameraBank);

            printf("\nCamera Bank = %f", thisObj->cameraBank);
            break;

        case EVENT_CAMERA_LEFT:

            thisObj->cameraBank = thisObj->normalize180(thisObj->cameraBank - 5.0f);

            hr = SimConnect_CameraSetRelative6DOF(hSimConnect, 0.0f, 0.0f, 0.0f,
                SIMCONNECT_CAMERA_IGNORE_FIELD, SIMCONNECT_CAMERA_IGNORE_FIELD, thisObj->cameraBank);

            printf("\nCamera Bank = %f", thisObj->cameraBank);
            break;

        default:
            break;
        }
        break;
    }

    case SIMCONNECT_RECV_ID_EXCEPTION:
    {
        SIMCONNECT_RECV_EXCEPTION* except = (SIMCONNECT_RECV_EXCEPTION*)pData;

        switch (except->dwException)
        {
        case SIMCONNECT_EXCEPTION_ERROR:
            printf("\nCamera error");
            break;

        default:
            printf("\nException");
            break;
        }
        break;
    }

    case SIMCONNECT_RECV_ID_QUIT:
    {
        quit = 1;
        break;
    }

    default:
        break;
    }
}
