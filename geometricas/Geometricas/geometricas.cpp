#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main (void)
{
    int width = 512;
    int height = 512;

    ALLEGRO_DISPLAY *display = NULL;

    al_init();
    al_init_primitives_addon();

    display = al_create_display(height, width);

    al_draw_line(10, 50, 100, 100, al_map_rgb(0,0,0),3);
    al_draw_rectangle(150,50,200,100,al_map_rgb(0,0,0),5);
    al_draw_filled_rectangle(100, 200, 200, 250, al_map_rgb(0,0,0));
    al_draw_filled_circle(400, 200, 50, al_map_rgb(0,0,0));
    al_draw_filled_rounded_rectangle(400, 300, 450, 350,10,10,al_map_rgb(0,0,0));

    al_flip_display();

    al_rest(3.0);

    al_destroy_display(display);
}
