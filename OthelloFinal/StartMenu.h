#ifndef STARTMENU_
#define STARTMENU_

#include "Form.h"
#include "Button.h"
#include <string>
#include <vector>
#include "allegro5/allegro_image.h"


class StartMenu
{
private:

	Form* F;
	vector<Button*> ButtonVector;
	ALLEGRO_BITMAP* Skin;
	ALLEGRO_COLOR Color;
public:
	StartMenu(ALLEGRO_FONT* Font, string Skinpath, Form* form);
	StartMenu(ALLEGRO_FONT* Font, ALLEGRO_COLOR C, Form* form);
	~StartMenu();
	vector<Button*> getButtons() { return ButtonVector; };
	Form* getForm() { return F; };

};
#endif
