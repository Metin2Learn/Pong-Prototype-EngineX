#include "Game/Private/GameObjects/Components/Behaviours/Player/Player1.h"

Player1::Player1(GameObject* gameObject)
	: Player(gameObject)
{

}

Player1::~Player1()
{

}

ComponentType Player1::GetType() const
{
	return ComponentType::Player1;
}

void Player1::Awake()
{
	Transform& transform = gameObject->GetTransform();

	transform.SetPosition(Vector2(30, 300));
}

void Player1::ReadInput()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState(&nKeys);

	if (pState[SDL_SCANCODE_W]) {

		vertical = -1;
	}
	else if (pState[SDL_SCANCODE_S]) {

		vertical = 1;
	}
	else {

		vertical = 0;
	}
}