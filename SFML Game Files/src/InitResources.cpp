#include "InitResources.h"

InitResources::InitResources() :hWnd()
{
	// ERROR Message:  "Couldn't load (wstring)"
	InitTextures();
	InitSounds();
	InitFonts();
}


void InitResources::InitTextures()
{
	if (!player.loadFromFile(defenti + "player_actions.png")) ThrowExeption(L"player textures");
}

void InitResources::InitSounds()
{

}

void InitResources::InitFonts()
{

}

void InitResources::ThrowExeption(wstring failed_resource)
{
	wchar_t buff[100];

	wstring error_message = L"Couldn't load ";
	error_message += failed_resource;
	swprintf_s(buff, 100, L"%s", error_message.c_str());

	MessageBox
	(
		hWnd,
		buff,
		L"ERROR",
		MB_OK | MB_ICONERROR
	);

	exit(EXIT_FAILURE);
}

