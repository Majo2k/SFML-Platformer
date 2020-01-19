#pragma once

#include "Animation.h"
#include "InitResources.h"

class Player
{
private:
	// SFML objects
	Sprite player;

	// Program objects
	Animation standAnim;
	Animation walkAnim;
	Animation jumpAnim;
	Animation dashAnim;

	// Class veriables
	int height = 114;
	int width = 124;
	double display_speed = 0.1;
	Vector2u player_size;

	Vector2f velocity;
	float movement_speed = 0.3f;
	const double jump_time = 0.3;
	double progress{};
	const double gravity = 1.1;
	bool faceRight = true;
	bool can_jump = true;

private:
	// Class funtions
	void HandleInputs(double dt);
	void DisplayAnimations(double dt);

	// Initializing functions used in constructor
	void InitFrames();
	InitResources& res;

public:
	// Constructor, destructor, main function
	Player(InitResources& res);
	~Player();
	void Render(RenderWindow& window, double dt);

};

