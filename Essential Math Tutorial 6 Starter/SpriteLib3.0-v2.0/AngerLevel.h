#pragma once 
#include "Scene.h" 
#include "PhysicsPlayground.h"

class AngerLevel : public Scene
{
public:
	AngerLevel(std::string name);

	void InitScene(float windowWidth, float windowHeight) override;

	void Update() override;

	//Input overrides
	void KeyboardHold() override;
	void KeyboardDown() override;
	void KeyboardUp() override;

	void ReattachCamera();

	/*void Defeated();*/

	void CheckShield();

	void ChangeVisualState(int shadowEntity);

	void SpawnBullet(int shadowEntity);
	void ShootBullet();

	void ActivateShadow();

	void MovePlatform();

	void PlayerDeath();

	void MouseClick(SDL_MouseButtonEvent evnt);

	void UpdatePositionWithCamera(int cameraEntity, int spriteEntity, int tempOffsetX, int tempOffsetY);

	void UpdateUI();

	std::string defaultPose = "testCube.png";
	std::string attackPose = "testCube2.png";
	bool switchDir = false;
	int bossPlatforms[5] = { 0,0,0,0,0 };

	int cPlatforms[4] = { 0,0,0,0 };
	int cTriggers[4] = { 0,0,0,0 };
	void CrumblingPlatforms(int entity);
	int flyingPieces[6] = { 0, 0, 0, 0, 0, 0 };
protected:
	PhysicsPlaygroundListener listener;
	vec3 playerVel;
	b2Vec2 playerPos;
	int player = 0;
	int camera = 0;
	int shadows[6];
	int enemy1 = 0, enemy2 = 0, enemy3 = 0, enemy4 = 0, enemy5 = 0, enemy6 = 0;
	int bossWall = 0; //aka
	bool bossWallDestroyed = false;
	int shield = 0;
	int bullet = 0;
	int boss = 0;
	int movingPlat = 0;
	int kinTrigger = 0;
	bool allShadowsDefeated = true;
	bool canMove = true; //turns false for a few seconds when the player hits a Shadow and gets knocked back
	int breakableWalls[1] = { 0 };
	int breakableWallTriggers[1] = { 0 };
	int testSprites[3] = { 0,0,0 };
	int shieldUI = 0;
	int attackUI = 0;
	int ouchUI = 0;
};