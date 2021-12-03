/*
 * SimConnCB.h
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#ifndef _SIMCONNCB_H_
#define _SIMCONNCB_H_

#include "Global.h"
#include "SimConnect.h"

class SimConnCB
{

public:
	//DispatchProc m_cb;
	//void SetCallback(DispatchProc _cb) { m_cb = _cb; }
	void        CALLBACK        MyDispatchProcCC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);

	/* Global variable */
	int                         quit;
	static float                cameraBank;

private:
	/* internal variable */


	/* internal function */
	float                       normalize180(float view);

};

#endif /* _SIMCONNCB_H_ */