#include "StartGame.h"

StartGame::StartGame(ALLEGRO_FONT* Font, string SkinPath, ALLEGRO_COLOR Player1Color, ALLEGRO_COLOR Player2Color, Form* form)
{

	
	font = Font;
	Skin = al_load_bitmap(SkinPath.c_str());

	//Board
	BoardGame = new Board(88, al_map_rgb(0, 255, 0), form);

	//Current Player
	Player1 = new Disc((getBoardDimension() / 8) - (((float)(getBoardDimension() / 8) / 100) * 60), Player1Color);
	Player2 = new Disc((getBoardDimension() / 8) - (((float)(getBoardDimension() / 8) / 100) * 60), Player2Color);

	//Button Reset-Exit
	Button* Reset = new Button(5, 13, al_map_rgb(255, 255, 255), al_map_rgb(0, 0, 0), Font, 2, form); //Save
	Button* Exit = new Button(5, 13, al_map_rgb(255, 255, 255), al_map_rgb(255, 0, 0), Font, 2, form); //Save

	//Draw Board
	BoardGame->drawBoard(3, 3, form);

	//Current Player
	drawCurrentPlayer(0, form);
	al_draw_text(Font, al_map_rgb(255, 255, 255), form->getWidth() * ((float)64/100), form->getHeight() * ((float)5/100), 0, "Current Player");

	//Draw Button
	Reset->draw(60, 88.8, "Reset", form);
	Exit->draw(73.3, 88.8, "Exit", form);
	
	//Add Button To ButtonVector
	ButtonVector.push_back(Reset);
	ButtonVector.push_back(Exit);


}
StartGame::StartGame(ALLEGRO_FONT* Font, ALLEGRO_COLOR BoardC, ALLEGRO_COLOR Player1Color, ALLEGRO_COLOR Player2Color, Form* form)
{

	font = Font;

	BoardColor = BoardC;


	//Board
	BoardGame = new Board(88, al_map_rgb(0, 255, 0), form);

	//Current Player
	Player1 = new Disc(2, Player1Color, form);
	Player2 = new Disc(2, Player2Color, form);
	
	//Button Reset-Exit
	Button* Reset = new Button(5, 13, al_map_rgb(255, 255, 255), al_map_rgb(0, 0, 0), Font, 2, form); //Save
	Button* Exit = new Button(5, 13, al_map_rgb(255, 255, 255), al_map_rgb(255, 0, 0), Font, 2, form); //Save

	//Draw Board
	BoardGame->drawBoard(3, 3, form);

	//Current Player
	drawCurrentPlayer(0, form);
	al_draw_text(Font, al_map_rgb(255, 255, 255), form->getWidth() * ((float)64/100), form->getHeight() * ((float)5/100), 0, "Current Player");

	//Draw Button
	Reset->draw(60, 88.8, "Reset", form);
	Exit->draw(73.3, 88.8, "Exit", form);

	//Add Button To ButtonVector
	ButtonVector.push_back(Reset);
	ButtonVector.push_back(Exit);


}

void StartGame::drawTimer(int sec, Form* form)
{
	al_draw_filled_rectangle(form->getWidth() * ((float)60/100), form->getHeight() * ((float)68/100), form->getWidth() * ((float)73/100), form->getHeight() * ((float)72/100), al_map_rgb(255, 255, 255));
	al_draw_textf(font, al_map_rgb(255, 255, 255), form->getWidth() * ((float)64/100), form->getHeight() * ((float)70/100), ALLEGRO_ALIGN_CENTRE, "Timer: %d", sec-1);
	al_draw_textf(font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)64/100), form->getHeight() * ((float)70/100), ALLEGRO_ALIGN_CENTRE, "Timer: %d", sec);
}

void StartGame::drawDiscBoard(Disc* D, int Riga, int Col)
{
	BoardGame->drawDisc(D, Riga, Col);
}
void StartGame::drawDiscBoard(Disc* P1, Disc* P2, int** M, int Size)
{
	for (int K = 0; K < Size; K++)
	{
		for (int i = 0; i < Size; i++)
		{
			if (M[K][i] == 0)
			{
				BoardGame->drawDisc(P1, K, i);
			}
			else if (M[K][i] == 1)
			{
				BoardGame->drawDisc(P2, K, i);
			}
		}
	}
	//al_flip_display();
}
void StartGame::drawCurrentPlayer(int Player, Form* form)
{
	if (Player == 0)
	{
		Player1->drawDisc(60, 5, form);
	}
	else
	{
		Player2->drawDisc(60, 5, form);
	}
	
}
void StartGame::drawDiscBoard(Disc* D, int Riga, int Col, bool Transparent)
{
	if (Transparent)
	{
		BoardGame->drawTransparentDisc(D, Riga, Col);
	}
	else
	{
		BoardGame->drawDisc(D, Riga, Col);
	}
}
void StartGame::clearDiscBoard(int R, int Riga, int Col, bool Transparent)
{
	BoardGame->clearDisc(R, Riga, Col, Transparent);
}
void StartGame::clearAllDiscBoard(int** M, int Size)
{
	for (int K = 0; K < Size; K++)
	{
		for (int i = 0; i < Size; i++)
		{
			if (M[K][i] == 0)
			{
				BoardGame->clearDisc(Player1->getRadius(), K, i, false);
			}
			else if (M[K][i] == 1)
			{
				BoardGame->clearDisc(Player2->getRadius(), K, i, false);
			}

		}
	}
}
void StartGame::drawScore(int Player1Score, int Player2Score, Form* form)
{
	al_draw_filled_rectangle(form->getWidth() * ((float)58.5/100), form->getHeight() * ((float)15/100), form->getWidth() * ((float)96/100), form->getHeight() * ((float)20/100), al_map_rgb(255, 255, 255));
	al_draw_textf(font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)66.6/100), form->getHeight() * ((float)16.6/100), ALLEGRO_ALIGN_CENTRE, "Player 1: %d", Player1Score);
	al_draw_textf(font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)86.6/100), form->getHeight() * ((float)16.6/100), ALLEGRO_ALIGN_CENTRE, "Player 2: %d", Player2Score);
}

StartGame::~StartGame()
{
	al_destroy_bitmap(Skin);
	for (int K = 0; K < ButtonVector.size(); K++)
	{
		ButtonVector[K]->~Button();
	}
}