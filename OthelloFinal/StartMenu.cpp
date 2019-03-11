#include "StartMenu.h"

StartMenu::StartMenu(ALLEGRO_FONT* Font, string Skinpath, Form* form)
{
	Skin = al_load_bitmap(Skinpath.c_str());


	Button* Start = new Button(7, 13, al_map_rgb(255, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form);
	Button* Settings = new Button(7, 13, al_map_rgb(255, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form);
	Button* Exit = new Button(7, 13, al_map_rgb(255, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form);

	Start->draw(43.5, 37, "Start", form);
	Settings->draw(43.5, 44.5, "Settings", form);
	Exit->draw(43.5, 52, "Exit", form);

	ButtonVector.push_back(Start);
	ButtonVector.push_back(Settings);
	ButtonVector.push_back(Exit);
}
StartMenu::StartMenu(ALLEGRO_FONT* Font, ALLEGRO_COLOR C, Form* form)
{


	Button* Start = new Button(7, 13, al_map_rgb(255, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form);
	Button* Settings = new Button(7, 13, al_map_rgb(255, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form);
	Button* Exit = new Button(7, 13, al_map_rgb(255, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form);

	Start->draw(43.5, 37, "Start", form);
	Settings->draw(43.5, 44.5, "Settings", form);
	Exit->draw(43.5, 52, "Exit", form);

	ButtonVector.push_back(Start);
	ButtonVector.push_back(Settings);
	ButtonVector.push_back(Exit);
}

StartMenu::~StartMenu()
{
	al_destroy_bitmap(Skin);
	for (int K = 0; K < ButtonVector.size(); K++)
	{
		ButtonVector[K]->~Button();
	}
}