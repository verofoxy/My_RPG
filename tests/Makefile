##
## EPITECH PROJECT, 2019
## Lib my
## File description:
## Makefile
##

CC	=	gcc

CPPFLAGS	=	-I../include
CFLAGS		=	--coverage

SRC		:=	../src/json/json_parser/parse_bool.c \
			../src/json/json_parser/parse_string.c \
			../src/json/json_parser/parse_number.c \
			../src/json/json_parser/parse_null.c \
			../src/json/json_tokenizer/constructor.c \
			../src/json/json_tokenizer/skip_white_space.c \
			../src/json/json_tokenizer/eat.c \
			../src/json/json_tokenizer/parse_token.c \
			../src/json/json_tokenizer/next_token.c \
			../src/json/json_tokenizer/parse_valid_token.c \
			../src/json/json_tokenizer/parse_string_token.c \
			../src/json/json_tokenizer/parse_number_token.c \
			../src/json/json_value/create_json_value.c \
			../src/json/json_value/destroy_json_value.c \
			eat_test.c \
			parse_string_test.c \
			parse_null_test.c \
			parse_number_test.c \
			parse_bool_test.c \
			next_token_test.c \
			skip_white_space_test.c \
			parse_valid_token_test.c \
			parse_string_token_test.c \
			parse_null_token_test.c \
			parse_number_token_test.c

LFLAGS	=	-L../lib/my -lmy	\
			-L../lib/list -llist -lcriterion \
			-lm \
			-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

OBJ_PATH	:= ../obj
OBJ		=	$(SRC:.c=.o)

NAME	=	unit_tests

get_obj	=	$(OBJ_PATH)/$(notdir $(1))

all: $(NAME)

%.o:	%.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(LFLAGS) &&  \
	echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" && \
	mv $@ $(OBJ_PATH)/$(notdir $@)  || \
	echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) \
	$(foreach obj, $(OBJ), $(call get_obj,$(obj))) $(LFLAGS)
	mv $(NAME) ../

clean:
	rm -f $(foreach wrd, $(OBJ), $(call get_obj,$(wrd)))