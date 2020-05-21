/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** sound.h
*/

#ifndef MUL_MY_DEFENDER_2019_SOUND_H
#define MUL_MY_DEFENDER_2019_SOUND_H

#include <SFML/Audio.h>
#include <stdbool.h>
#include "list.h"
#include "scene.h"

#define PATH_SOUND_J "assets/sound/sound_mini.json"

#define SFX_ACTIVED(x) if (sys->settings.sfx_allowed) (x)
#define MUSIC_ACTIVED(x) if (sys->settings.music_allowed) (x)


#define PLAY 1
#define STOP 2
#define PAUSE 3
#define RESET 4
#define VOLUME 5

#define TAG_SOUND {"env", "move", \
"collision", "click", "att", "level", "newitem", "gameover"}

typedef enum type_sound
{
    ENV,
    MOVE,
    COLLISION,
    CLICK,
    ATT,
    LEVEL,
    NEWITEM,
    GAMEOVER
} type_sound_e;

typedef struct sound {
    sfSoundBuffer *buffer;
    sfSound *sound;
    bool is_sfx;
} snd_t;

snd_t *create_sound(char const *filepath, float volume, bool loop, bool sfx);
void sound_handle(game_sys_t *sys, int type_sound, float volume, int mode);
void play_sound(snd_t *snd);
void pause_sound(snd_t *snd);
void stop_sound(snd_t *snd);
void volume_sound(snd_t *snd, float volume);
void set_volume_sound(list_t *sound, float volume);
void reset_all_sound(list_t *sound);
void destroy_sound(snd_t *sound);
void set_sfx(game_sys_t *sys);
void set_music(game_sys_t *sys);
list_t *set_sound(void);

#endif