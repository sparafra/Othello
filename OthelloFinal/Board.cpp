#include "Board.h"

	Board::Board(float dimPercentage, ALLEGRO_COLOR C, Form* form)
	{
		Dim = form->getHeight() * ((float)dimPercentage/100);
		Color = C;
	}
	void Board::drawBoard(float XPerc, float YPerc, Form* form)
	{
		x = form->getWidth() * ((float)XPerc/100);
		y = form->getHeight() * ((float)YPerc/100);
		al_draw_filled_rectangle(x, y, Dim+x,Dim+y, Color);
		for (int K = 1; K < 8; K++)
		{
			al_draw_line(x, (K * (Dim/8)) + y, x + Dim, (K * (Dim/8)) + y, al_map_rgb(255, 0, 0), 2);
			al_draw_line((K * (Dim / 8)) + x, y, x + (K * (Dim / 8)), Dim + y, al_map_rgb(255, 0, 0), 2);
		}
	}
	void Board::drawBoard(int X, int Y)
	{
		x = X;
		y = Y;
		al_draw_filled_rectangle(x, y, Dim+x,Dim+y, Color);
		for (int K = 1; K < 8; K++)
		{
			al_draw_line(x, (K * (Dim/8)) + y, x + Dim, (K * (Dim/8)) + y, al_map_rgb(255, 0, 0), 2);
			al_draw_line((K * (Dim / 8)) + x, y, x + (K * (Dim / 8)), Dim + y, al_map_rgb(255, 0, 0), 2);
			
		}
	}
	void Board::drawDisc(Disc* D, int Riga, int Col )
	{
		int centro = (Dim/8) / 2;
		D->drawDisc(x + (Col * (Dim / 8))+ centro, y + (Riga * (Dim / 8))+ centro);

	}
	void Board::drawTransparentDisc(Disc* D, int Riga, int Col)
	{
		
		int centro = (Dim / 8) / 2;
		D->drawTransparentDisc(x + (Col * (Dim / 8)) + centro, y + (Riga * (Dim / 8)) + centro);

	}
	void Board::clearTransparentDisc(int R, int Riga, int Col)
	{
		Disc* D = new Disc(R, Color);
		int centro = (Dim / 8) / 2;
		D->drawTransparentDisc(x + (Col * (Dim / 8)) + centro, y + (Riga * (Dim / 8)) + centro);

	}
	void Board::clearDisc(int R, int Riga, int Col, bool Transparent)
	{
		Disc* D = new Disc(R, Color);
		int centro = (Dim / 8) / 2;
		if (Transparent)
		{
			D->drawTransparentDisc(x + (Col * (Dim / 8)) + centro, y + (Riga * (Dim / 8)) + centro);
		}
		else
		{
			D->drawDisc(x + (Col * (Dim / 8))+ centro, y + (Riga * (Dim / 8))+ centro);
		}
	}
	bool Board::Clicked(int x, int y)
	{
		if (x >= this->x && y >= this->y && x <= (this->x + Dim) && y <= (this->y + Dim))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int* Board::ClickedCell(int x, int y)
	{
		int* RigaColonna = new int[2];
		RigaColonna[0] = (y - this->y) / (Dim / 8);
		RigaColonna[1] = (x - this->x) / (Dim / 8);
		return RigaColonna;
	}