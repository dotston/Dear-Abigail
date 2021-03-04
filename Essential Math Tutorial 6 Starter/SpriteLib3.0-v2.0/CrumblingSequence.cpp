#include "CrumblingSequence.h"
#include <string>

void CrumblingSequence::Crumble()
{
	auto& sprite = ECS::GetComponent<Sprite>(entity);
	std::string spritesheet = "spritesheets/crumblingPlatform.png";
	std::string animations = "crumble.json";

	if (sequenceStart == false)
	{
		startTime = Timer::time;
	}
	float currentTime = Timer::StopWatch(startTime);
	if (sequenceStart == true)
	{
		if (currentTime < 3)
		{
			sprite.LoadSprite(spritesheet, sprite.GetWidth(), sprite.GetHeight());
		}
		else if (currentTime >= 3 && currentTime < 5)
		{
			operation = 1;
			disable = true;
		}
		else if (currentTime >= 5)
		{
			operation = 0;
			disable = true;
			startTime = 0;
			sequenceStart = false;
		}
	}
	
}

void CrumblingSequence::setEntity(int newEntity)
{
	entity = newEntity;
}

void CrumblingSequence::setSequenceStart(bool start)
{
	sequenceStart = start;
}

bool CrumblingSequence::getSequenceStart()
{
	return sequenceStart;
}

int CrumblingSequence::disablePlatform()
{
	if (disable == true)
	{
		return operation;
	}
	else
	{
		return -1;
	}
}

