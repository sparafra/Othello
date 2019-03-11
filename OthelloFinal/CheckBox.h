#ifndef CHECKBOX_
#define CHECKBOX_

#include <string>
#include "allegro5/allegro_color.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

#include "Form.h"
#include "Control.h"

using namespace std;


class CheckBox: public Control
{
private:

	ALLEGRO_COLOR Color;
	bool Selected;

public:
	CheckBox(float H, float W);
	CheckBox(float HPerc, float WPerc, Form* form);
	virtual void draw(float XPerc, float YPerc, bool Active, Form* form);
	virtual void draw(int X, int Y, bool Selected);
	bool getSelected() { return Selected; };
	void changeState();
	~CheckBox();
};
#endif