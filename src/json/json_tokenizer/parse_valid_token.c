/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_bool_token.c
*/

#include "rpg.h"

void parse_valid_token(json_tokenizer_t *tokenizer, bool *got, char const *test)
{
    if (m_strncmp(tokenizer->buffer->str + tokenizer->data_position,
    test, m_strlen(test)) != 0) {
        *got = false;
        return;
    }
    tokenizer->token_length = m_strlen(test);
}