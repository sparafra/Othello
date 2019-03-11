#ifndef GESTIONEGIOCO_H
#define GESTIONEGIOCO_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "Button.h"
#include "Form.h"
#include "StartMenu.h"
#include "Settings.h"
#include "StartGame.h"
#include <vector>
#include "CoreOthello.h"

using namespace std;

class GestioneGioco
{
private:
	vector<string> SkinsFile;
	vector<string> SkinsPath;
	const string fontfile = "Risorse/Font/Font.ttf";
	const string SelectionSxImageFile = "Risorse/Sx.png";
	const string SelectionDxImageFile = "Risorse/Dx.png";

	string FontPath;
	string SelectionSxPath;
	string SelectionDxPath;

	
	int sec;
	ALLEGRO_TIMER* timer = NULL;

	ALLEGRO_FONT *font;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_COLOR BoardColor;
	bool BoardColorSelected;
	ALLEGRO_COLOR Disc1Color;
	ALLEGRO_COLOR Disc2Color;
	int IndexSkin;
	bool Multiplayer;
	Disc* DiscPlayer1;
	Disc* DiscPlayer2;
	string Path;
	bool timerActive;
	Form* F;
	
	bool GameOver;

	void MenuLoad(ALLEGRO_EVENT_QUEUE *event_queue, bool SkinBackground);
	void SettingsLoad(ALLEGRO_EVENT_QUEUE *event_queue);
	void GameLoad(ALLEGRO_EVENT_QUEUE *event_queue);

	void Init();
public:
	GestioneGioco(string Directory);
	~GestioneGioco();
	void Start();
	
};
#endif