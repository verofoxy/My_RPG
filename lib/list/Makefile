##
## EPITECH PROJECT, 2019
## Lib linked_list
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)
OBJ +=	../my/str_op/m_strcmp.o \
		../my/str_op/m_strdup.o \
		../my/str_op/m_strcpy.o \
		../my/str_op/m_strlen.o

NAME	=	liblist.a

all:	$(NAME)

LDFLAGS	=	-L../my/ -lmy

$(NAME):	$(OBJ)
	@cp list.h ../../include/
	@ar rc $(NAME) $(OBJ)

%.o:	%.c
	@gcc -o $@ -c $< $(LDFLAGS)

clean:
	@rm -f $(OBJ)
	@find . -name "*[#|~]" -delete  -o -name "[#]*" -delete

fclean:	clean
	@rm -f $(NAME)
auteur:
	echo $(USER) > auteur
