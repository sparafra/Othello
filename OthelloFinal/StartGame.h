#ifndef STARTGAME_
#define STARTGAME_

#include "Board.h"
#include "allegro5/allegro_color.h"
#include "Form.h"
#include "Button.h"
#include <string>
#include <vector>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

using namespace std;

class StartGame
{
private:
	int Width;
	int Height;
	Form* F;
	vector<Button*> ButtonVector;
	ALLEGRO_COLOR BoardColor;
	ALLEGRO_BITMAP* Skin;
	ALLEGRO_FONT *font;
	Board* BoardGame;
	Disc* Player1;
	Disc* Player2;

	

public:
	StartGame(ALLEGRO_FONT* Font, string SkinPath, ALLEGRO_COLOR Player1Color, ALLEGRO_COLOR Player2Color, Form* form);
	StartGame(ALLEGRO_FONT* Font, ALLEGRO_COLOR BoardC, ALLEGRO_COLOR Player1Color, ALLEGRO_COLOR Player2Color, Form* form);
	~StartGame();
	vector<Button*> getButtons() { return ButtonVector; };
	void drawTimer(int sec, Form* form);
	void drawDiscBoard(Disc* D, int Riga, int Col);
	void drawDiscBoard(Disc* D, int Riga, int Col, bool Transparent);
	void drawCurrentPlayer(int Player, Form* form);
	void drawScore(int Player1Score, int Player2Score, Form* form);
	void clearDiscBoard(int R, int Riga, int Col, bool Transparent);
	int getBoardDimension() { return BoardGame->getDim(); };
	Board* getBoard() { return BoardGame; };
	Form* getForm() { return F; };
	void drawDiscBoard(Disc* P1, Disc* P2, int** M, int Size);
	void clearAllDiscBoard(int** M, int Size);
};
#endif // !STARTGAME_
