// MIT License - Copyright (c) 2025 LJYC (ljyc.me)
// See LICENSE file in the root of the repository for more details.

#pragma once

#include "Modules/ModuleManager.h"

class FMunsellToRGBModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
