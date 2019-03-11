#ifndef SETTINGS_
#define SETTINGS_

#include "Form.h"
#include "Button.h"
#include "CheckBox.h"
#include <string>
#include <vector>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"


class Settings
{
private:

	Form* F;
	vector<Button*> ButtonVector;
	vector<CheckBox*> CheckBoxVector;
	ALLEGRO_BITMAP* Skin;
	ALLEGRO_BITMAP* SkinPreview;
	vector<string> Skins;
	int IndexSkin;
public:
	Settings(ALLEGRO_FONT* Font, ALLEGRO_BITMAP* S, string PrecImage, string NextImage, vector<ALLEGRO_BITMAP*> Skins, Form* form);
	Settings(ALLEGRO_FONT* Font, string PrecImage, string NextImage, vector<string> SkinsPath, int SelectedIndexSkin, Form* form);
	~Settings();
	void NextPreview(Form* form);
	void PrecPreview(Form* form);
	int getIndexSkin() { return IndexSkin; };
	int getNumberOfSkins() { return Skins.size(); };
	vector<Button*> getButtons() { return ButtonVector; };
	vector<CheckBox*> getCheckBoxVector() { return CheckBoxVector; };
	Form* getForm() { return F; };

};
#endif