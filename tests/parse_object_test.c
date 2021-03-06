/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_object_test.c
*/

#include "rpg.h"
#include <criterion/criterion.h>
#include <rpg.h>

Test(parse_number, valid_number)
{
    char *str = "{ \"mlv\" : 3}";
    int status = 0;
    data_buffer_t buffer = {str, m_strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    json_value_t *value = NULL;

    parse_token(&tokenizer, &status);
    value = parse_number(&tokenizer, &status);
    cr_assert_eq(value->value_type, J_OBJ);
    cr_assert_not_null(value->value.obj);
    cr_assert_eq(((json_value_t *)
    L_TAG(value->value.obj, "mlv"))->value.number, 3);
    destroy_json_value(value);
}