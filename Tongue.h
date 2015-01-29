#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

float degreesToRadians(int a){
	return a*M_PI/180;
}

class Tongue{
private:
	int length;
	int rotation;
	int zerox;
	int zeroy;
	int thickness;
	
public:
	Tongue(){}
	Tongue(int l, ALLEGRO_DISPLAY* display, int t){
		length = l;
		zerox = (int)(al_get_display_width(display)/2);
		zeroy = (int)(al_get_display_height(display)/2);
		rotation = 90;
		thickness = t;
	}
	~Tongue(){}
	void ticTac(){
		if(rotation == 6)
			rotation = 360;
		else
			rotation -= 6;
	}
	void draw(){
		al_draw_line(zerox, zeroy, zerox + cos(degreesToRadians(rotation)) * length, zeroy - sin(degreesToRadians(rotation)) * length, al_map_rgb(255, 255, 255), thickness);
	}
};