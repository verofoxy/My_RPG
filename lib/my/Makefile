##
## EPITECH PROJECT, 2019
## Lib my
## File description:
## Makefile
##

CC	=	gcc

CPPFLAGS	=	-I./

SRC	:=	./char_op/is_upcase.c \
		./char_op/is_num.c \
		./char_op/is_alpha.c \
		./char_op/is_special_char.c \
		./char_op/is_lowcase.c \
		./char_op/is_printable.c \

SRC +=	./str_verif/m_str_isalpha.c \
		./str_verif/m_str_islower.c \
		./str_verif/m_str_isprintable.c \
		./str_verif/m_str_isnum.c \
		./str_verif/m_str_isupper.c \

SRC	+=	./str_op/m_strlen.c \
		./str_op/m_strncpy.c \
		./str_op/m_revstr.c \
		./str_op/m_memset.c \
		./str_op/m_strdup.c \
		./str_op/m_strcmp.c \
		./str_op/m_strcat.c \
		./str_op/m_strcpy.c \
		./str_op/m_str_split.c \
		./str_op/m_upcase.c \
		./str_op/m_lowcase.c \
		./str_op/m_strncmp.c \
		./str_op/m_memcpy.c \
		./str_op/m_getnbr.c \
		./str_op/m_strcat_dup.c \

SRC	+=	./str_printing/m_putstr.c \
		./str_printing/m_put_nbr.c \
		./str_printing/m_put_double.c \
		./str_printing/m_putchar.c \
		./str_printing/m_printf.c

SRC	+=	./get_next_line/get_next_line.c


SRC	+=	./int_op/m_itos.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	@cp my.h ../../include/
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean all
