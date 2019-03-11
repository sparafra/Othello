#include "Settings.h"

Settings::Settings(ALLEGRO_FONT* Font, string PrecImage, string NextImage, vector<string> SkinsPath, int SelectedIndexSkin, Form* form)
{

	Skins = SkinsPath;
	IndexSkin = SelectedIndexSkin;
	
	//CheckBox
	CheckBox* BoardColorCB = new CheckBox(2.5, 2, form);
	CheckBox* BoardSkinCB = new CheckBox(2.5, 2, form);
	CheckBox* PlayerCB = new CheckBox(2.5, 2, form);
	CheckBox* PCCB = new CheckBox(2.5, 2, form);
	CheckBox* TimerCB = new CheckBox(2.5, 2, form);

	//Board Color
	Button* BoardColorR = new Button(3, 3, al_map_rgb(167, 22, 3), al_map_rgb(255, 255, 255), Font, 2, form); //Red
	Button* BoardColorG = new Button(3, 3, al_map_rgb(55, 165, 50), al_map_rgb(255, 255, 255), Font, 2, form); //Green
	Button* BoardColorB = new Button(3, 3, al_map_rgb(11, 65, 202), al_map_rgb(255, 255, 255), Font, 2, form); //Blue
	Button* BoardColorO = new Button(3, 3, al_map_rgb(237, 159, 55), al_map_rgb(255, 255, 255), Font, 2, form); //Orange
	Button* BoardColorY = new Button(3, 3, al_map_rgb(249, 215, 88), al_map_rgb(255, 255, 255), Font, 2, form); //Yellow


	//Disc 1 Color
	Button* Disc1ColorR = new Button(3, 3, al_map_rgb(167, 22, 3), al_map_rgb(255, 255, 255), Font, 2, form); //Red
	Button* Disc1ColorG = new Button(3, 3, al_map_rgb(55, 165, 50), al_map_rgb(255, 255, 255), Font, 2, form); //Green
	Button* Disc1ColorB = new Button(3, 3, al_map_rgb(11, 65, 202), al_map_rgb(255, 255, 255), Font, 2, form); //Blue
	Button* Disc1ColorO = new Button(3, 3, al_map_rgb(237, 159, 55), al_map_rgb(255, 255, 255), Font, 2, form); //Orange
	Button* Disc1ColorBk = new Button(3, 3, al_map_rgb(0, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form); //Black
	Button* Disc1ColorW = new Button(3, 3, al_map_rgb(255, 255, 255), al_map_rgb(255, 255, 255), Font, 2, form); //White

	//Disc 2 Color																										  
	Button* Disc2ColorR = new Button(3, 3, al_map_rgb(167, 22, 3), al_map_rgb(255, 255, 255), Font, 2, form); //Red
	Button* Disc2ColorG = new Button(3, 3, al_map_rgb(55, 165, 50), al_map_rgb(255, 255, 255), Font, 2, form); //Green
	Button* Disc2ColorB = new Button(3, 3, al_map_rgb(11, 65, 202), al_map_rgb(255, 255, 255), Font, 2, form); //Blue
	Button* Disc2ColorO = new Button(3, 3, al_map_rgb(237, 159, 55), al_map_rgb(255, 255, 255), Font, 2, form); //Orange
	Button* Disc2ColorBk = new Button(3, 3, al_map_rgb(0, 0, 0), al_map_rgb(255, 255, 255), Font, 2, form); //Black
	Button* Disc2ColorW = new Button(3, 3, al_map_rgb(255, 255, 255), al_map_rgb(255, 255, 255), Font, 2, form); //White

	//Next/Prec Skin Select
	ALLEGRO_BITMAP* PrecBMP = al_load_bitmap(PrecImage.c_str());
	ALLEGRO_BITMAP* NextBMP = al_load_bitmap(NextImage.c_str());
	Button* Prec = new Button(6.5, 3.6, PrecBMP, al_map_rgb(255, 255, 255), Font, 2, form); //Red
	Button* Next = new Button(6.5, 3.6, NextBMP, al_map_rgb(255, 255, 255), Font, 2, form); //Red
	

	//Save Button
	Button* Save = new Button(6, 10, al_map_rgb(255, 255, 255), al_map_rgb(0, 0, 0), Font, 2, form); //Save

	//Draw Checkbox
	BoardColorCB->draw(8, 4.2, false, form);
	BoardSkinCB->draw(48, 4.2, true, form);
	PlayerCB->draw(4, 24, true, form);
	PCCB->draw(11, 24, false, form);
	TimerCB->draw(22, 20, false, form);

	//Draw Board Color Sample
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)1.5/100), form->getHeight() * ((float)4.6/100), 0, "Board Color");
	BoardColorR->draw(2, 11, "", form);
	BoardColorG->draw(7, 11, "", form);
	BoardColorB->draw(12, 11, "", form);
	BoardColorO->draw(17, 11, "", form);
	BoardColorY->draw(22, 11, "", form);

	//Draw Enemies Button 
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)2/100), form->getHeight() * ((float)20/100), 0, "Enemies");
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)2/100), form->getHeight() * ((float)24/100), 0, "PC");
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)7/100), form->getHeight() * ((float)24/100), 0, "Player");
	
	//Draw Timer
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)18/100), form->getHeight() * ((float)20/100), 0, "Timer");


	//Draw Disc 1 Color
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)2/100), form->getHeight() * ((float)38/100), 0, "Disc 1");
	Disc1ColorR->draw(2, 44, "", form);
	Disc1ColorG->draw(6, 44, "", form);
	Disc1ColorB->draw(10, 44, "", form);
	Disc1ColorO->draw(2, 53, "", form);
	Disc1ColorBk->draw(6, 53, "", form);
	Disc1ColorW->draw(10, 53, "", form);

	al_draw_line(form->getWidth() * ((float)16/100), form->getHeight() * ((float)38/100), form->getWidth() * ((float)16/100), form->getHeight() * ((float)58/100), al_map_rgb(0, 0, 0), 5);

	//Draw Disc 2 Color
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)19/100), form->getHeight() * ((float)38/100), 0, "Disc 2");
	Disc2ColorR->draw(19, 44, "", form);
	Disc2ColorG->draw(23, 44, "", form);
	Disc2ColorB->draw(27, 44, "", form);
	Disc2ColorO->draw(19, 53, "", form);
	Disc2ColorBk->draw(23, 53, "", form);
	Disc2ColorW->draw(27, 53, "", form);

	//Draw Next/Prec Skin Select
	al_draw_text(Font, al_map_rgb(0, 0, 0), form->getWidth() * ((float)52/100), form->getHeight() * ((float)4.5/100), 0, "Board Skin");
	Prec->draw(37, 22, "", form);
	Next->draw(73, 22, "", form);
	SkinPreview = al_load_bitmap(SkinsPath[IndexSkin].c_str());

	al_draw_scaled_bitmap(SkinPreview, form->getWidth() * ((float)43/100), form->getHeight() * ((float)11/100), al_get_bitmap_width(SkinPreview), al_get_bitmap_height(SkinPreview), form->getWidth() * ((float)43/100), form->getHeight() * ((float)11/100), form->getWidth() * ((float)48/100), form->getHeight() * ((float)40/100), 0);
	al_destroy_bitmap(SkinPreview);


	//Draw Save Button
	Save->draw(45, 55, "Save", form);

	//Add Board Color Button
	ButtonVector.push_back(BoardColorR);
	ButtonVector.push_back(BoardColorG);
	ButtonVector.push_back(BoardColorB);
	ButtonVector.push_back(BoardColorO);
	ButtonVector.push_back(BoardColorY);

	//Add Enemies Button
	ButtonVector.push_back(Next);
	ButtonVector.push_back(Prec);

	//Add Disc1 Button
	ButtonVector.push_back(Disc1ColorR);
	ButtonVector.push_back(Disc1ColorG);
	ButtonVector.push_back(Disc1ColorB);
	ButtonVector.push_back(Disc1ColorO);
	ButtonVector.push_back(Disc1ColorBk);
	ButtonVector.push_back(Disc1ColorW);

	//Add Disc2 Button
	ButtonVector.push_back(Disc2ColorR);
	ButtonVector.push_back(Disc2ColorG);
	ButtonVector.push_back(Disc2ColorB);
	ButtonVector.push_back(Disc2ColorO);
	ButtonVector.push_back(Disc2ColorBk);
	ButtonVector.push_back(Disc2ColorW);


	//Add Save Button
	ButtonVector.push_back(Save);

	//Add CheckBox
	CheckBoxVector.push_back(BoardColorCB);
	CheckBoxVector.push_back(BoardSkinCB);
	CheckBoxVector.push_back(PlayerCB);
	CheckBoxVector.push_back(PCCB);
	CheckBoxVector.push_back(TimerCB);

}
void Settings::NextPreview(Form* form)
{
	IndexSkin++;
	SkinPreview = al_load_bitmap(Skins[IndexSkin].c_str());
	al_draw_scaled_bitmap(SkinPreview, form->getWidth() * ((float)43/100), form->getHeight() * ((float)11/100), al_get_bitmap_width(SkinPreview), al_get_bitmap_height(SkinPreview), form->getWidth() * ((float)43/100), form->getHeight() * ((float)11/100), form->getWidth() * ((float)48/100), form->getHeight() * ((float)40/100), 0);
	al_destroy_bitmap(SkinPreview);
}
void Settings::PrecPreview(Form* form)
{
	IndexSkin--;
	SkinPreview = al_load_bitmap(Skins[IndexSkin].c_str());
	al_draw_scaled_bitmap(SkinPreview, form->getWidth() * ((float)43/100), form->getHeight() * ((float)11/100), al_get_bitmap_width(SkinPreview), al_get_bitmap_height(SkinPreview), form->getWidth() * ((float)43/100), form->getHeight() * ((float)11/100), form->getWidth() * ((float)48/100), form->getHeight() * ((float)40/100), 0);
	al_destroy_bitmap(SkinPreview);

}
Settings::~Settings()
{

	for (int K = 0; K < ButtonVector.size(); K++)
	{
		ButtonVector[K]->~Button();
	}
	
	for (int K = 0; K < CheckBoxVector.size(); K++)
	{
		CheckBoxVector[K]->~CheckBox();
	}
	
}