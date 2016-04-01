#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


int main()
{
    ALLEGRO_DISPLAY *Screen;
    ALLEGRO_EVENT_QUEUE *EventQueue;
    ALLEGRO_EVENT Event;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *Image = NULL;
    ALLEGRO_SAMPLE *sample=NULL;

    bool Exit = false;

    al_init();
    al_init_image_addon();

    if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
    }
    if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
    }

    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    sample = al_load_sample( "music.ogg" );

    if (!sample){
        printf( "Audio clip sample not loaded!\n" );
        return -1;
    }

    Screen = al_create_display(512, 512);

    EventQueue = al_create_event_queue();
    al_register_event_source(EventQueue, al_get_display_event_source(Screen));

    background = al_load_bitmap("image_background_colors__black_bg.png");
    Image = al_load_bitmap("image.png");
    al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

    while(Exit == false)
    {

        al_draw_bitmap(background, 0, 0, 0);
        al_draw_bitmap(Image, 200, 200, 0);
        al_wait_for_vsync();
        al_flip_display();
        al_wait_for_event(EventQueue, &Event);

        if(Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            al_destroy_sample(sample);
            Exit = true;
        }
    }

    return 0;
}
