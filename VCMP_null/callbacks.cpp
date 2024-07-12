#include <stdio.h>

#include "callbacks.h"

// This is a callback for when the server is initialised
uint8_t OnInitServer()
{
#ifdef _DEBUG
	printf("Hello, World!\n");
#endif
	return 1;
}

// This is a callback for when the server is shutting down
void OnServerShutdown()
{
}

void OnFrame(float elapsedTime)
{
}

void OnPlayerConnect(int32_t nPlayerId)
{
}

void OnPlayerDisconnect(int32_t nPlayerId, vcmpDisconnectReason nReason)
{
}