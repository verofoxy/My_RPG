/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_bool_token_test.c
*/

#include "rpg.h"
#include <criterion/criterion.h>

Test(parse_valid_token, valid_false_token)
{
    char *str = "false";
    data_buffer_t buffer = {str, m_strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    bool got_token = true;

    parse_valid_token(&tokenizer, &got_token, "false");
    cr_assert_eq(got_token, true);
    cr_assert_eq(tokenizer.token_length, 5);
}

Test(parse_valid_token, invalid_false_token)
{
    char *str = "flse";
    data_buffer_t buffer = {str, m_strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    bool got_token = true;

    parse_valid_token(&tokenizer, &got_token, "false");
    cr_assert_eq(got_token, false);
    cr_assert_eq(tokenizer.token_length, 0);
}

Test(parse_valid_token, valid_true_token)
{
    char *str = "true";
    data_buffer_t buffer = {str, m_strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    bool got_token = true;

    parse_valid_token(&tokenizer, &got_token, "true");
    cr_assert_eq(got_token, true);
    cr_assert_eq(tokenizer.token_length, 4);
}

Test(parse_valid_token, invalid_true_token)
{
    char *str = "tue";
    data_buffer_t buffer = {str, m_strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    bool got_token = true;

    parse_valid_token(&tokenizer, &got_token, "true");
    cr_assert_eq(got_token, false);
    cr_assert_eq(tokenizer.token_length, 0);
}