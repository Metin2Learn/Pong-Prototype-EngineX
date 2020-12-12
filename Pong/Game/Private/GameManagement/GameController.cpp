//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameManagement/GameController.h"
#include "Game/Private/GameObjects/Components/Behaviours/Goal/GoalEvent.h"
#include "Game/Private/GameObjects/Components/Renderers/Text/Text.h"
#include "Game/Private/GameObjects/Prefabs/Ball.h"
#include "Game/Private/GameObjects/Components/Behaviours/Ball/BallMovement.h"

GameController::GameController(GameObject* gameObject)
	: BehaviourScript(gameObject)
{
	player1Score = 0;
	player2Score = 0;
}

GameController::~GameController()
{

}

ComponentType GameController::GetType() const
{
	return ComponentType::GameController;
}

void GameController::OnNotify(EventData* eventData)
{
	GoalEvent* goalEvent = dynamic_cast<GoalEvent*>(eventData);
	std::string id = goalEvent->GetID();

	if (id == "LeftGoal")
	{
		player1Score++;
		player1Text->text = std::to_string(player1Score);
	}
	else
	{
		player2Score++;
		player2Text->text = std::to_string(player2Score);
	}
	ballMovement->speed = 250;
	ball->GetTransform().SetPosition(Vector2(400, 300));
}