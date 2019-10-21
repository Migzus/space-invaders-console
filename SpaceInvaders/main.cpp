#include "GameCore.h"

int main()
{
	FrameBuffer buffer;

	const int enemySize{ 4 };

	// modify this variable to modify the speed of the controlled element
	float speed{ 0.4f }, deltaTime{ 1.0f };
	Enemy enemy[enemySize], enemyMedium[enemySize], enemyBig[enemySize];
	Player player;

	ConsoleSetup();

	for (size_t i = 0; i < enemySize; i++)
	{
		enemy[i].sprite.SetSprite(1);
		enemy[i].sprite.SetFrames({ 0, 1 });
		enemy[i].transform.position.x = 28 * float(i) + 8;
		enemy[i].transform.position.y = 14;

		enemyMedium[i].sprite.SetSprite(2);
		enemyMedium[i].sprite.SetFrames({ 2, 3 });
		enemyMedium[i].transform.position.x = 28 * float(i) + 4;
		enemyMedium[i].transform.position.y = 24;

		enemyBig[i].sprite.SetSprite(4);
		enemyBig[i].sprite.SetFrames({ 4, 5 });
		enemyBig[i].transform.position.x = 28 * float(i) + 4;
		enemyBig[i].transform.position.y = 34;
	}

	player.transform.position.x = 120;
	player.transform.position.y = 96;

	//buffer.AddToRenderQueue(player.sprite);

	// Game loop
	while (true)
	{
		for (size_t i = 0; i < enemySize; i++)
		{
			enemy[i].sprite.PlayAnimation();
			enemyMedium[i].sprite.PlayAnimation();
			enemyBig[i].sprite.PlayAnimation();

			buffer.InsertObject(&enemy[i]);
			buffer.InsertObject(&enemyMedium[i]);
			buffer.InsertObject(&enemyBig[i]);
		}

		buffer.InsertObject(&player);

		buffer.DrawFrame();

		///////////////////////////////////////////////////////////////
		
		player.Movement();
		player.Shoot(&buffer);
	}

	return 0;
}