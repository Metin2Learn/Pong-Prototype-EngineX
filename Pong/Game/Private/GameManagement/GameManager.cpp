//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameManagement/GameManager.h"
#include "Game/Private/GameManagement/GameController.h"

#include "Game/Private/GameObjects/Prefabs/Ball.h"
#include "Game/Private/GameObjects/Prefabs/Paddle.h"
#include "Game/Private/GameObjects/Components/Behaviours/Player/Player1.h"
#include "Game/Private/GameObjects/Components/Behaviours/Player/Player2.h"
#include "Game/Private/GameObjects/Prefabs/Wall.h"
#include "Game/Private/GameObjects/Prefabs/GoalGO.h"
#include "Game/Private/GameObjects/Components/Behaviours/Goal/Goal.h"
#include "Game/Private/GameObjects/Components/Renderers/Text/Text.h"
#include "Game/Private/GameObjects/Components/Renderers/Renderer.h"
#include "Game/Private/GameObjects/Components/Behaviours/Ball/BallMovement.h"

//Setting up the game
GameManager::GameManager()
{
	GameController* gameController = new GameController(this);
	AddComponent(gameController);

	exColor color;
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
	color.mColor[3] = 255;

	GameObject* text1GO = new GameObject();
	Renderer* renderer1 = new Renderer(text1GO);
	Text* text1 = new Text();
	text1->text = "0";
	renderer1->SetRenderable(text1);
	renderer1->SetColor(color);
	text1GO->AddComponent(renderer1);
	text1GO->GetTransform().SetPosition(Vector2(200, 100));

	GameObject* text2GO = new GameObject();
	Renderer* renderer2 = new Renderer(text2GO);
	Text* text2 = new Text();
	text2->text = "0";
	renderer2->SetRenderable(text2);
	renderer2->SetColor(color);
	text2GO->AddComponent(renderer2);
	text2GO->GetTransform().SetPosition(Vector2(500, 100));

	gameController->player1Text = text2;
	gameController->player2Text = text1;

	Ball* ball1 = new Ball();
	gameController->ballMovement = ball1->GetComponent<BallMovement>();
	gameController->ball = ball1;

	Paddle* paddle1 = new Paddle();
	paddle1->AddComponent(new Player1(paddle1));

	Paddle* paddle2 = new Paddle();
	paddle2->AddComponent(new Player2(paddle2));

	Wall* upperWall = new Wall();
	upperWall->GetTransform().SetPosition(Vector2(400, 0));

	Wall* lowerWall = new Wall();
	lowerWall->GetTransform().SetPosition(Vector2(400, 600));

	GoalGO* leftGoal = new GoalGO("LeftGoal");
	leftGoal->GetTransform().SetPosition(Vector2(-20, 300));
	Goal* goal1 = leftGoal->GetComponent<Goal>();
	goal1->AddListener(gameController);

	GoalGO* rightGoal = new GoalGO("RightGoal");
	rightGoal->GetTransform().SetPosition(Vector2(820, 300));
	Goal* goal2 = rightGoal->GetComponent<Goal>();
	goal2->AddListener(gameController);
}

GameManager::~GameManager()
{

}