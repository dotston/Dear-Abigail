#include "ShadowTriggers.h"
#include "ECS.h"

void ShadowAreaTrigger::OnEnter()
{
	//each trigger has a specific integer value set in DenialRough.cpp
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowLoc(Trigger::GetShadowZone());
	//^^^changes the value of shadowLoc(found in ShadowSense) to equal the integer value of the trigger
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowSequence(true); //starts the timer in ShadowTime
	//ECS::GetComponent<ShadowLoop>(m_targetEntities[0]).SetShadowSequence(true); //starts the timer in ShadowTime
	ECS::GetComponent<ShadowLoop>(m_targetEntities[0]).SetShadowSequence(true);	
}

void ShadowAreaTrigger::OnExit()
{
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowLoc(0); //sets the shadowLoc back to 0. 0 indicates that the player is not within range of a shadow.
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowSequence(false); //ends the timer in ShadowTime
	//ECS::GetComponent<ShadowLoop>(m_targetEntities[0]).SetShadowSequence(false); //starts the timer in ShadowTime
	ECS::GetComponent<ShadowLoop>(m_targetEntities[0]).SetShadowSequence(false);	
}

void BossAreaTrigger::OnEnter()
{
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowLoc(Trigger::GetShadowZone());
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowSequence(true); 
}

void BossAreaTrigger::OnExit()
{
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowLoc(0); 
	ECS::GetComponent<PlayerMechanics>(MainEntities::MainPlayer()).SetShadowSequence(false); 
}