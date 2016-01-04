#include "Component.h"


Component::Component()
{
}

Component::Component(std::shared_ptr<Entity> owner) : owner(owner)
{
}

Component::~Component()
{
}




