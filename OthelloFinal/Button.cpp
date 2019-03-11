#include "Button.h"

Button::Button(float H, float W, ALLEGRO_COLOR CBackground, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, int FSize)
:Control(H, W, CBackground)
{
	/*
	Height = H;
	Width = W;
	Color = CBackground;
	*/
	FontColor = CFont;
	Font = F;
	Background = NULL;
	FontSize = FSize;
		
}
Button::Button(float HPerc, float WPerc, ALLEGRO_COLOR CBackground, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, float FSizePerc, Form* form)
:Control(HPerc, WPerc, CBackground, form)
{
	/*
	cout<<"WidthForm: "<<form->getWidth()<<endl;
	cout<<"HeightForm: "<<form->getHeight()<<endl;
	Height = form->getHeight() * ((float)HPerc/100);
	Width = form->getWidth() * ((float)WPerc/100);
	cout<<"WidthButton: "<<Width<<endl;
	cout<<"HeightButton: "<<Height<<endl;
	Color = CBackground;
	*/
	FontColor = CFont;
	Font = F;
	Background = NULL;
	FontSize = form->getWidth() * ((float)FSizePerc/100);
	
	
}
Button::Button(float H, float W, ALLEGRO_BITMAP *BG, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, int FSize)
:Control(H, W)
{
	//Height = H;
	//Width = W;
	FontColor = CFont;
	Font = F;
	Background = BG;
	FontSize = FSize;

}
Button::Button(float HPerc, float WPerc, ALLEGRO_BITMAP *BG, ALLEGRO_COLOR CFont, ALLEGRO_FONT *F, float FSizePerc, Form* form)
:Control(HPerc, WPerc, form)
{

	FontColor = CFont;
	Font = F;
	Background = BG;
	FontSize = form->getWidth() * ((float)FSizePerc/100);

}
void Button::draw(float XPerc, float YPerc, string text, Form* form)
{
	x = form->getWidth() * ((float)XPerc/100);
	y = form->getHeight() * ((float)YPerc/100);
	Text = text;
	if (Background == NULL)
	{
		al_draw_filled_rectangle(x, y, Width + x, Height + y, Color);
		al_draw_text(Font, FontColor, x + ((Width / 2) - (FontSize)), y + ((Height / 2) - (FontSize / 2)), 0, Text.c_str());
	}
	else
	{
		//al_draw_scaled_bitmap(Background, x, y , al_get_bitmap_width(Background), al_get_bitmap_height(Background), x, y, Width, Height, 0);
		al_draw_bitmap(Background, x, y, 0);
	}
}
void Button::draw(int X, int Y, string text)
{
	x = X;
	y = Y;
	Text = text;
	if (Background == NULL)
	{
		al_draw_filled_rectangle(x, y, Width + x, Height + y, Color);
		al_draw_text(Font, FontColor, x + ((Width / 2) - (FontSize)), y + ((Height / 2) - (FontSize / 2)), 0, Text.c_str());
	}
	else
	{
		al_draw_bitmap(Background, x, y, 0);
	}
	//al_flip_display();
}

Button::~Button()
{
	
	al_destroy_bitmap(Background);
}

