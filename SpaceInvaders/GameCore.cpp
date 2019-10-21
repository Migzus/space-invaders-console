#include "GameCore.h"

template<class T, class U> U clamp(U value, T min, T max) {
	return value < min ? min : value > max ? max : value;
}

void ConsoleSetup()
{
	// set new random values per second
	srand(time(nullptr));

	// Set the console window do fullscreenMode
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	// Handle console fontsize and standard supported font
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.Y = 10;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HideCursor();

	// Prepare Colours
	std::cout << WHITE;
	system("cls");
	std::cout << WHITE;
}

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

void Sprite::SetSprite(int spriteAtlasIndex) {
	pixelChar.resize(spriteAtlas[spriteAtlasIndex].size());

	for (size_t y{ 0 }; y < spriteAtlas[spriteAtlasIndex].size(); y++)
	{
		pixelChar[y] = spriteAtlas[spriteAtlasIndex][y];
	}
}

void Sprite::PlayAnimation()
{
	if (currentWaitFrame > waitFrames)
	{
		if (m_currentFrame >= m_frameIDs.size())
		{
			m_currentFrame = 0;
		}

		SetSprite(m_frameIDs[m_currentFrame]);
		m_currentFrame++;
		currentWaitFrame = 0;
	}
	else
	{
		currentWaitFrame++;
	}
}

void Sprite::SetFrames(std::vector<size_t> p_newFrames)
{
	m_frameIDs = p_newFrames;
}

void Player::Movement() {
	/*if (GetKeyState(VK_UP) & 0x8000)
	{
		transform.position.y -= speed;
	}

	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		transform.position.y += speed;
	}*/

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		transform.position.x -= speed * CONSTANT_PIXEL_WIDTH;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		transform.position.x += speed * CONSTANT_PIXEL_WIDTH;
	}

	transform.position.x = clamp(transform.position.x, 2, 348);
}

void Player::Shoot(FrameBuffer* buffer) {
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		Bullet* _bullet = new Bullet;

		buffer->bulletList.push_back(*_bullet);

		delete _bullet;

		//mciSendString(L"open \"*.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		//mciSendString(L"play mp3", NULL, 0, NULL);
	}
}

void FrameBuffer::InsertObject(GameObject* p_object)
{
	for (size_t y{ 0 }; y < p_object->sprite.pixelChar.size(); y++)
	{
		int _compareVal{ int(screenSize.x * round(p_object->transform.position.y + y) + round((p_object->transform.position.x) / CONSTANT_PIXEL_WIDTH) * CONSTANT_PIXEL_WIDTH) };

		std::string _s = p_object->sprite.pixelChar[y];

		//_s.erase(0, clamp(int(round(p_object->transform.position.x) + p_object->sprite.pixelChar[y].size()), 0, 8));

		if (_compareVal < int(m_output.size()) && _compareVal >= 0)
			m_output.replace(_compareVal, p_object->sprite.pixelChar[y].size(), _s);
	}
}

void FrameBuffer::AddToRenderQueue(Sprite player) {
	renderQueue.push_back(player);
}

void FrameBuffer::DrawFrame()
{
	size_t _pos{ 0 };

	gotoxy(0, 0);

	std::cout << WHITE;

	for (int y = screenSize.y; y > 0; y--)
	{
		m_output.insert(screenSize.x * y, "\n" + std::string(y >= 80 ? LIME : WHITE));
	}

	while ((_pos = m_output.find("X")) != std::string::npos)
	{
		m_output.replace(_pos, 1, "█");
	}

	std::cout << m_output;

	ConfigureScreen();

	//memset(&frame, 0, frame.size());
}

void FrameBuffer::ConfigureScreen()
{
	m_output.clear();
	m_output.resize(screenSize.x * screenSize.y, ' ');
}