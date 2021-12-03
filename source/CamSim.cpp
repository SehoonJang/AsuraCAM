/*
 *  CamSim.cpp
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

//
// CamSim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CockpitCam.h"


int __cdecl main(int argc, _TCHAR* argv[])
{
    CockpitCam*     cockpit = new CockpitCam;

    cockpit->init();
    cockpit->start();
    

    return 0;
}
