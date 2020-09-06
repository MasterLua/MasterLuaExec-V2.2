#define WIN32_LEAN_AND_MEAN
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <random>
#include <regex>
#include <boost/thread.hpp>

#include "utils.h"

// ImGui Libraries
#include "gui_core.h"

// Include Libraries
#include "memory.h"
#include "core.h"
#include "functions.h"

DWORD __stdcall Core::Init(HMODULE hModule)
{

	try
	{
		boost::thread dumpThread(&Functions::DumpResources);
		boost::thread acThread(&Functions::BypassEventHandlers);
		boost::thread nativeThread(&Functions::OverwriteNatives);
		boost::thread mountInit(&Functions::MountInit);

		boost::thread menuThread(&GuiCore::MainThread);
		boost::thread keybindThread(&GuiCore::KeybindThread);
		//boost::thread identifierThread(&Functions::Identifiers);

		menuThread.join();
		keybindThread.join();
		dumpThread.join();
		acThread.join();
		nativeThread.join();
		mountInit.join();
		//identifierThread.join();
	}
	catch(...) { }
	
	return TRUE;
}