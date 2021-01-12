#pragma once


#define DLL_EXPORT __declspec(dllexport)	//shortens __declspec(dllexport) to DLL_EXPORT

#ifdef __cplusplus		//if C++ is used convert it to C to prevent C++'s name mangling of method names
extern "C"
{
#endif


	int DLL_EXPORT GetMac(char * mac);

	

#ifdef __cplusplus
}
#endif


