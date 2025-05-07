// MIT License - Copyright (c) 2025 LJYC (ljyc.me)
// See LICENSE file in the root of the repository for more details.

#include "MunsellToRGB.h"

#define LOCTEXT_NAMESPACE "FMunsellToRGBModule"

void FMunsellToRGBModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FMunsellToRGBModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMunsellToRGBModule, MunsellToRGB)