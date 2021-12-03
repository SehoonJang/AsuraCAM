/*
 *  CockpitCam.h
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#ifndef _COCKPITCAM_H_
#define _COCKPITCAM_H_

#include "Global.h"
#include "SimConnCallBack.h"

using namespace std;

//static void    CALLBACK     MyDispatchProcCC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);

class CockpitCam
{
public:
    CockpitCam();
    ~CockpitCam();

    /* External Function Call */
    void        init(void);
    int         start(void);

    /* input variable */
    SimConnCallBack     cb;
    static float        cameraBank;
    float               normalize180(float view);
    void    CALLBACK    MyDispatchProcCC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);
    /* output variable */

private:

    /* internal variable */
     

    /* internal Function*/
    void                        testCockpitCamera(void);
   
};



#endif /* _COCKPITCAM_H_ */