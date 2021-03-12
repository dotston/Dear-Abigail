#include "Kinematics.h"
#include "ECS.h"

void Kinematics::UpdatePosition()
{
	float parentX = ECS::GetComponent<PhysicsBody>(kinParent).GetPosition().x;
	float parentY = ECS::GetComponent<PhysicsBody>(kinParent).GetPosition().y;

	float childX = ECS::GetComponent<Transform>(kinChild).GetPosition().x;
	float childY = ECS::GetComponent<Transform>(kinChild).GetPosition().y;
	float childZ = ECS::GetComponent<Transform>(kinChild).GetPosition().z;

	ECS::GetComponent<PhysicsBody>(kinChild).SetPosition(b2Vec2(parentX + offsetX, parentY + offsetY), true);
}

void Kinematics::SetParent(int parent)
{
	kinParent = parent;
}

void Kinematics::SetChild(int child)
{
	kinChild = child;
}

void Kinematics::SetOffset(float x, float y)
{
	offsetX = x;
	offsetY = y;
}