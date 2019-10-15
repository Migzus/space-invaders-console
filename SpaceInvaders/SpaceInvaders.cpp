#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <cwchar>
#else
#include <ncurses.h>
#endif

const char WHITE[9]{ 0x1b, '[', '0', '0', ';', '3', '9', 'm', 0 };
const char LIME[9]{ 0x1b, '[', '0', '1', ';', '3', '2', 'm', 0 };

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
	},
	{
		"██",
		"██",
		"██",
		"██"
	},
	{
		"        ██      ██        ",
		"  ██      ██  ██      ██  ",
		"    ██              ██    ",
		"      ██          ██      ",
		"████                  ████",
		"      ██          ██      ",
		"    ██              ██    ",
		"  ██      ██  ██      ██  ",
		"        ██      ██        "
	},
	{
		"    ██",
		"  ██  ",
		"██    ",
		"  ██  ",
		"    ██",
		"  ██  ",
		"██    "
	},
	{
		"██    ",
		"  ██  ",
		"    ██",
		"  ██  ",
		"██    ",
		"  ██  ",
		"    ██"
	}
};

void gotoxy(int x, int y);

typedef struct console_info {
	ULONG cbSize;
	DWORD nFont;
	COORD dwFontSize;
	UINT  FontFamily;
	UINT  FontWeight;
	WCHAR FaceName[LF_FACESIZE];
};

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

class Sprite : public Transform
{
public:
	size_t waitFrames{ 40 }, currentWaitFrame{ 0 };
	std::vector<std::string> pixelChar;

	Sprite() : Transform() {
		//m_size.x = 22;
		//m_size.y = 8;
	}

	void SetSprite(int spriteAtlasIndex) {
		pixelChar.resize(spriteAtlas[spriteAtlasIndex].size());

		for (int y{ 0 }; y < spriteAtlas[spriteAtlasIndex].size(); y++)
		{
			pixelChar[y] = spriteAtlas[spriteAtlasIndex][y];
		}
	}

	void PlayAnimation()
	{
		if (currentWaitFrame > waitFrames)
		{
			if (m_currentFrame >= m_frameLength)
			{
				m_currentFrame = 0;
			}

			m_currentFrame++;
			SetSprite(m_currentFrame + 1);
			currentWaitFrame = 0;
		}
		else
		{
			currentWaitFrame++;
		}
	}

	void set_FrameLength(size_t p_newLength)
	{
		m_frameLength = p_newLength;
	}

private:
	//Vector2 m_size;
	size_t m_currentFrame{ 0 }, m_frameLength{ 2 };
};

void gotoxy(int x, int y)
{
	static HANDLE _h = nullptr;

	if (!_h)
	{
		_h = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD _c = { short(x), short(y) };
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

class Enemy {
public:
	Sprite sprite;
	BoxCollider collider;

	Enemy() {
		
	}

	void RunAnimation() {
		
	}

	void Shoot() {

	}

	void KillEnemy() {

	}
};

class Player {
public:
	Sprite sprite;
	BoxCollider collider;

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
		screenSize.y = 50;
		screenSize.x = 90;

		ConfigureScreen();
	}

	void InsertSprite(Sprite* p_sprite)
	{
		for (unsigned int y{ 0 }; y < p_sprite->pixelChar.size(); y++)
		{
			//frame[p_sprite->position.y + y].insert(p_sprite->position.x, p_sprite->pixelChar[y]);
			frame[int(round(p_sprite->position.y)) + y].replace(int(round(p_sprite->position.x / CONSTANT_PIXEL_WIDTH) * CONSTANT_PIXEL_WIDTH), p_sprite->pixelChar[0].size() - 8, p_sprite->pixelChar[y]);
		}
	}

	void DrawFrame()
	{
		for (int y{ 0 }; y < screenSize.y; y++)
		{
			// draw green from 40 and down
			std::cout << (y == 40 ? LIME : "") << frame[y] << '\n';
		}
		
		std::cout << WHITE;

		ConfigureScreen();

		//memset(&frame, 0, frame.size());
	}
private:
	void ConfigureScreen()
	{
		frame.clear();

		frame.resize(screenSize.y);

		for (int y{ 0 }; y < screenSize.y; y++)
		{
			frame[y].resize(screenSize.x * CONSTANT_PIXEL_WIDTH, ' ');
		}
	}
};

int main()
{
	// TODO : Make the game in layers. take input, do calculations,
	//        then putt new shit in the frame buffer, then draw the new frame
	console_info consoleInfo;
	FrameBuffer buffer;

	// modify this variable to modify the speed of the controlled element
	float speed{ 0.4f };

	int in{ 0 };
	Sprite enemySmall[3]; //, enemy[11], enemyBig[11];

	// Prepare Colours
	std::cout << WHITE;
	system("cls");

	// Set the console window do fullscreenMode
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	// Handle console fontsize and standard supported font
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.Y = 10;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	enemySmall[0].SetSprite(0);
	enemySmall[1].SetSprite(0);
	enemySmall[2].SetSprite(2);

	enemySmall[0].position.y = 1;

	enemySmall[1].position.y = 40;
	enemySmall[1].position.x = 136;

	enemySmall[2].position.y = 1;
	enemySmall[2].position.x = 50;

	enemySmall[1].currentWaitFrame = 15;

	// Game loop
	while (true)
	{
		HideCursor();

		//enemySmall[0].position.x += CONSTANT_PIXEL_WIDTH;
		//enemySmall[1].position.x += CONSTANT_PIXEL_WIDTH;

		//enemySmall[0].SetSprite(in);
		//enemySmall[1].SetSprite(in);

		enemySmall[0].PlayAnimation();
		enemySmall[1].PlayAnimation();

		buffer.InsertSprite(&enemySmall[2]);
		buffer.InsertSprite(&enemySmall[1]);
		buffer.InsertSprite(&enemySmall[0]);

		gotoxy(0, 0);
		buffer.DrawFrame();

		in++;

		if (GetKeyState(VK_UP) & 0x8000)
		{
			enemySmall[0].position.y -= speed;
		}
		else if (GetKeyState(VK_DOWN) & 0x8000)
		{
			enemySmall[0].position.y += speed;
		}
		else if (GetKeyState(VK_LEFT) & 0x8000)
		{
			enemySmall[0].position.x -= speed * CONSTANT_PIXEL_WIDTH;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			enemySmall[0].position.x += speed * CONSTANT_PIXEL_WIDTH;
		}

		if (in > 1)
		{
			in = 0;
		}
	}

	/*for (int i{ 0 }; i < 11; i++)
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
	
	while (true)
	{
		/*for (int i{ 0 }; i < 11; i++)
		{
			enemySmall[i].DrawSprite(in);
			enemySmall[i].position.y += 10;
		}

		for (int i{ 0 }; i < 11; i++)
		{
			enemy[i].DrawSprite(in + 2);
		}

		for (int i{ 0 }; i < 11; i++)
		{
			enemyBig[i].DrawSprite(in + 4);
		}

		in++;

		Sleep(1000);

		if (in > 1)
		{
			in = 0;
		}

		
	}*/

	system("pause");

	return 0;
}