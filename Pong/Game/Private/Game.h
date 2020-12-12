//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//
//Copyright(C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Engine/Public/EngineInterface.h"

#include <vector>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class Game : public exGameInterface
{
public:

								Game();
	virtual						~Game();

	virtual void				Initialize( exEngineInterface* engine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* event );
	virtual void				OnEventsConsumed();

	virtual void				Run( float deltaTime );

private:

	exEngineInterface*			engine;
};