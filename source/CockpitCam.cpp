#include "CockpitCam.h"

CockpitCam::CockpitCam()
{


}


CockpitCam::~CockpitCam()
{

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
            SimConnect_CallDispatch(hSimConnect, m_cb, NULL);
            Sleep(1);
        }

        hr = SimConnect_Close(hSimConnect);
    }
    else
        printf("\nFailed to Connect");
}


int CockpitCam::start()
{
    testCockpitCamera();

    return 0;
}