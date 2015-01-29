#pragma once
#include <allegro5/allegro.h>
#include <iostream>
using namespace std;

class Queue{
	private:
		ALLEGRO_EVENT_QUEUE *eventQueue;
		ALLEGRO_EVENT event;
	public:
		Queue(){
			eventQueue = al_create_event_queue();
		}
		
		~Queue(){
			al_destroy_event_queue(eventQueue);
		}
		
		void registerEvents(ALLEGRO_TIMER* timer, ALLEGRO_DISPLAY* display){
			al_register_event_source(eventQueue, al_get_keyboard_event_source());
			al_register_event_source(eventQueue, al_get_mouse_event_source());
			al_register_event_source(eventQueue, al_get_display_event_source(display));
			al_register_event_source(eventQueue, al_get_timer_event_source(timer));
		}
	
		void waitForEvent(){
			al_wait_for_event(eventQueue, &event);
		}
	
		ALLEGRO_EVENT getEvent(){
			return event;
		}
};