#include "Game/Private/GameObjects/Components/Behaviours/Player/Player2.h"

Player2::Player2(GameObject* gameObject)
	: Player(gameObject)
{

}

Player2::~Player2()
{

}

ComponentType Player2::GetType() const
{
	return ComponentType::Player1;
}

void Player2::Awake()
{
	Transform& transform = gameObject->GetTransform();

	transform.SetPosition(Vector2(770, 300));
}

void Player2::ReadInput()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState(&nKeys);

	if (pState[SDL_SCANCODE_UP]) {

		vertical = -1;
	}
	else if (pState[SDL_SCANCODE_DOWN]) {

		vertical = 1;
	}
	else {

		vertical = 0;
	}
}