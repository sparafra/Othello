#include "Control.h"

Control::Control(float H, float W, ALLEGRO_COLOR CBackground)
{
    Height = H;
	Width = W;
	Color = CBackground;
}
Control::Control(float HPerc, float WPerc, ALLEGRO_COLOR CBackground, Form* form)
{
    Height = form->getHeight() * ((float)HPerc/100);
	Width = form->getWidth() * ((float)WPerc/100);
    Color = CBackground;
}
Control::Control(float HPerc, float WPerc, Form* form)
{
    Height = form->getHeight() * ((float)HPerc/100);
	Width = form->getWidth() * ((float)WPerc/100);
}
void Control::draw(float X, float Y)
{
    x = X;
    y = Y;
	al_draw_filled_rectangle(x, y, Width + x, Height + y, Color);
}
void Control::draw(float XPerc, float YPerc, Form* form)
{
    x = form->getWidth() * ((float)XPerc/100);
	y = form->getHeight() * ((float)YPerc/100);
	al_draw_filled_rectangle(x, y, Width + x, Height + y, Color);
}
bool Control::Clicked(float xClick, float yClick)
{
    if (xClick >= this->x && yClick >= this->y && xClick <= (this->x + Width) && yClick <= (this->y + Height))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Control::~Control()
{

}