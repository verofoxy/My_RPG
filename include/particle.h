/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle.h
*/

#ifndef PARTICLE_H
#define PARTICLE_H

#include "camera.h"

#define MAIN_PATH_PART PATH_PART_EYES
#define PATH_PART_EYES "assets/particle/eyes.png"
#define PATH_PART_BUBBLE "assets/particle/bubble.png"
#define PATH_PART_FIRE "assets/particle/fire.png"

#define RAND_PART_POS_X (rand() % range - rand() % (range * 2) + 10)
#define RAND_PART_POS_Y (rand() % (range / 2))
#define RAND_PART_POS ((rand() % frequency -1) * 10)

#define FREQUENCY(size) (size / 2)

#define CIMSX center_in_the_middle_size_x
#define CIMSY center_in_the_middle_size_y

typedef struct particle_t
{
    img_t *img;
} particle_t;

particle_t *create_particle(char const *filepath);
particle_t **create_tab_particle_effect(const unsigned int nb,
const char *filepath);

void particle_effect(const unsigned int size,
const unsigned int frequency, const char *filepath, sfRenderWindow *window);
void particles_effect_from_pos(sfVector2f pos,
const unsigned int frequency, const char *filepath, sfRenderWindow *window);

void set_random_pos(sfVector2f center, img_t *img, const int size);
void set_random_pos_particle(img_t *img, const int range);

void destroy_particle(particle_t *part);
player_t *find_player_for_set_particle(list_t **entities);

#endif
