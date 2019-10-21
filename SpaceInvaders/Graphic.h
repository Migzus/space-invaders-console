#pragma once

const char GRAY[9]{ 0x1b, '[', '0', '0', ';', '3', '0', 'm', 0 };
const char RED[9]{ 0x1b, '[', '0', '0', ';', '3', '1', 'm', 0 };
const char GREEN[9]{ 0x1b, '[', '0', '0', ';', '3', '2', 'm', 0 };
const char YELLOW[9]{ 0x1b, '[', '0', '0', ';', '3', '3', 'm', 0 };
const char BLUE[9]{ 0x1b, '[', '0', '0', ';', '3', '4', 'm', 0 };
const char MAGENTA[9]{ 0x1b, '[', '0', '0', ';', '3', '5', 'm', 0 };
const char CYAN[9]{ 0x1b, '[', '0', '0', ';', '3', '6', 'm', 0 };
const char SILVER[9]{ 0x1b, '[', '0', '0', ';', '3', '7', 'm', 0 };

const char LIGHT_GRAY[9]{ 0x1b, '[', '0', '1', ';', '3', '0', 'm', 0 };
const char LIGHT_RED[9]{ 0x1b, '[', '0', '1', ';', '3', '1', 'm', 0 };
const char LIME[9]{ 0x1b, '[', '0', '1', ';', '3', '2', 'm', 0 };
const char LIGHT_YELLOW[9]{ 0x1b, '[', '0', '1', ';', '3', '3', 'm', 0 };
const char LIGHT_BLUE[9]{ 0x1b, '[', '0', '1', ';', '3', '4', 'm', 0 };
const char LIGHT_MAGENTA[9]{ 0x1b, '[', '0', '1', ';', '3', '5', 'm', 0 };
const char LIGHT_CYAN[9]{ 0x1b, '[', '0', '1', ';', '3', '6', 'm', 0 };
const char WHITE[9]{ 0x1b, '[', '0', '1', ';', '3', '7', 'm', 0 };

const char GRAY_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '0', 'm', 0 };
const char RED_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '1', 'm', 0 };
const char GREEN_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '2', 'm', 0 };
const char YELLOW_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '3', 'm', 0 };
const char BLUE_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '4', 'm', 0 };
const char MAGENTA_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '5', 'm', 0 };
const char CYAN_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '6', 'm', 0 };
const char WHITE_INVERTED[9]{ 0x1b, '[', '0', '7', ';', '3', '7', 'm', 0 };

const auto CONSTANT_PIXEL_WIDTH = 2;
const std::vector<std::vector<std::string>> spriteAtlas
{
	{
		"      XXXX      ",
		"    XXXXXXXX    ",
		"  XXXXXXXXXXXX  ",
		"XXXX  XXXX  XXXX",
		"XXXXXXXXXXXXXXXX",
		"  XX  XXXX  XX  ",
		"XX            XX",
		"  XX        XX  "
	},
	{
		"      XXXX      ",
		"    XXXXXXXX    ",
		"  XXXXXXXXXXXX  ",
		"XXXX  XXXX  XXXX",
		"XXXXXXXXXXXXXXXX",
		"    XX    XX    ",
		"  XX  XXXX  XX  ",
		"XX  XX    XX  XX"
	},
	{
		"    XX          XX    ",
		"      XX      XX      ",
		"    XXXXXXXXXXXXXX    ",
		"  XXXX  XXXXXX  XXXX  ",
		"XX  XXXXXXXXXXXXXX  XX",
		"XX  XXXXXXXXXXXXXX  XX",
		"    XX          XX    ",
		"      XXXX  XXXX      "
	},
	{
		"    XX          XX    ",
		"XX    XX      XX    XX",
		"XX  XXXXXXXXXXXXXX  XX",
		"XXXXXX  XXXXXX  XXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXX",
		"  XXXXXXXXXXXXXXXXXX  ",
		"    XX          XX    ",
		"  XX              XX  "
	},
	{
		"        XXXXXXXX        ",
		"  XXXXXXXXXXXXXXXXXXXX  ",
		"XXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXX    XXXX    XXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXX",
		"      XXXX    XXXX      ",
		"    XXXX  XXXX  XXXX    ",
		"XXXX                XXXX"
	},
	{
		"        XXXXXXXX        ",
		"  XXXXXXXXXXXXXXXXXXXX  ",
		"XXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXX    XXXX    XXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXX",
		"    XXXXXX    XXXXXX    ",
		"  XXXX    XXXX    XXXX  ",
		"    XXXX        XXXX    "
	},
	{
		"XX",
		"XX",
		"XX",
		"XX"
	},
	{
		"        XX      XX        ",
		"  XX      XX  XX      XX  ",
		"    XX              XX    ",
		"      XX          XX      ",
		"XXXX                  XXXX",
		"      XX          XX      ",
		"    XX              XX    ",
		"  XX      XX  XX      XX  ",
		"        XX      XX        "
	},
	{
		"    XX",
		"  XX  ",
		"XX    ",
		"  XX  ",
		"    XX",
		"  XX  ",
		"XX    "
	},
	{
		"XX    ",
		"  XX  ",
		"    XX",
		"  XX  ",
		"XX    ",
		"  XX  ",
		"    XX"
	},
	{
		"              XX              ",
		"            XXXXXX            ",
		"            XXXXXX            ",
		"            XXXXXX            ",
		"  XXXXXXXXXXXXXXXXXXXXXXXXXX  ",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	},
	{
		"  XXXXXXXX    XXXXXXXX    XXXXXX    XXXXXXXX    XXXXXXXXXX",
		"XX          XX          XX      XX  XX      XX  XX        ",
		"  XXXXXX    XX          XX      XX  XXXXXXXX    XXXXXX    ",
		"        XX  XX          XX      XX  XX      XX  XX        ",
		"XXXXXXXX      XXXXXXXX    XXXXXX    XX      XX  XXXXXXXXXX"
	},
	{
		"XX          XX  XX      XX  XXXXXXXXXX    XXXXXXXX",
		"XX          XX  XX      XX  XX          XX        ",
		"XX          XX  XX      XX  XXXXXX        XXXXXX  ",
		"XX          XX    XX  XX    XX                  XX",
		"XXXXXXXXXX  XX      XX      XXXXXXXXXX  XXXXXXXX  "
	}
};

const std::vector<std::vector<std::string>> numberAtlas
{
	{
		"  XXXXXX  ",
		"XX      XX",
		"XX      XX",
		"XX      XX",
		"  XXXXXX  "
	},
	{
		"XXXX",
		"  XX",
		"  XX",
		"  XX",
		"  XX"
	},
	{
		"  XXXXXX  ",
		"XX      XX",
		"     XX   ",
		"  XX      ",
		"XXXXXXXXXX"
	},
	{
		"  XXXXXX  ",
		"XX      XX",
		"    XXXX  ",
		"XX      XX",
		"  XXXXXX  "
	},
	{
		"  XX    XX",
		"XX      XX",
		"XXXXXXXXXX",
		"        XX",
		"        XX"
	},
	{
		"XXXXXXXX  ",
		"XX        ",
		"XXXXXXXX  ",
		"        XX",
		"  XXXXXX  "
	},
	{
		"  XXXXXX  ",
		"XX        ",
		"XXXXXXXX  ",
		"XX      XX",
		"  XXXXXX  "
	},
	{
		"XXXXXXXXXX",
		"        XX",
		"      XX  ",
		"    XX    ",
		"    XX    "
	},
	{
		"  XXXXXX  ",
		"XX      XX",
		"  XXXXXX  ",
		"XX      XX",
		"  XXXXXX  "
	},
	{
		"  XXXXXX  ",
		"XX      XX",
		"  XXXXXXXX",
		"        XX",
		"  XXXXXX  "
	}
};