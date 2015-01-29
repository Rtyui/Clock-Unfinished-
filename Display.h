#pragma once
#include <allegro5/allegro.h>

class Display{
	private:
		ALLEGRO_DISPLAY *display;
	public:
		Display(int w, int h){
			display = al_create_display(w, h);
		}
		
		~Display(){
			al_destroy_display(display);
		}
		
		ALLEGRO_DISPLAY* getDisplay(){
			return display;
		}
};