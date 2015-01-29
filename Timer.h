#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include "Tongue.h"
using namespace std;

class Timer{
	private:
		ALLEGRO_TIMER *timer;
		int counter;
	public:
		Timer(int fps){
			timer = al_create_timer(1.0 / fps);
			counter = 0;
		}
		
		~Timer(){
			al_destroy_timer(timer);
		}
		
		void start(){
			al_start_timer(timer);
		}
		
		void timerEvent(ALLEGRO_EVENT event, bool *redraw, Tongue* t1, Tongue* t2, Tongue* t3){
			if(event.type == ALLEGRO_EVENT_TIMER){
				if(counter == 3600){
					counter = 1;
					t3->ticTac();
				}
				else
					counter++;
				*redraw = true;
				t1->ticTac();
				if(counter % 60 == 0){
					t2->ticTac();
				}
			}
		}
		
		ALLEGRO_TIMER* getTimer()
		{
			return timer;
		}
};