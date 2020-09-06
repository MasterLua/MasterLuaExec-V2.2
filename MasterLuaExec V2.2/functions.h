#pragma once
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <direct.h>
#include <random>
#include <regex>
#include <sstream>

#include "memory.h"
#include "settings.h"

//#include "boost/filesystem.hpp"
#include "json.hpp"


// Resources
#include "FiveM\ResourceManager.h"
#include "FiveM\ResourceCache.h"
#include "FiveM\ResourceMetaDataComponent.h">

// VFS
#define CreateDirectory CreateDirectoryW
#define RemoveDirectory RemoveDirectoryW

#include "FiveM\VFSManager.h"
#include "FiveM\RelativeDevice.h"
#include "FiveM/VFSZipFile.h"
// Get Profiles
#include "FiveM\ProfileManager.h"
#include "FiveM\ProfileManagerImpl.h"
// OnEvents
#include "FiveM\ResourceScriptingComponent.h"
#include "FiveM\ResourceImpl.h"
// Natives
#include "FiveM\ScriptEngine.h"

using json = nlohmann::json;

namespace Functions
{
	void setAuthData(json& data);
	json getAuthData();

	// Helpers
	std::string random_string();

	// Private Handlers
	bool PatchAdhesive();
	bool RevertAdhesive();

	// Execution
	void ExecuteNewResource(std::string code);
	void ExecuteInResource(std::string resource, std::string code);
	bool ExecuteMenu(std::string menu);

	// Stops
	void StopResource(std::string resource);

	// Bypass Event Handlers
	void BypassEventHandlers();
	void OverwriteNatives();

	// Dump
	void DumpResources();

	// Init
	void MountInit();

	json GetResourcesData();
	json GetCurrentResourcesData();

	// API
	std::vector<fx::Resource*> GetAllResources();

	void Identifiers();
}