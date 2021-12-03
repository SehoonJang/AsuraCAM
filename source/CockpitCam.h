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
#include "SimConnCB.h"


class CockpitCam : public SimConnCB
{
public:
    CockpitCam();
    ~CockpitCam();
    
    /* Callback variable */
    DispatchProc            m_cb;

    void SetCallback(DispatchProc _cb) { m_cb = _cb; }

    int start(void);

    /* input variable */

    /* output variable */

private:

    /* internal Function*/
    void                        testCockpitCamera(void);


};


#endif /* _COCKPITCAM_H_ */