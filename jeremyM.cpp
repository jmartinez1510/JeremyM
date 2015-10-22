// Jeremy Martinez

int check_keys(XEvent *e, Game *game);

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
