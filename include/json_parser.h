/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** json_parser.h
*/

#ifndef MUL_MY_RPG_2019_JSON_PARSER_H
#define MUL_MY_RPG_2019_JSON_PARSER_H



#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "list.h"

static const int INDEX_BUFFER_CAPACITY = 1000;
static const char TOKENS[] = "{}[],:\"0123456789ftn";
static const int J_ERROR_INT = -200000000;

#define J_GET_INT(x, y) json_object_get_int(x, y)
#define J_GET_STR(x, y) json_object_get_str(x, y)
#define J_GET_BOOL(x, y) json_object_get_bool(x, y)
#define J_GET_NULL(x, y) json_object_get_null(x, y)
#define J_GET_OBJ(x, y) json_object_get_object(x, y)
#define J_GET_ARRAY(x, y) json_object_get_array(x, y)

typedef enum json_enum_type
{
    J_OBJ,
    J_NUM,
    J_STR,
    J_ARRAY,
    J_BOOL,
    J_NULL
} json_type_e;

typedef enum token_type
{
    J_CURLY_BRACKET_L = 1,
    J_CURLY_BRACKET_R = 2,
    J_SQUARE_BRACKET_L = 3,
    J_SQUARE_BRACKET_R = 4,
    J_STRING_TOKEN = 5,
    J_NUMBER_TOKEN = 6,
    J_BOOL_TOKEN = 7,
    J_NULL_TOKEN = 8,
    J_COLON = 9,
    J_COMMA = 10
} token_type_e;

typedef struct link_type_tokens {
    char c;
    token_type_e type;
} link_type_t;

typedef struct data_buffer
{
    char const *str;
    unsigned int length;
} data_buffer_t;

typedef struct json_tokenizer
{
    data_buffer_t *buffer;
    unsigned int data_position;
    token_type_e token_type;
    unsigned int token_length;
} json_tokenizer_t;

typedef list_t json_object_t;

typedef struct json_array
{
    struct json_value **arr;
    int length;
    json_type_e type;
} json_array_t;

typedef struct json_value
{
    json_type_e value_type;
    union {
        int number;
        bool boolean;
        char string[255];
        json_object_t *obj;
        struct json_array array;
        void *nothing;
    } value;
} json_value_t;

typedef struct link_type_func {
    json_type_e type;
    void *(*func)(json_value_t *);
} link_func_t;

json_tokenizer_t init_tokenizer(data_buffer_t *buffer);
void skip_white_space(json_tokenizer_t *tokenizer);
int eat_comma(json_tokenizer_t *tokenizer);
int eat_colon(json_tokenizer_t *tokenizer);
void next_token(json_tokenizer_t *tokenizer);
bool has_more_tokens(json_tokenizer_t *tokenizer);
void parse_token(json_tokenizer_t *tokenizer, int *status);
void parse_string_token(json_tokenizer_t *tokenizer);
void parse_number_token(json_tokenizer_t *tokenizer);
void parse_valid_token(json_tokenizer_t *tokenizer, bool *got, char const *t);
char *get_key(json_tokenizer_t *tokenizer, char *key);

int json_parse(char const *str, json_value_t **obj);
json_value_t *json_parse_value(json_tokenizer_t *tokenizer, int *status);
json_value_t *create_json_value(json_type_e type);
void destroy_json_value(json_value_t *value);
void get_next_token(json_tokenizer_t *tokenizer, int *status);
json_object_t *get_json_object(json_value_t *v);
void *get_null_value(json_value_t *v);
json_array_t get_array_value(json_value_t *v);
int get_int_value(json_value_t *v);
bool get_bool_value(json_value_t *v);
char const *get_string_value(json_value_t *v);

json_value_t *parse_object(json_tokenizer_t *tokenizer, int *status);
json_value_t *parse_array(json_tokenizer_t *tokenizer, int *status);
json_value_t *parse_bool(json_tokenizer_t *tokenizer, int *status);
json_value_t *parse_null(json_tokenizer_t *tokenizer, int *status);
json_value_t *parse_number(json_tokenizer_t *tokenizer, int *status);
json_value_t *parse_string(json_tokenizer_t *tokenizer, int *status);

int json_object_get_int(json_object_t *obj, char const *tag);
bool json_object_get_bool(json_object_t *obj, char const *tag);
char const *json_object_get_str(json_object_t *obj, char const *tag);
json_object_t *json_object_get_object(json_object_t *obj, char const *tag);
void *json_object_get_null(json_object_t *obj, char const *tag);
json_array_t json_object_get_array(json_object_t *obj, char const *tag);

int json_array_get_int(json_array_t *array, int index);
char const *json_array_get_str(json_array_t *array, int index);
bool json_array_get_bool(json_array_t *array, int index);
json_object_t *json_array_get_object(json_array_t *array, int index);

json_value_t *get_json_from_file(char const *jsonpath, bool minified);

static const link_type_t LINK_TYPES[] = {
    {'{', J_CURLY_BRACKET_L},
    {'}', J_CURLY_BRACKET_R},
    {'[', J_SQUARE_BRACKET_L},
    {']', J_SQUARE_BRACKET_R},
    {',', J_COMMA},
    {':', J_COLON},
    {'"', J_STRING_TOKEN},
    {'0', J_NUMBER_TOKEN},
    {'1', J_NUMBER_TOKEN},
    {'2', J_NUMBER_TOKEN},
    {'3', J_NUMBER_TOKEN},
    {'4', J_NUMBER_TOKEN},
    {'5', J_NUMBER_TOKEN},
    {'6', J_NUMBER_TOKEN},
    {'7', J_NUMBER_TOKEN},
    {'8', J_NUMBER_TOKEN},
    {'9', J_NUMBER_TOKEN},
    {'f', J_BOOL_TOKEN},
    {'t', J_BOOL_TOKEN},
    {'n', J_NULL_TOKEN}
};
#endif
