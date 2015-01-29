#include <iostream>
#include <allegro5/allegro.h>

#include "Display.h"
#include "Timer.h"
#include "Queue.h"
#include "Keyboard.h"
#include "Tongue.h"

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 640

int main(){
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	
	Display *display = new Display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	Timer *timer = new Timer(10);
	Queue *eventQueue = new Queue();
	Keyboard *keyboard = new Keyboard();
	Tongue *secundar = new Tongue(60, display->getDisplay(), 1);
	Tongue *minutar = new Tongue(60, display->getDisplay(), 2);
	Tongue *orar = new Tongue(40, display->getDisplay(), 3);
	
	bool running = true, redraw = true;
	
	eventQueue->registerEvents(timer->getTimer(), display->getDisplay());
	
	timer->start();
	while(running){
		eventQueue->waitForEvent();
		keyboard->checkEvent(eventQueue->getEvent());
		keyboard->checkKeys(&running);
		timer->timerEvent(eventQueue->getEvent(), &redraw, secundar, minutar, orar);
		
		if(redraw){
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			secundar->draw();
			minutar->draw();
			orar->draw();
			al_flip_display();
		}
	}

	delete keyboard;
	delete eventQueue;
	delete timer;
	delete display;
	return 0;
}