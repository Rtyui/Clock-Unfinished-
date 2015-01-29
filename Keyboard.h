#pragma once
#include <allegro5/allegro.h>
#include <iostream>
using namespace std;

class Keyboard{
	private:
		bool keys[256];
	public:
		Keyboard(){
			for(int i = 0; i < 256; i++){
				keys[i] = false;
			}
		}
		~Keyboard(){
			;
		}
		void checkEvent(ALLEGRO_EVENT event){
			if(event.type == ALLEGRO_EVENT_KEY_DOWN){
				keys[event.keyboard.keycode] = true;
			} else if(event.type == ALLEGRO_EVENT_KEY_UP){
				keys[event.keyboard.keycode] = false;
			}
		}
	
		bool checkKey(int i){
			return keys[i];
		}
		
		void checkKeys(bool *running){
			if(keys[ALLEGRO_KEY_ESCAPE]){
				*running = false;
			}
		}
};