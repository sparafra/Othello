#include "Form.h"

Form::Form(ALLEGRO_BITMAP* S)
{
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	ALLEGRO_DISPLAY_MODE disp_data;
	al_get_display_mode(0, &disp_data);


	Width = disp_data.width;
	Height = disp_data.height;



	Display = al_create_display(Width, Height);
	if (!Display) {
		al_show_native_message_box(Display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}

	imagebackground = true;
	Skin = S;
	repaint();

}
Form::Form(ALLEGRO_COLOR C)
{
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	ALLEGRO_DISPLAY_MODE disp_data;
	al_get_display_mode(0, &disp_data);


	Width = disp_data.width;
	Height = disp_data.height;

	Display = al_create_display(Width, Height);
	if (!Display) {
		al_show_native_message_box(Display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	imagebackground = false;
	Color = C;
	repaint();

}
Form::Form(int W, int H, ALLEGRO_BITMAP* S)
{
	Width = W;
	Height = H;



	Display = al_create_display(Width, Height);
	if (!Display) {
		al_show_native_message_box(Display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}

	imagebackground = true;
	Skin = S;
	repaint();

}
Form::Form(int W, int H, ALLEGRO_COLOR C)
{
	Width = W;
	Height = H;
	Display = al_create_display(Width, Height);
	if (!Display) {
		al_show_native_message_box(Display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	imagebackground = false;
	Color = C;
	repaint();

}
void Form::repaint()
{
	if(imagebackground)
	{
		al_draw_bitmap(Skin,0,0,0);
	}
	else
	{
		al_clear_to_color(Color);

	}	
}
Form::~Form()
{
	al_destroy_display(Display);

}