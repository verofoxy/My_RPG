##
## EPITECH PROJECT, 2019
## Lib my
## File description:
## Makefile
##

CC	=	gcc

DEBUG_FLAGS = -g3 -ggdb

CFLAGS	=	-W -Wall -Wextra -g
ifeq ($(DEBUG), yes)
	CFLAGS	:= $(CFLAGS) $(DEBUG_FLAGS)
endif
SHELL:=/bin/bash
CPPFLAGS	:=	-I./include
LFLAGS	+=	-L./lib/my -lmy	\
			-L./lib/list -llist \
			-lm \
			-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

SRC	:=	src/main.c 															\
		src/res/img/image.c 												\
		src/res/img/image_op.c 												\
		src/res/sound/sound.c 												\
		src/res/sound/sound_op.c 											\
		src/res/sound/sound_handle.c										\
		src/res/sound/sound_settings.c										\
		src/res/txt/label.c 												\
		src/res/txt/label_op.c 												\
		src/window/window.c 												\
		src/window/window_op.c												\
		src/animations/animation_settings.c 								\
		src/animations/animation_using.c									\
		src/particle/particle_effect.c										\
		src/particle/particle_op.c

SRC	+=	src/keyboard/keyboard_management.c 									\
		src/keyboard/interact_keyboard.c 									\
		src/keyboard/move_keyboard.c 										\
		src/quest/quest.c 													\
		src/quest/validation_quest.c 										\
		src/quest/draw_quests.c

SRC +=	src/environment/map/map.c											\
		src/environment/map/load_map.c										\
		src/environment/map/collisions.c 									\
		src/environment/camera/camera.c 									\
		src/environment/camera/apply_camera.c 								\
		src/environment/camera/update_camera.c 								\
		src/environment/map/trigger/init_trigger.c 							\
		src/environment/map/trigger/triggers.c 								\
		src/environment/map/trigger/check_trigger.c 						\
		src/environment/map/trigger/create_trigger.c

SRC +=	src/json/json_parser/json_parse.c 									\
		src/json/json_parser/json_parse_value.c 							\
		src/json/json_parser/parse_object.c									\
		src/json/json_parser/parse_string.c 								\
		src/json/json_parser/parse_number.c 								\
		src/json/json_parser/parse_array.c 									\
		src/json/json_parser/parse_null.c									\
		src/json/json_parser/parse_bool.c 									\
		src/json/json_tokenizer/constructor.c 								\
		src/json/json_tokenizer/eat.c 										\
		src/json/json_tokenizer/parse_token.c 								\
		src/json/json_tokenizer/next_token.c								\
		src/json/json_tokenizer/skip_white_space.c 							\
		src/json/json_tokenizer/parse_string_token.c 						\
		src/json/json_tokenizer/parse_number_token.c 						\
		src/json/json_tokenizer/parse_valid_token.c							\
		src/json/json_value/create_json_value.c 							\
		src/json/json_value/destroy_json_value.c 							\
		src/json/json_value/json_get_from_value.c 							\
		src/json/json_value/get_json_from_file.c 							\
		src/json/json_value/json_get_from_value_part_2.c					\
		src/json/json_value/json_get_from_object/json_object_get.c			\
		src/json/json_value/json_get_from_object/json_object_get_part_2.c	\
		src/json/json_value/json_get_from_array/json_array_get.c

SRC	+=	src/entity/entity.c 												\
		src/entity/get_entity_data.c 										\
		src/entity/get_entity_animation.c									\
		src/entity/handle_entity.c 											\
		src/entity/pnj/create_pnj.c 										\
		src/entity/pnj/pnj.c 												\
		src/entity/pnj/ia.c 												\
		src/entity/pnj/destroy_pnj.c 										\
		src/entity/player/create_player.c 									\
		src/entity/player/destroy_player.c 									\
		src/entity/player/player_moves.c 									\
		src/entity/player/player_animation.c 								\
		src/entity/enemy/create_enemy.c 									\
		src/entity/enemy/destroy_enemy.c			 						\
		src/entity/enemy/enemy_animation.c 									\
		src/entity/entity_management.c 										\
		src/entity/enemy/enemy.c 											\
		src/entity/player/player_combat.c			 						\
		src/entity/enemy/enemy_combat.c 									\
		src/entity/enemy/monster_spawn.c 									\
		src/entity/combat/entity_combat.c 									\
		src/items/create_items.c 											\
		src/entity/combat/run_boss_fight.c 									\
		src/items/get_object.c

SRC	+=	src/system/init_game.c 												\
		src/system/destroy_game.c		 									\
		src/system/scene.c 													\
		src/system/dialog.c

SRC +=	src/scenes/world_scene.c											\
		src/scenes/fight_scene/fight_scene.c								\
		src/scenes/fight_scene/create_destroy_fight.c 						\
		src/scenes/fight_scene/run_fight.c 									\
		src/scenes/fight_scene/attack_enemy_scene.c 						\
		src/scenes/fight_scene/fight_btns_callback.c 						\
		src/scenes/dialog_scene.c											\
		src/scenes/fade_scene.c												\
		src/scenes/transition.c												\
		src/scenes/item_scene.c												\
		src/scenes/menu_scene.c												\
		src/scenes/pause_scene.c											\
		src/scenes/settings_scene.c  										\
		src/scenes/how_to_play_scene.c 										\
		src/scenes/credits_scene.c 											\
		src/scenes/lose.c													\
		src/scenes/end_scene.c												\
		src/scenes/intro_scenes/intro_forest_scene.c						\
		src/scenes/intro_scenes/intro_cave_scene.c

SRC +=	src/menus/button.c 													\
		src/menus/menus.c													\
		src/menus/btn_callback.c											\
		src/menus/btn_callback_settings.c

OBJ	=	$(SRC:.c=.o)
OBJ_PATH	:=	./obj

NAME	=	my_rpg

LIBS	=	libs

all: $(NAME)

get_obj	=	$(OBJ_PATH)/$(notdir $(1))

$(NAME):	$(LIBS) $(OBJ)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) \
	$(foreach obj, $(OBJ), $(call get_obj,$(obj))) $(LFLAGS) && \
	echo -e "\e[1m\e[32m******** Compilation completed ********\033[0m" || \
	echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"
	@if [ -a $(NAME) ]; then echo -e "███╗   ███╗ ██╗   ██╗       ██████╗  ██████╗   ███████╗"; fi
	@if [ -a $(NAME) ]; then echo -e "████╗ ████║ ╚██╗ ██╔╝       ██╔══██╗ ██╔══██╗ ██╔═════╝"; fi
	@if [ -a $(NAME) ]; then echo -e "██╔████╔██║  ╚████╔╝        ██████╔╝ ██████╔╝ ██║   ███║"; fi
	@if [ -a $(NAME) ]; then echo -e "██║╚██╔╝██║   ╚██╔╝         ██╔══██╗ ██╔═══╝  ██║    ██║"; fi
	@if [ -a $(NAME) ]; then echo -e "██║ ╚═╝ ██║    ██║ ███████╗ ██║  ██║ ██║       ███████╔╝"; fi
	@if [ -a $(NAME) ]; then echo -e "╚═╝     ╚═╝    ╚═╝ ╚══════╝ ╚═╝  ╚═╝ ╚═╝       ╚══════╝  \033[0m"; fi

%.o:	%.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(LFLAGS) &&  \
	echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" && \
	mv $@ $(OBJ_PATH)/$(notdir $@) ||\
	echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

$(LIBS):
	@make -C lib/my
	@make -C lib/list

init:
	@touch .gitignore && \
	mkdir obj src lib include && \
	echo -e "\e[32m[OK] Project basics initialized" \
	"\033[0m\e[1m\e[32m\033[0m" || echo -e \
	"\e[31m[OK] Project basics already initialized \033[0m\e[1m\e[32m\033[0m"

tests_run: $(LIBS)
	make clean
	make -C tests/
	./unit_tests

clean:
	@rm -f $(foreach wrd, $(OBJ), $(call get_obj,$(wrd)))

clean_tests:
	-rm -f ./unit_tests
	find . -name "*.gcno" -delete -o -name "*.gcda" -delete
	make -C tests/ clean

fclean: clean clean_tests
	@make -C lib/my/ fclean
	@make -C lib/list fclean
	@rm -f $(NAME)

re: clean all

.PHONY	=	all my_rpg libs init clean fclean re
