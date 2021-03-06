/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_string_token.c
*/

#include "rpg.h"

void parse_string_token(json_tokenizer_t *tokenizer)
{
    unsigned int tmp_pos = tokenizer->data_position;
    bool end_of_string = false;

    while (!end_of_string) {
        tmp_pos++;
        if (tokenizer->buffer->str[tmp_pos] ==  '"')
            end_of_string = (tokenizer->buffer->str[tmp_pos - 1] != '\\')
            ? true
            : false;
    }
    tokenizer->token_length = tmp_pos - tokenizer->data_position - 1;
}