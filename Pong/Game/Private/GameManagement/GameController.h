//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"
#include "Game/Private/DesignPatterns/Observer/Observer.h"

class Text;
class Ball;
class BallMovement;

//Manages the game
class GameController : public BehaviourScript, public Observer
{
public:
	GameController(GameObject* gameObject);
	~GameController();

	ComponentType GetType() const override;

	void OnNotify(EventData* data) override;	//Listens for the event of the goals

	Text* player1Text;
	Text* player2Text;
	Ball* ball;
	BallMovement* ballMovement;

private:
	int player1Score;
	int player2Score;
};