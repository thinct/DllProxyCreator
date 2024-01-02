> ref(http://jacquelin.potier.free.fr/DllProxyCreator/)

## Must replace the dll original name by the new name
Project content source files are:

   - DllMain.cpp containing the skeletons of the functions to override : you need to fill these functions code and adjust definition of functions for which header parsing failed (or if no header parsing was done)

   - Forwarded.cpp (or Forwarded.def according to the choosen "Forward way" option) containing forwarded functions definition. For Method 1, as we are going to rename original dll, you must replace the dll original name by the new name. Here, as we are going to rename "lib_magic64.dll" into "lib_magic64_org.dll", we have to replace all occurences of "lib_magic64" by "lib_magic64_org" in Forwarded.cpp (use your favorite editor to do this search and replace operation)


## Have to do an explicit function address resolving
```c++
typedef void* (__cdecl *pfmagic_open)(int i);
C_DLL_EXPORT void* __cdecl magic_open(int i)
{
    ::MessageBoxW(NULL,L"magic_open trace",L"Dll Proxy",MB_ICONINFORMATION);
 
    // 1) get the original dll handle (WARNING the new name of the original dll)
    HMODULE hModule = ::GetModuleHandle(TEXT("lib_magic64_org.dll"));
 
    // 2) get function address inside the original dll
    pfmagic_open pmagic_open = (pfmagic_open)::GetProcAddress(hModule,"magic_open");
 
    // 3) call original function
    if (pmagic_open)
        return pmagic_open(i);
    else
        return NULL;
}
```
