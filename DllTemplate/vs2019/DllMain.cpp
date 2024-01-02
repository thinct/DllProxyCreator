#include <Windows.h>

HINSTANCE gDllhInstance = NULL; // global storage for current dll handle

BOOL ProcessAttach();
BOOL ProcessDetach();

BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD dwReason, PVOID pvReserved)
{
    UNREFERENCED_PARAMETER(pvReserved);

    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        gDllhInstance =hInstDLL;
        return ProcessAttach();
    case DLL_PROCESS_DETACH:
        return ProcessDetach();
    }
    return TRUE;
}

BOOL ProcessAttach()
{
    // Add your initialization code there
    return TRUE;
}

BOOL ProcessDetach()
{
    // Add your uninitialization code there
    return TRUE;
}
