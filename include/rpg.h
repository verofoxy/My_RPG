/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifndef MUL_MY_RPG_2019_RPG_H
#define MUL_MY_RPG_2019_RPG_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "list.h"
#include "json_parser.h"

#define EXEC_FAIL       84
#define EXEC_SUCCESS    0

#define CHECK_NULL(x) if (!x) return EXEC_FAIL;
#define CHECK_MALLOC(x) if (!x) return NULL;
#define CHECK_ERR(x) if (x == EXEC_FAIL) return EXEC_FAIL;
#define CHECK_FAIL(x) if (x == EXEC_FAIL) break;
#define CHECK_INVALID_PTR(x) if (!x) return NULL;
#define CHECK_CORRUPTED(x) if (x == EXEC_FAIL) return NULL;
#define CHECK_END(x) if (m_strlen(x) == 0) break;
#define CHECK_CANCEL(x) if (!(x)) return;
#define UNEXPECTED_EXIT(x) if (!(x)) { change_scene(sys, EXIT_SCENE); return; }

#define L_TAG(x, y) list_get_from_tag(x, y)
#define L_INDEX(x, y) list_get_from_index(x, y)

#endif