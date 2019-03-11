#include "CheckBox.h"

CheckBox::CheckBox(float H, float W):Control(H, W)
{

	Selected = false;
	Color = al_map_rgb(255, 255, 255);
}
CheckBox::CheckBox(float HPerc, float WPerc, Form* form):Control(HPerc, WPerc, form)
{

	Selected = false;
	Color = al_map_rgb(255, 255, 255);
}

void CheckBox::draw(float XPerc, float YPerc, bool Active, Form* form)
{
	x = form->getWidth() * ((float)XPerc/100);
	y = form->getHeight() * ((float)YPerc/100);
	Selected = Active;
	if (!Selected)
	{
		Selected = false;
		al_draw_filled_rectangle(x, y, x + Width, y + Height, Color);
		al_draw_filled_circle(x + (Width / 2), y + (Height / 2), Height / 2, al_map_rgb(255, 255, 255));
	}
	else
	{
		Selected = true;
		al_draw_filled_rectangle(x, y, x + Width, y + Height, Color);
		al_draw_filled_circle(x + (Width / 2), y + (Height / 2), Height / 2, al_map_rgb(0, 255, 0));
	}
}
void CheckBox::draw(int X, int Y, bool Active)
{
	x = X;
	y = Y;
	Selected = Active;
	if (!Selected)
	{
		Selected = false;
		al_draw_filled_rectangle(x, y, x + Width, y + Height, Color);
		al_draw_filled_circle(x + (Width / 2), y + (Height / 2), Height / 2, al_map_rgb(255, 255, 255));
	}
	else
	{
		Selected = true;
		al_draw_filled_rectangle(x, y, x + Width, y + Height, Color);
		al_draw_filled_circle(x + (Width / 2), y + (Height / 2), Height / 2, al_map_rgb(0, 255, 0));
	}
}
void CheckBox::changeState()
{
	if (Selected)
	{
		Selected = false;
		al_draw_filled_rectangle(x, y, x + Width, y + Height, Color);
		al_draw_filled_circle(x + (Width / 2), y + (Height / 2), Height/2, al_map_rgb(255, 255, 255));
	}
	else
	{
		Selected = true;
		al_draw_filled_rectangle(x, y, x + Width, y + Height, Color);
		al_draw_filled_circle(x + (Width / 2), y + (Height/2), Height / 2, al_map_rgb(0, 255, 0));
	}
		
}

CheckBox::~CheckBox()
{

}
