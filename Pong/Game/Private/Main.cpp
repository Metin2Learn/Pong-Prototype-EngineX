//
// * ENGINE-X
// * SAMPLE GAME
//
// + Main.cpp
// entry point
//
//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"

#include <windows.h>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

// this is could be better, think design patterns as to why
Game game;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// never allow two instances
	if ( hPrevInstance )
	{
		return 0;
	}

	// check version
	if ( AccessEngineVersion() != kEngineVersion )
	{
		return 0;
	}

	// find the engine
	exEngineInterface* pEngine = AccessEngine();

	if ( pEngine == nullptr )
	{
		return 0;
	}

	// tell it to run
	pEngine->Run( &game );

	return 0;
}
