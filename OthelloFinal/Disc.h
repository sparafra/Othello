#ifndef DISC_
#define DISC_

#include "allegro5/allegro_color.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

#include "Form.h"

using namespace std;

class Disc
{
private:
	int Radius;
	
	int x; 
	int y;
	ALLEGRO_COLOR Color;
public:
	Disc(int R, ALLEGRO_COLOR C);
	Disc(float RPercentage, ALLEGRO_COLOR C, Form* form);
	void drawDisc(int x, int y);
	void drawDisc(float XPerc, float YPerc, Form* form);
	void drawTransparentDisc(int x, int y);
	int getX() { return x; };
	int getY() { return y; };
	int getRadius() { return Radius; };
	ALLEGRO_COLOR getColor() { return Color; };
	~Disc();
};

#endif // !DISC_
