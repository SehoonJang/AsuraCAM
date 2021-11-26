/*
 * CockpitCam.h
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#ifndef _COCKPITCAM_H_
#define _COCKPITCAM_H_

#include "Global.h"

class CockpitCam
{
public:
    CockpitCam();
    ~CockpitCam();

    int start(void);

    /* input variable */

    /* output variable */

private:
    
    /* internal variable */
    int             quit;
    HANDLE          hSimConnect;
    static float    cameraBank;
    DispatchProc    MyDispatchProcCC;

    /* internal Function*/
    float   normalize180(float view);
    void    MyDispatchProcCC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);
    void    testCockpitCamera(void);

};


#endif /* _COCKPITCAM_H_ */