/*
 *  Global.h
 *
 *  Created on  : 2021.10.23.
 *      Author  : Sehoon Jang
 *
 */

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include <functional>



int                     quit;
HANDLE                  hSimConnect;

enum GROUP_ID {
    GROUP0,
};

enum EVENT_ID {
    EVENT_CAMERA_RIGHT,
    EVENT_CAMERA_LEFT,
};

enum INPUT_ID {
    INPUT0,
};


#endif /* _GLOBAL_H_ */