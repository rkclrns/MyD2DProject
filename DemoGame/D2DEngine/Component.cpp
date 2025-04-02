#include "pch.h"
#include "Component.h"

Component::Component(eComponentType type)
	: mType(type)
{
	mState = eComponentState::ACTIVE;
}

Component::~Component()
{

}

void Component::Initialize()
{

}
