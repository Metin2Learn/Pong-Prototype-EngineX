//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/DesignPatterns/Observer/Notifier.h"
#include "Game/Private/DesignPatterns/Observer/Observer.h"

Notifier::Notifier() {

	observers = new std::vector<Observer*>();
}

Notifier::~Notifier() {

	delete observers;
}

void Notifier::AddListener(Observer* observer) {

	observers->push_back(observer);
}

void Notifier::RemoveListener(Observer* observer) {

	for (unsigned int i = 0; i < observers->size(); i++)
	{
		if (observer == observers->at(i)) {

			observers->erase(observers->begin() + i);
			break;
		}
	}
}

void Notifier::Notify(EventData* data) const {

	for (unsigned int i = 0; i < observers->size(); i++)
	{
		observers->at(i)->OnNotify(data);
	}
}