
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>

#define GRAVITY 0.1

struct Character {
	Shape s;
	Vec velocity;
	float width, height;
	Vec center;  //position?
};

struct Game {
	Shape box[6];
	Shape circle;
	Character character;
	Shape platform;
	
	
	Particle particle[MAX_PARTICLES];
	int n;
	int lastMousex, lastMousey;
	
};


float gravity = 0.5f;

void check_mouse(XEvent *e, Game *game);
int check_keys(XEvent *e, Game *game);

void check_mouse(XEvent *e, Game *game)
{
	static int savex = 0;
	static int savey = 0;
	//static int n = 0;

	if (e->type == ButtonRelease) {
		return;
	}
	/*if (e->type == ButtonPress) {
		if (e->xbutton.button==1) {
			//Left button was pressed
			int y = WINDOW_HEIGHT - e->xbutton.y;
			for(int i = 0; i<10; i++)
			    makeParticle(game, e->xbutton.x, y);
			return;
		}
		if (e->xbutton.button==3) {
			//Right button was pressed
			return;
		}
	}*/
	//Did the mouse move?
	if (savex != e->xbutton.x || savey != e->xbutton.y) {
		savex = e->xbutton.x;
		savey = e->xbutton.y;
		int y = WINDOW_HEIGHT - e->xbutton.y;
		//for(int i = 0; i<10; i++)
		    //makeParticle(game, e->xbutton.x, y);

		//if (++n < 10)
		//	return;
		game->lastMousex = e->xbutton.x; 
		game->lastMousey = y;
	}
}

int check_keys(XEvent *e, Game *game)
{
	//int shift;
	//Was there input from the keyboard?
	int key = XLookupKeysym(&e->xkey, 0);
	//Log("key: %i\n", key);
	if (e->type == KeyRelease) {
		keys[key]=0;
		if (key == XK_Shift_L || key == XK_Shift_R) {
			//shift=0;
		}
		return 0;
	}
	if (e->type == KeyPress) {
		//int key = XLookupKeysym(&e->xkey, 0);
		keys[key] = 1;
		if (key == XK_Shift_L || key == XK_Shift_R) {
			//shift=1;
			return 0;
		}
		
		if (key == XK_Escape) {
			return 1;
		}
	
		//You may check other keys here.

	}
	return 0;
}
