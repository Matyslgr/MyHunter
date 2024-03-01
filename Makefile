##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_hunter
##

NAME	=	my_hunter

SRC	=	my_strcmp.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_getnbr.c	\
		my_hunter.c	\
		init.c	\
		destroy.c	\
		add_init.c	\
		bestscore.c	\
		my_strcpy.c	\
		set_elements.c	\
		set_elements2.c	\
		add_at_list.c	\
		add_at_list2.c	\
		add_at_list3.c	\
		add_at_list4.c	\
		add_at_list5.c	\
		event.c	\
		event2.c	\
		event3.c	\
		restart.c	\
		update.c	\
		set_rect.c	\
		set_rect2.c	\
		score.c	\
		background.c	\
		my_strlen.c	\
		my_strcat.c	\
		my_strdup.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

CPPFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window \
				-lcsfml-audio -lm

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
