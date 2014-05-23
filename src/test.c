#include <allegro5/allegro.h>
#include "test.h"

int main(void)
{
	ALLEGRO_DISPLAY *d;
	ALLEGRO_EVENT_QUEUE *q;
	al_init();
	
	d = al_create_display(320, 240);
	q = al_create_event_queue();
	al_register_event_source(q, al_get_display_event_source(d));
	
	al_wait_for_event(q, NULL);
	
	return 0;
}
