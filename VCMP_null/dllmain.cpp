/*
More information about VC:MP Plugin SDK at: https://forum.vc-mp.org/index.php?topic=13.0

  VC:MP 0.4.7.0 Null plugin by BuilderDemo7
  The purpose of this null plugin is for newbies in plugin scripting

  pluginFuncs is the PluginFuncs struct from the server header, which can be used to call any function available through the plugin SDK.
  pluginCalls is a struct of PluginCallbacks. pluginCalls essentially starts off empty; your plugin must provide its own callbacks and set them in the struct in order for them to be called, and you must use the same pointer to the struct provided.
  pluginInfo is a struct of PluginInfo (from the SDK) that, again, is empty at first. You can set your plugin's version and name (max 32 characters) through it, but you must use the same pointer to the struct.
*/

#include "VCMP.h"
#include "callbacks.h"

#include <memory.h>
#include <stdio.h>

#ifdef WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" EXPORT unsigned int VcmpPluginInit(PluginFuncs* pluginFuncs, PluginCallbacks* pluginCalls, PluginInfo* pluginInfo)
{
	// Plugin information for the server
	pluginInfo->apiMajorVersion = PLUGIN_API_MAJOR;
	pluginInfo->apiMinorVersion = PLUGIN_API_MINOR;

	// Your plugin's name, it can't exceed 32 characters, so keep the size of it 32 chars long.
	const char* PluginName = "NULL";
	memcpy_s(pluginInfo->name, 32, PluginName, 32); // in the memory, copy the name you wrote to the plugin info name
	
	// For callbacks important stuff..
	PluginFunctions = pluginFuncs;
	PluginInformation = pluginInfo;

	// When adding a callback you will need to add it here
	pluginCalls->OnServerInitialise = OnInitServer;
	pluginCalls->OnServerShutdown = OnServerShutdown;
	pluginCalls->OnServerFrame = OnFrame;

	pluginCalls->OnPlayerConnect = OnPlayerConnect;
	pluginCalls->OnPlayerDisconnect = OnPlayerDisconnect;

	return 1; // returns 1 (bool,true) which means success for the server, otherwise for failure.
}