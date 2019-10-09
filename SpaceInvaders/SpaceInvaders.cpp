#include <iostream>
#include <vector>
#include <string>
#ifdef _WIN32
#include <windows.h>
#include <cwchar>
#else
#include <ncurses.h>
#endif

const auto CONSTANT_PIXEL_WIDTH = 2;
const std::vector<std::vector<std::string>> spriteAtlas
{
	{
		"      ████      ",
		"    ████████    ",
		"  ████████████  ",
		"████  ████  ████",
		"████████████████",
		"  ██  ████  ██  ",
		"██            ██",
		"  ██        ██  "
	},
	{
		"      ████      ",
		"    ████████    ",
		"  ████████████  ",
		"████  ████  ████",
		"████████████████",
		"    ██    ██    ",
		"  ██  ████  ██  ",
		"██  ██    ██  ██"
	},
	{
		"    ██          ██    ",
		"      ██      ██      ",
		"    ██████████████    ",
		"  ████  ██████  ████  ",
		"██  ██████████████  ██",
		"██  ██████████████  ██",
		"    ██          ██    ",
		"      ████  ████      "
	},
	{
		"    ██          ██    ",
		"██    ██      ██    ██",
		"██  ██████████████  ██",
		"██████  ██████  ██████",
		"  ██████████████████  ",
		"  ██████████████████  ",
		"    ██          ██    ",
		"  ██              ██  "
	},
	{
		"        ████████        ",
		"  ████████████████████  ",
		"████████████████████████",
		"██████    ████    ██████",
		"████████████████████████",
		"      ████    ████      ",
		"    ████  ████  ████    ",
		"████                ████"
	},
	{
		"        ████████        ",
		"  ████████████████████  ",
		"████████████████████████",
		"██████    ████    ██████",
		"████████████████████████",
		"    ██████    ██████    ",
		"  ████    ████    ████  ",
		"    ████        ████    "
	}
};

void gotoxy(int x, int y);

struct Vector2
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

class Transform
{
public:
	Vector2 position;
};

class Sprite : public Transform
{
public:
	std::vector<std::vector<std::string>> frames;

	Sprite() : Transform() {
		size.x = 22;
		size.y = 8;
	}

	void DrawSprite(int frame) {
		for (int i{ 0 }; i < size.y; i++) {
			gotoxy(position.x, position.y + i);
			std::cout << frames[frame][i];
		}
	}
protected:
	Vector2 size;
};

void gotoxy(int x, int y)
{
	static HANDLE _h = nullptr;

	if (!_h)
	{
		_h = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD _c = { x, y };
	SetConsoleCursorPosition(_h, _c);
}

void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &info);
}

class Enemy : public Sprite {
public:
	Enemy() {
		
	}

	void Shoot() {

	}

	void KillEnemy() {

	}
};

class Player : public Sprite {
public:
	Player() {

	}

	void Shoot() {

	}

	void KillPlayer() {

	}
};

class FrameBuffer {
public:
	Vector2 screenSize;
	std::vector<std::string> frame;

	FrameBuffer()
	{
		frame[0].push_back(char(""));
	}

	void DrawFrame()
	{
		for (int y{ 0 }; y < screenSize.y; y++)
		{
			std::cout << frame[y] << '\n';
		}

		memset(&frame, 0, frame.size());
	}
};

int main()
{
	// TODO : Make the game in layers. take input, do calculations,
	//        then putt new shit in the frame buffer, then draw the new frame


	int in{ 0 };
	Sprite enemySmall[11], enemy[11], enemyBig[11];

	for (int i{ 0 }; i < 11; i++)
	{
		enemySmall[i].frames.push_back(spriteAtlas[2]);
		enemySmall[i].frames.push_back(spriteAtlas[3]);
		enemySmall[i].position.x = i * 30 + 6;
		enemySmall[i].position.y = 2;

		//enemy[i].position.x = i * 30 + 4;
		//enemy[i].position.y = 12;

		//enemyBig[i].position.x = i * 30 + 2;
		//enemyBig[i].position.y = 22;
	}
	
	HideCursor();

	while (true)
	{
		for (int i{ 0 }; i < 11; i++)
		{
			enemySmall[i].DrawSprite(in);
		}

		/*for (int i{ 0 }; i < 11; i++)
		{
			enemy[i].DrawSprite(in + 2);
		}

		for (int i{ 0 }; i < 11; i++)
		{
			enemyBig[i].DrawSprite(in + 4);
		}*/

		in++;

		Sleep(1000);

		if (in > 1)
		{
			in = 0;
		}
	}

	system("pause");
}