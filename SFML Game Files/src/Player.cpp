#include "Player.h"

Player::Player(InitResources& res)
	:standAnim(player), walkAnim(player), jumpAnim(player), dashAnim(player), res(res)
{
	// Setting the player
	player.setTexture(res.player);
	player.setPosition(300, 200);

	velocity.x = 0.0;
	velocity.y = 0.0;

	InitFrames();
}

void Player::InitFrames()
{
		// Adding standing animation frames
	standAnim.AddFrame({IntRect(0, 0, 84, 108), display_speed});

		// Adding walking animation frames
	for (int i = 0; i <= 5; i++)
		walkAnim.AddFrame({ IntRect(72 * i + 90, 0, 72, 108), display_speed });

		// Adding jumping animation frames
	for (int i = 0; i <= NULL; i++)
		jumpAnim.AddFrame({ IntRect(2, i, width, height), NULL });
	
		// Adding dash animation frames
	for (int i = 0; i <= NULL; i++)
		dashAnim.AddFrame({ IntRect(3, i, width, height), NULL });
}

Player::~Player()
{
	/*
	
	--------------------------------
	Destrucor Poem:

		Roses are red,
		life has no meaning,
		voices in my head
		are constantly screaming.
	--------------------------------

	picardia.png

	*/
}

void Player::HandleInputs(double dt)
{
	velocity.x = 0.0f;

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (!faceRight)
		{
			player.setScale(1.0f, 1.0f);
			player.move(-90.0f, 0.0f);
		}
		else velocity.x += 0.3f;

		faceRight = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (faceRight)
		{
			player.setScale(-1.0f, 1.0f);
			player.move(90.0f, 0.0f);
		}
		else velocity.x -= 0.3f;

		faceRight = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (velocity.y == 0.0f && velocity.y < jump_height)
			velocity.y = -sqrt(2.0f * gravity * jump_height);
	}

	if (velocity.y != 0.0f && velocity.y < 1.0f)
		velocity.y += gravity * dt;
	else velocity.y = 0.0f;
}

void Player::DisplayAnimations(double dt)
{
	if (velocity.x == 0.0f && velocity.y == 0.0f) standAnim.Update(dt, false);
	else if (velocity.x != 0.0f && velocity.y == 0.0f) walkAnim.Update(dt, true);
}

void Player::Render(RenderWindow& window, double dt)
{
	//if (PlayerIsWalking(dt)) walkAnim.Update(dt, true);
	//else PlayerIsStanding(dt);

	HandleInputs(dt);
	DisplayAnimations(dt);

	player.move(velocity.x, velocity.y);
	window.draw(player);
}
