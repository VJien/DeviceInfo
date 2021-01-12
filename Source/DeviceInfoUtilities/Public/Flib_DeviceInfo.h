// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Flib_DeviceInfo.generated.h"

/**
 * 
 */
UCLASS()
class DEVICEINFOUTILITIES_API UFlib_DeviceInfo : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Flib|DllHelper")
		static bool importDLL(const FString& folder, const FString& name);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo", meta = (DisplayName = "GetMacDLL"))
		static FString GetMacFromDLL();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo", meta = (DisplayName = "GetMac"))
		static FString GetMacFromLib();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo")
		static FString GetBuildVersion();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo")
		static void GetCPUInfo(FString& brand, FString& Chipset, int32& Info, FString& Vendor);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo")
		static void GetGPUInfo(FString& Brand, FString& ProviderName, int& VendorID, FString& InternalDriverVersion,
			FString& UserDriverVersion, FString& DriverDate, FString& RHIName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo")
		static FString GetIpAddress(bool bHasPort = true);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Flib|DeviceInfo")
		static void GetOSVersions( FString& Label,  FString& Version);

};
