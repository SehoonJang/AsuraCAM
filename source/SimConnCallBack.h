/*
 *  SimConnCallBack.h
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#ifndef _SIMCONNCALLBACK_H_
#define _SIMCONNCALLBACK_H_

#include "Global.h"
#include "MySimConnect.h"

using namespace std;

class SimConnCallBack
{
public:
    //SimConnCallBack();
    //~SimConnCallBack();

    DispatchProc    m_userfunc;

    void*           m_userContext;

    //void                        SetHandler(DispatchProc f) { m_userfunc = std::move(f); }

    //void                        testCockpitCamera(void);

    void RegisterUserFunc(void* func, void* ctx);

private:

    /* typedefine the callback function
    * same as :
    * typedef void (CALLBACK* DispatchProc)(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);
    */
    //typedef std::function<void(SIMCONNECT_RECV*, DWORD, void*)>  DispatchProc;


    
    /* internal variable */
    


};

#endif /* _SIMCONNCALLBACK_H_ */