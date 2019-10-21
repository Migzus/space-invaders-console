#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <stdlib.h>
//#include <fstream>
#ifdef _WIN32
#include <windows.h>
//#include <cwchar>
#else
#include <ncurses.h>
#endif

#include "Graphic.h"

struct console_info {
	ULONG cbSize;
	DWORD nFont;
	COORD dwFontSize;
	UINT  FontFamily;
	UINT  FontWeight;
	WCHAR FaceName[LF_FACESIZE];
};

template<class T, class U> U clamp(U value, T min, T max);
void ConsoleSetup();
void gotoxy(int x, int y);
void HideCursor();

struct Vector2
{
	float x{ 0 }, y{ 0 };

	void zero()
	{
		x = y = 0;
	}

	void one()
	{
		x = y = 1;
	}
};

struct Vector2Int
{
	int x{ 0 }, y{ 0 };

	void zero()
	{
		x = y = 0;
	}

	void one()
	{
		x = y = 1;
	}
};

class BoxCollider {
public:
	Vector2 size, pivod;
protected:
private:
};

class Transform
{
public:
	Vector2 position;
};

class Sprite
{
public:
	size_t waitFrames{ 30 }, currentWaitFrame{ 0 };
	std::vector<std::string> pixelChar;

	Sprite() {

	}

	void SetSprite(int spriteAtlasIndex);
	void PlayAnimation();
	void SetFrames(std::vector<size_t> p_newLength);

private:
	size_t m_currentFrame{ 0 };
	std::vector<size_t> m_frameIDs;
};

class GameObject {
public:
	Transform transform;
	Sprite sprite;
	BoxCollider collider;
};

class Bullet : public GameObject {
public:
	float speed{ 0 };

	Bullet() {
		sprite.SetSprite(6);
	}
};

class FrameBuffer {
public:
	Vector2Int screenSize;

	// use the queue to add and render new stuff that was instantiated mid game
	std::vector<Sprite> renderQueue;
	std::vector<Bullet> bulletList;

	FrameBuffer()
	{
		// cannot pass the current resolution - TODO : fix this crap...
		screenSize.y = 107;
		screenSize.x = 380;

		ConfigureScreen();
	}

	void InsertObject(GameObject* p_object);
	void AddToRenderQueue(Sprite player);
	void DrawFrame();
private:
	std::string m_output;

	void ConfigureScreen();
};

class Enemy : public GameObject {
public:
	Enemy() {
		sprite.currentWaitFrame = rand() % sprite.waitFrames;
	}

	//void Shoot();
	//void KillEnemy();
};

class Player : public GameObject {
public:
	float speed{ 0.0f };

	Player() {
		sprite.SetSprite(10);

		speed = 1.3f;
	}

	void Shoot(FrameBuffer* buffer);
	//void KillPlayer();
	void Movement();
};

class UIText {
	std::string text{ "2" };
	Transform transform;
	Sprite sprite;
};