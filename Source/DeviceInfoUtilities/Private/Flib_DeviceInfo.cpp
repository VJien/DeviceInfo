// Fill out your copyright notice in the Description page of Project Settings.


#include "Flib_DeviceInfo.h"
#include "Windows/WindowsPlatformProcess.h"
#include "Misc/Paths.h"
#include "ThirdPartyDLL.h"
#include "Misc/NetworkVersion.h"
#include "GenericPlatform/GenericPlatformDriver.h"
#include "SocketSubsystem.h"

typedef int(*_getMac)(char * mac);


_getMac funcGetMac;


void *v_dllHandle;

bool UFlib_DeviceInfo::importDLL(const FString& folder, const FString& name)
{
	FString filePath = *FPaths::ProjectPluginsDir() + folder + "/" + name;

	if (FPaths::FileExists(filePath))
	{

		v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);

		if (v_dllHandle != nullptr)
		{
			return true;
		}
	}
	return false;
}

FString UFlib_DeviceInfo::GetMacFromDLL()
{
	FString folder = "DeviceInfoUtilities//ThirdParty//DLL";
	FString file = "ThirdPartyDLL.dll";
	FString filePath = *FPaths::ProjectPluginsDir() + folder + "/" + file;

	if (FPaths::FileExists(filePath))
	{
		v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);

		if (v_dllHandle != nullptr)
		{
			funcGetMac = nullptr;
			FString procName = "GetMac";
			funcGetMac = (_getMac)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
			if (funcGetMac != nullptr)
			{
				int idx = 0;
				char   mac[200];
				idx = int(funcGetMac(mac));
				return FString(mac);
			}
		}
	}
	return TEXT("");
}

FString UFlib_DeviceInfo::GetMacFromLib()
{
	char   mac[200];
	GetMac(mac);
	FString out = FString(mac);
	return out;
}

FString UFlib_DeviceInfo::GetBuildVersion()
{
	return FApp::GetBuildVersion();
}

void UFlib_DeviceInfo::GetCPUInfo(FString& brand, FString& Chipset, int& Info, FString& Vendor)
{
	 brand =  FPlatformMisc::GetCPUBrand();
	 Chipset = FPlatformMisc::GetCPUChipset();
	 Info = FPlatformMisc::GetCPUInfo();
	 Vendor = FPlatformMisc::GetCPUVendor();

}




void UFlib_DeviceInfo::GetGPUInfo(FString& Brand,  FString& ProviderName, int32& VendorID, FString& InternalDriverVersion,
FString& UserDriverVersion, FString& DriverDate, FString& RHIName)
{
	Brand = FPlatformMisc::GetPrimaryGPUBrand();
	FGPUDriverInfo info = FPlatformMisc::GetGPUDriverInfo(Brand);
	ProviderName = info.ProviderName;
	VendorID = info.VendorId;
	InternalDriverVersion = info.InternalDriverVersion;
	UserDriverVersion = info.UserDriverVersion;
	DriverDate = info.DriverDate;
	RHIName = info.RHIName;

}



FString UFlib_DeviceInfo::GetIpAddress(bool bHasPort /*= true*/)
{
	FString IpAddr("NONE");

	bool canBind = false;
	TSharedRef<FInternetAddr>LocalIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBind);

	if (LocalIp->IsValid())
	{
		IpAddr = LocalIp->ToString(bHasPort); //如果想附加端口就写 ture
	}

	return IpAddr;
}



void UFlib_DeviceInfo::GetOSVersions( FString& Label,  FString& Version)
{
	FPlatformMisc::GetOSVersions(Label, Version);
}
