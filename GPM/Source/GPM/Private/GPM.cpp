//------------------------------------------------------------------------------
//
// File: GPM.cpp
// Module: GPM
// Version: 1.0
// Author: vincentwgao
//
//------------------------------------------------------------------------------


// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GPM.h"
//#include "Modules/ModuleManager.h"


#define LOCTEXT_NAMESPACE "FGPMModule"

void FGPMModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FGPMModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGPMModule, GPM)
