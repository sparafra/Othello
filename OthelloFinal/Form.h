#ifndef FORM_
#define FORM_

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_color.h"


class Form
{
private:

	int Height;
	int Width;
	ALLEGRO_DISPLAY* Display;
	ALLEGRO_COLOR Color;
	ALLEGRO_BITMAP* Skin;
	bool imagebackground;

public:
	Form(int W, int H, ALLEGRO_BITMAP* S);
	Form(int W, int H, ALLEGRO_COLOR C);
	Form(ALLEGRO_BITMAP* S);
	Form(ALLEGRO_COLOR C);
	float getWidth(){return Width;};
	float getHeight(){return Height;};
	void repaint();
	void setColor(ALLEGRO_COLOR C){Color = C;};
	void setSkin(ALLEGRO_BITMAP* S){Skin = S;};
	void setImageBackground(bool imgBack){imagebackground = imgBack;};
	ALLEGRO_DISPLAY* getDisplay() { return Display; };
	~Form();
};
#endif
