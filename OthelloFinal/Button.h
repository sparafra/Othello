#ifndef BUTTON_
#define BUTTON_

#include <string>
#include "allegro5/allegro_color.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

#include <iostream>

#include "Form.h"
#include "Control.h"

using namespace std;


class Button: public Control
{
private:
	ALLEGRO_COLOR FontColor;
	ALLEGRO_FONT *Font;
	ALLEGRO_BITMAP *Background;
	int FontSize;
	string Text;
	
public:
	Button(float H, float W, ALLEGRO_COLOR CBackground, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, int FSize);
	Button(float H, float W, ALLEGRO_BITMAP *BG, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, int FSize);
	Button(float HPerc, float WPerc, ALLEGRO_COLOR CBackground, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, float FSizePerc, Form* form);
	Button(float HPerc, float WPerc, ALLEGRO_BITMAP *BG, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, float FSizePerc, Form* form);
	virtual void draw(int x, int y, string text);
	virtual void draw(float XPerc, float YPerc, string text, Form* form);
	string getText() { return Text; };
	~Button();
};
#endif