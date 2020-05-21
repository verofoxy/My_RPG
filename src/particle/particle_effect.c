/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle_effect.c
*/

#include "rpg.h"
#include "json_parser.h"
#include "entity.h"
#include "particle.h"

particle_t *create_particle(char const *filepath)
{
    particle_t *part = malloc(sizeof(*part));

    CHECK_MALLOC(part)
    part->img = create_image(filepath, NULL);
    return (part);
}

particle_t **create_tab_particle_effect
(const unsigned int nb, const char *filepath)
{
    particle_t **part = malloc(sizeof(particle_t *) * ((int)nb + 1));

    CHECK_MALLOC(part)
    part[nb] = NULL;
    for (int i = 0; i < (int)nb; i++)
        part[i] = create_particle(filepath);
    return (part);
}

void particle_effect(const unsigned int size, const unsigned int frequency,
const char *filepath, sfRenderWindow *window)
{
    sfVector2f center;
    particle_t **part = create_tab_particle_effect(frequency, filepath);

    center.x = W_SCREEN / 2;
    center.y = H_SCREEN / 2;
    for (int count = 0; part[count]; count++) {
        set_random_pos(center, part[count]->img, size);
        draw_img(part[count]->img, window);
        destroy_particle(part[count]);
    }
    free(part);
}

void particles_effect_from_pos(sfVector2f pos, const unsigned int frequency,
const char *filepath, sfRenderWindow *window)
{
    particle_t **part = create_tab_particle_effect(frequency, filepath);

    pos.x += 15;
    for (int count = 0; part[count]; count++) {
        set_img_position(part[count]->img, pos);
        set_random_pos_particle(part[count]->img, RAND_PART_POS);
        draw_img(part[count]->img, window);
        destroy_particle(part[count]);
    }
    free(part);
}