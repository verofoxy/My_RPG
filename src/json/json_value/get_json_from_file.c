/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** get_json_from_file.c
*/

#include "rpg.h"

json_value_t *get_json_from_file(char const *filepath, bool minified)
{
    int status = 0;
    json_value_t *value = NULL;
    FILE *json_file = fopen(filepath, "r");
    char *buffer = NULL;
    size_t n = 0;

    if (!json_file)
        return NULL;
    if (minified) {
        if (getline(&buffer, &n, json_file) == -1)
            return NULL;
        status = json_parse(buffer, &value);
        free(buffer);
        CHECK_CORRUPTED(status)
    }
    fclose(json_file);
    return value;
}