#include "Disc.h"

Disc::Disc(int R, ALLEGRO_COLOR C)
{
	Radius = R;
	Color = C;
}

Disc::Disc(float RPercentage, ALLEGRO_COLOR C, Form* form)
{
	Radius = form->getWidth() * ((float)RPercentage/100);
	Color = C;
}
void Disc::drawDisc(float XPerc, float YPerc, Form* form)
{
	x = form->getWidth() * ((float)XPerc/100);
	y = form->getHeight() * ((float)YPerc/100);
	al_draw_filled_circle(x, y , Radius, Color); 
}
void Disc::drawDisc(int X, int Y)
{
	x = X;
	y = Y;
	al_draw_filled_circle(x, y , Radius, Color); 
}
void Disc::drawTransparentDisc(int X, int Y)
{
	x = X;
	y = Y;
	al_draw_circle(x, y, Radius, Color, 2);
}
Disc::~Disc()
{

}