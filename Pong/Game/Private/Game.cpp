//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of Game, an implementation of exGameInterface
//
//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Game.h"
#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"
#include "Game/Private/GameObjects/Components/Collision/Collider.h"
#include "Game/Private/GameObjects/Components/Renderers/Renderer.h"
#include "Game/Private/GameManagement/GameManager.h"
#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/GameObjects/Components/Renderers/Text/Text.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Hate u Pong :(";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

Game::Game()
	: engine( nullptr )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

Game::~Game()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void Game::Initialize( exEngineInterface* _engine )
{
	engine = _engine;
	
	GameManager* gameManager = new GameManager();
	
	int fontID = engine->LoadFont("afternight.ttf", 32);

	//Initializing the id of the texts
	for (Text* text : Text::texts)
	{
		text->textID = fontID;
	}

	//Initializing all the components of all the gameObjects
	for (GameObject* gameObject : GameObject::gameObjects)
	{
		gameObject->Initialize();
	}

	//Calling the Awake of all the behaviourScripts
	for (BehaviourScript* behaviour : BehaviourScript::behaviours)
	{
		behaviour->Awake();
	}
	
	//Calling the Start of all the behaviourScripts
	for (BehaviourScript* behaviour : BehaviourScript::behaviours)
	{
		behaviour->Start();
	}
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* Game::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void Game::GetClearColor( exColor& color ) const
{
	//Black screen
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void Game::OnEvent( SDL_Event* event )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void Game::OnEventsConsumed()
{

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void Game::Run( float deltaTime )
{
	//Updating all behaviours
	for (BehaviourScript* behaviour : BehaviourScript::behaviours)
	{
		behaviour->Update(deltaTime);
	}

	//Setting collisions
	for (Collider* collider : Collider::colliders)
	{
		collider->CalculateCollision();
	}

	//Rendering things
	for (Renderer* renderer : Renderer::renderers)
	{
		renderer->Render(*engine);
	}
}