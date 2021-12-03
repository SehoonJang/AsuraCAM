﻿// CamSim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CockpitCam.h"
#include "SimConnCB.h"

DispatchProc		m_cb = NULL;

int __cdecl main(int argc, _TCHAR* argv[])
{
	CockpitCam*			CAM		= new CockpitCam;

	if (m_cb == NULL)
	{
		std::cout << "Callback Function is not set" << std::endl;
	}
	
	SetCallBack(MyDispatchProcCC);
	

	CAM->start();
	

	return 0;
}

void SetCallBack(DispatchProc cb) { m_cb = cb; }


float normalize180(float view)
{
    while (view < -180.0f) view += 360.0f;
    while (view < 180.0f) view -= 360.0f;

    return view;
}

void CALLBACK MyDispatchProcCC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
    HRESULT hr;

    switch (pData->dwID)
    {
    case SIMCONNECT_RECV_ID_EVENT:
    {
        SIMCONNECT_RECV_EVENT* evt = (SIMCONNECT_RECV_EVENT*)pData;

        switch (evt->uEventID)
        {
        case EVENT_CAMERA_RIGHT:

            cameraBank = normalize180(cameraBank + 5.0f);

            hr = SimConnect_CameraSetRelative6DOF(hSimConnect, 0.0f, 0.0f, 0.0f,
                SIMCONNECT_CAMERA_IGNORE_FIELD, SIMCONNECT_CAMERA_IGNORE_FIELD, cameraBank);

            printf("\nCamera Bank = %f", cameraBank);
            break;

        case EVENT_CAMERA_LEFT:

            cameraBank = normalize180(cameraBank - 5.0f);

            hr = SimConnect_CameraSetRelative6DOF(hSimConnect, 0.0f, 0.0f, 0.0f,
                SIMCONNECT_CAMERA_IGNORE_FIELD, SIMCONNECT_CAMERA_IGNORE_FIELD, cameraBank);

            printf("\nCamera Bank = %f", cameraBank);
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