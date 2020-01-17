#pragma once

#include "all_headers.h"

class InitResources
{
private:
	HWND hWnd;

	// Textures default paths
	const string
		defenti = "../res/",
		defback = "../res/";

public:
	Texture player;
	//Sound testbuff;
	//Font testfont;

public:
	InitResources();

private:
	void InitTextures();
	void InitSounds();
	void InitFonts();

	void ThrowExeption(wstring failed_resource);
};

