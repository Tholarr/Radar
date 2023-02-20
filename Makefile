##
## EPITECH PROJECT, 2023
## B-MUL-100-NAN-1-1-myradar-thomas.cluseau
## File description:
## Makefile
##

SRC =	./main.c								\
		./lib.c									\
		./menu/init_menu.c						\
		./menu/menu.c							\
		./menu/options/play_options.c			\
		./menu/options/init_options.c			\
		./menu/options/set_weather.c			\
		./simulation/init_simulation.c			\
		./simulation/play_simulation.c			\
		./simulation/display_simulation.c		\
		./simulation/moves.c					\
		./simulation/collisions.c				\
		./simulation/countdown.c				\
		./simulation/read_script.c				\
		./simulation/get_script.c				\
		./end/end.c								\
		./end/init_end.c						\
		./destroy.c

OBJ =	$(SRC:.c=.o)

NAME =	my_radar

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC) -I ./include/ $(CSFML) -lm
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
