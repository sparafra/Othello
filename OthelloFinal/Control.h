#ifndef CONTROL_
#define CONTROL_

#include <string>
#include "allegro5/allegro_color.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

#include "Form.h"


class Control
{

protected:
	float Height;
	float Width;
	float x; 
	float y;
	ALLEGRO_COLOR Color;
	
public:
    Control(float H, float W, ALLEGRO_COLOR CBackground);
    Control(float HPerc, float WPerc, ALLEGRO_COLOR CBackground, Form* form);
    Control(float HPerc, float WPerc, Form* form);
	Control(float H, float W){Height = H; Width = W;};
	virtual void draw(float x, float y);
	virtual void draw(float XPerc, float YPerc, Form* form);
	int getX() { return x; };
	int getY() { return y; };
	int getWidth() { return Width; };
	int getHeight() { return Height; };
	bool Clicked(float xClick, float yClick);
	
	~Control();
};
#endif