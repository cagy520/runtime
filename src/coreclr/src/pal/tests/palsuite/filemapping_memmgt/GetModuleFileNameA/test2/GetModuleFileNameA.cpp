// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

/*=============================================================
**
** Source:  getmodulefilenamea.c
**
** Purpose: Positive test the GetModuleFileNameA API.
**          Call GetModuleFileName to retrieve current process 
**          full path and file name by passing a NULL module handle
**
**
**============================================================*/
#include <palsuite.h>


#define MODULENAMEBUFFERSIZE 1024

int __cdecl main(int argc, char *argv[])
{

    DWORD ModuleNameLength;
    char ModuleFileNameBuf[MODULENAMEBUFFERSIZE]="";
    int err;

    //Initialize the PAL environment
    err = PAL_Initialize(argc, argv);
    if(0 != err)
    {
        ExitProcess(FAIL);
    }


    //retrieve the current process full path and file name
    //by passing a NULL module handle
    ModuleNameLength = GetModuleFileName(
                NULL,             //a NULL handle
                ModuleFileNameBuf,//buffer for module file name
                MODULENAMEBUFFERSIZE);

    if(0 == ModuleNameLength)
    {
        Fail("\nFailed to all GetModuleFileName API!\n");
    }

    PAL_Terminate();
    return PASS;
}
