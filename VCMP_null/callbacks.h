/*
More information about VC:MP Plugin SDK at: https://forum.vc-mp.org/index.php?topic=13.0

  Callbacks header file,
  in order to create a callback you would need to make the function like so.
*/

#include "VCMP.h"

typedef int(*SDK_OnInitServer) (void);
typedef void(*SDK_OnShutdownServer) (void);
typedef void(*SDK_OnFrame) (float fElapsedTime);
typedef void(*SDK_OnPlayerConnect) (int nPlayerId);
typedef void(*SDK_OnPlayerDisconnect) (int nPlayerId, int nReason);
typedef void(*SDK_OnPlayerBeginTyping) (int nPlayerId);
typedef void(*SDK_OnPlayerEndTyping) (int nPlayerId);
typedef int(*SDK_OnPlayerRequestClass) (int nPlayerId, int nOffset);
typedef int(*SDK_OnPlayerRequestSpawn) (int nPlayerId);
typedef void(*SDK_OnPlayerSpawn) (int nPlayerId);
typedef void(*SDK_OnPlayerDeath) (int nPlayerId, int nKillerId, int nReason, int nBodyPart);
typedef void(*SDK_OnPlayerUpdate) (int nPlayerId, int nUpdateType);
typedef int(*SDK_OnPlayerRequestEnter) (int nPlayerId, int nVehicleId, int nSlotId);
typedef void(*SDK_OnPlayerEnterVehicle) (int nPlayerId, int nVehicleId, int nSlotId);
typedef void(*SDK_OnPlayerExitVehicle) (int nPlayerId, int nVehicleId);
typedef int(*SDK_OnPickupClaimPicked) (int nPickupId, int nPlayerId);
typedef void(*SDK_OnPickupPickedUp) (int nPickupId, int nPlayerId);
typedef void(*SDK_OnPickupRespawn) (int nPickupId);
typedef void(*SDK_OnVehicleUpdate) (int nVehicleId, int nUpdateType);
typedef void(*SDK_OnVehicleExplode) (int nVehicleId);
typedef void(*SDK_OnVehicleRespawn) (int nVehicleId);
typedef void(*SDK_OnObjectShot) (int nObjectId, int nPlayerId, int nWeapon);
typedef void(*SDK_OnObjectBump) (int nObjectId, int nPlayerId);
typedef int(*SDK_OnPublicMessage) (int nPlayerId, const char* pszText);
typedef int(*SDK_OnCommandMessage) (int nPlayerId, const char* pszText);
typedef int(*SDK_OnPrivateMessage) (int nPlayerId, int nTargetId, const char* pszText);
typedef int(*SDK_OnInternalCommand) (unsigned int uCmdType, const char* pszText);
typedef int(*SDK_OnLoginAttempt) (char* pszPlayerName, const char* pszUserPassword, const char* pszIpAddress);
typedef void(*SDK_OnEntityPoolChange) (int nEntityType, int nEntityId, unsigned int bDeleted);
typedef void(*SDK_OnKeyBindDown) (int nPlayerId, int nBindId);
typedef void(*SDK_OnKeyBindUp) (int nPlayerId, int nBindId);
typedef void(*SDK_OnPlayerAwayChange) (int nPlayerId, unsigned int bNewStatus);
typedef void(*SDK_OnPlayerSpectate) (int nPlayerId, int nTargetId);
typedef void(*SDK_OnPlayerCrashReport) (int nPlayerId, const char* pszReport);
typedef void(*SDK_OnServerPerformanceReport) (int nNumStats, const char** ppszDescription, unsigned long long* pnMillisecsSpent);

// Important callbacks
static PluginFuncs* PluginFunctions; // This is the server functions SDK struct
static PluginInfo* PluginInformation; // This is the plugin information

// Your callbacks here
uint8_t OnInitServer();
void OnServerShutdown();
void OnFrame(float elapsedTime);
void OnPlayerConnect(int32_t nPlayerId);
void OnPlayerDisconnect(int32_t nPlayerId, vcmpDisconnectReason nReason);