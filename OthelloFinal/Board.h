#ifndef BOARD_H
#define BOARD_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include "Disc.h"
#include "Form.h"

class Board
{
	private:
		int Dim;
		int x;
		int y;
		ALLEGRO_COLOR Color;
		
	public:
		Board(float dimPercentage, ALLEGRO_COLOR C, Form* form);
		int getDim() { return Dim; };

		void drawBoard(int x, int y);
		void drawBoard(float XPerc, float YPerc, Form* form);
		void drawDisc(Disc* D, int Riga, int Col);
		void drawTransparentDisc(Disc* D, int Riga, int Col);
		void clearTransparentDisc(int R, int Riga, int Col);
		void clearDisc(int R, int Riga, int Col, bool Transparent);
		bool Clicked(int x, int y);
		int* ClickedCell(int x, int y);
}; 
#endif // !BOARD_H