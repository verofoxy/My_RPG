/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_number.c
*/

#include "rpg.h"
#include <criterion/criterion.h>

Test(parse_number, valid_number)
{
    char *str = "122";
    int status = 0;
    data_buffer_t buffer = {str, m_strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    json_value_t *value = NULL;

    parse_token(&tokenizer, &status);
    value = parse_number(&tokenizer, &status);
    cr_assert_eq(value->value_type, J_NUM);
    cr_assert_eq(value->value.number, 122);
    destroy_json_value(value);
}